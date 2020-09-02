#ifndef IOBOARD_H
#define IOBOARD_H

#include <QtCore/QObject>
#include <QtWebSockets>
#include <QtSerialPort/QSerialPortInfo>
#include <QtSerialPort/QSerialPort>


class IoBoard : public QObject
{
    Q_OBJECT

public:
    IoBoard(QObject* parent);
    virtual ~IoBoard();

    int OpenLock(int nLock);

private Q_SLOTS:
    void onConnected();
    void onDisconnected();
    void onDestroyed();
    void onStateChanged(QAbstractSocket::SocketState state);

    void onTextMessageReceived(QString message);
    void onBinMessageReceived(QByteArray message);
    void onError(QAbstractSocket::SocketError error);

private:
    QWebSocket _ws;
    QSerialPort _serial;
};


#endif // IOBOARD_H
