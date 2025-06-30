#ifndef QMARKDOWNTEXTDOCUMENT_H
#define QMARKDOWNTEXTDOCUMENT_H

#include <QObject>
#include <QTextDocument>

class QMarkdownTextDocument : public QObject
{
    Q_OBJECT
public:
    explicit QMarkdownTextDocument(QObject *parent = nullptr);
    void setMarkdown(const QString &markdown);
    QString toHtml() const;

private:
    QTextDocument *m_doc;
};

#endif // QMARKDOWNTEXTDOCUMENT_H
