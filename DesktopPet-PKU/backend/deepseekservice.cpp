#include "deepseekservice.h"

DeepSeekService::DeepSeekService(QObject *parent) : QObject(parent) {
    manager = new QNetworkAccessManager(this);
}

void DeepSeekService::sendMessage(const QString &message) {
    QNetworkRequest request;
    request.setUrl(QUrl(API_URL));
    request.setRawHeader("Authorization", ("Bearer " + API_KEY).toUtf8());
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    // 构造请求JSON（根据DeepSeek API文档调整参数）
    QJsonObject body;
    body["model"] = "deepseek-chat";  // 选择合适的模型
    body["temperature"] = 0.7;

    QJsonArray messages;
    QJsonObject msgObj;
    msgObj["role"] = "user";
    msgObj["content"] = message;
    messages.append(msgObj);
    body["messages"] = messages;

    QNetworkReply *reply = manager->post(request, QJsonDocument(body).toJson());
    connect(reply, &QNetworkReply::finished, this, [=]() { onApiResponse(reply); });
}

void DeepSeekService::onApiResponse(QNetworkReply *reply) {
    if (reply->error() != QNetworkReply::NoError) {
        emit errorOccurred(reply->errorString());
        reply->deleteLater();
        return;
    }

    QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
    QJsonObject json = doc.object();

    //解析错误响应
    if (json.contains("error")) {
        emit errorOccurred(json["error"].toObject()["message"].toString());
    }

    // 解析响应数据（根据API返回结构调整）
    if (json.contains("choices")) {
        QJsonArray choices = json["choices"].toArray();
        if (!choices.isEmpty()) {
            QJsonObject choice = choices[0].toObject();
            QJsonObject message = choice["message"].toObject();
            emit responseReceived(message["content"].toString());
        }
    } else {
        emit errorOccurred("Invalid response format");
    }

    reply->deleteLater();
}
void DeepSeekService::sendMessageWithHistory(const QList<QPair<QString, QString>> &history)
{
    QNetworkRequest request;
    request.setUrl(QUrl(API_URL));
    request.setRawHeader("Authorization", ("Bearer " + API_KEY).toUtf8());
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    // 构造带上下文的请求
    QJsonObject body;
    body["model"] = "deepseek-chat";
    body["temperature"] = 0.7;
    body["max_tokens"] = 4096;

    QJsonArray messages;
    for (const auto &pair : history) {
        QJsonObject msgObj;
        msgObj["role"] = pair.first;
        msgObj["content"] = pair.second;
        messages.append(msgObj);
    }
    body["messages"] = messages;

    QNetworkReply *reply = manager->post(request, QJsonDocument(body).toJson());
    connect(reply, &QNetworkReply::finished, this, [=]() { onApiResponse(reply); });
}

void DeepSeekService::setApiKey(const QString &apiKey)
{
    API_KEY = apiKey;
}

QString DeepSeekService::getApiKey() const
{
    return API_KEY;
}
