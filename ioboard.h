#ifndef IOBOARD_H
#define IOBOARD_H

#include <QtCore/QObject>
#include <QtWebSockets>


class IoBoard : public QObject
{
    Q_OBJECT

public:
    IoBoard(QObject* parent);

private Q_SLOTS:
    void onConnected();
    void onTextMessageReceived(QString message);
    void onBinMessageReceived(QByteArray message);
    void onError(QAbstractSocket::SocketError error);

private:
    QWebSocket _ws;
};


#endif // IOBOARD_H
