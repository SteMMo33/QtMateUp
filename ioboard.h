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
    typedef enum connectionType {
        CONNECTION_WS,
        CONNECTION_SERIAL
    } ConnectionType;



    IoBoard(QObject* parent = nullptr);
    virtual ~IoBoard();

    Q_INVOKABLE int apriCassetto(int nCassetto);
    Q_INVOKABLE int leggiCassetto(int nCassetto);

    void setType(ConnectionType type) { _type = type;};
    int sendSerial(char* buffer, int size);

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
    ConnectionType _type;
};


#endif // IOBOARD_H
