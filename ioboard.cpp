#include "ioboard.h"



/**
 * @brief IoBoard::IoBoard
 * Costruttore oggetto IoBoard che comunica via websocket
 */
IoBoard::IoBoard(QObject* parent) : QObject(parent)
{
    qDebug() << "Costruttore IoBoard";

    QObject::connect( &_ws, &QWebSocket::connected, this, &IoBoard::onConnected);

    connect( &_ws, QOverload<QAbstractSocket::SocketError>::of(&QWebSocket::error),
        [=](QAbstractSocket::SocketError error){
            qDebug() << "[IoBoard] Errore: " << error;
        }
    );

    QUrl url ("ws://localhost:7681");
    qDebug() << "[IoBoard] url: " << url.toString() << " - Host: " << url.host() << " - Port: " << url.port();
    _ws.open(url);
}


/**
 * @brief IoBoard::onConnected
 */
void IoBoard::onConnected()
{
    qDebug() << "[IoBoard] WebSocket connected";
    QObject::connect( &_ws, &QWebSocket::textMessageReceived, this, &IoBoard::onTextMessageReceived);
    QObject::connect( &_ws, &QWebSocket::binaryMessageReceived, this, &IoBoard::onBinMessageReceived);

    // _ws.sendTextMessage(QStringLiteral("Hello, world!"));

    char cmd[] = { 0x00, 0x00, 0x7F};
    QByteArray fwCmd(cmd);
    _ws.sendBinaryMessage(fwCmd);
}


/**
 * @brief IoBoard::onTextMessageReceived
 * @param message
 */
void IoBoard::onTextMessageReceived(QString message)
 {
    qDebug() << "[IoBoard] Message received:" << message;
    _ws.close();
 }


void IoBoard::onBinMessageReceived(QByteArray message)
{
    qDebug() << "[IoBoard] Binary message: " << message;
};


void IoBoard::onError(QAbstractSocket::SocketError error)
{
    qDebug() << "[IoBoard] Error: " << error;
};
