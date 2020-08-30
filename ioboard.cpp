#include "ioboard.h"



/**
 * @brief IoBoard::IoBoard
 * Costruttore oggetto IoBoard che comunica via websocket
 */
IoBoard::IoBoard()
{
    qDebug() << "Costruttore IoBoard";

    QObject::connect( &m_ws, &QWebSocket::connected, this, &IoBoard::onConnected);
    m_ws.open(QUrl("localhost"));
}


/**
 * @brief IoBoard::onConnected
 */
void IoBoard::onConnected()
{
    qDebug() << "WebSocket connected";
    QObject::connect( &m_ws, &QWebSocket::textMessageReceived, this, &IoBoard::onTextMessageReceived);
    m_ws.sendTextMessage(QStringLiteral("Hello, world!"));
}


/**
 * @brief IoBoard::onTextMessageReceived
 * @param message
 */
void IoBoard::onTextMessageReceived(QString message)
 {
    qDebug() << "Message received:" << message;
     m_ws.close();
 }
