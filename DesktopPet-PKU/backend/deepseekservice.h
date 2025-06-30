#ifndef DEEPSEEKSERVICE_H
#define DEEPSEEKSERVICE_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include<QJsonArray>
class DeepSeekService : public QObject {
    Q_OBJECT
public:
    explicit DeepSeekService(QObject *parent = nullptr);
    void sendMessage(const QString &message);
    void sendMessageWithHistory(const QList<QPair<QString, QString>> &history);
    void setApiKey(const QString &apiKey);
    QString getApiKey() const;
signals:
    void responseReceived(const QString &reply);
    void errorOccurred(const QString &error);

private slots:
    void onApiResponse(QNetworkReply *reply);

private:
    QNetworkAccessManager *manager;
    QString API_KEY = "sk-14b6dac102dd4c75a02fc29b4d69d503";  // 替换为你的API密钥
    const QString API_URL = "https://api.deepseek.com/chat/completions";
};
#endif // DEEPSEEKSERVICE_H
