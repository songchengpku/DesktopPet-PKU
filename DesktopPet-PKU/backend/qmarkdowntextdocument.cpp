#include "qmarkdowntextdocument.h"

#include <QTextFrame>
#include <QRegularExpression>

QMarkdownTextDocument::QMarkdownTextDocument(QObject *parent) : QObject(parent)
{
    m_doc = new QTextDocument(this);
}

void QMarkdownTextDocument::setMarkdown(const QString &markdown)
{
    // We will build an HTML string directly, it's simpler and more robust for this case.
    QString html;
    QStringList lines = markdown.split('\n');
    bool inList = false;

    for (const QString& line : lines) {
        QString trimmedLine = line.trimmed();

        // If a line is not a list item, and we were in a list, close the list tag.
        if (!trimmedLine.startsWith("- ") && inList) {
            html += "</ul>";
            inList = false;
        }

        if (trimmedLine.startsWith("### ")) {
            html += QString("<h3>%1</h3>").arg(trimmedLine.mid(4).toHtmlEscaped());
        } else if (trimmedLine.startsWith("## ")) {
            html += QString("<h2>%1</h2>").arg(trimmedLine.mid(3).toHtmlEscaped());
        } else if (trimmedLine.startsWith("# ")) {
            html += QString("<h1>%1</h1>").arg(trimmedLine.mid(2).toHtmlEscaped());
        } else if (trimmedLine.startsWith("- ")) {
            if (!inList) {
                html += "<ul>";
                inList = true;
            }
            html += QString("<li>%1</li>").arg(trimmedLine.mid(2).toHtmlEscaped());
        } else if (trimmedLine.isEmpty()) {
            html += "<br>";
        }
        else {
            QString processedLine = line;
            // Use QRegularExpression for robust replacement
            processedLine.replace(QRegularExpression("\\*\\*(.*?)\\*\\*"), "<b>\\1</b>");
            processedLine.replace(QRegularExpression("\\*(.*?)\\*"), "<i>\\1</i>");
            processedLine.replace(QRegularExpression("`(.*?)`"), "<code>\\1</code>");
            html += processedLine + "<br>";
        }
    }

    if (inList) { // Close any open list at the end
        html += "</ul>";
    }

    m_doc->setHtml(html);
}


QString QMarkdownTextDocument::toHtml() const
{
    return m_doc->toHtml();
}
