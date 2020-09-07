#ifndef IOBOARD_H
#define IOBOARD_H

#include <QtCore/QObject>
#include <QtWebSockets>
#include <QtSerialPort/QSerialPortInfo>
#include <QtSerialPort/QSerialPort>


class IoBoard : public QObject
{
    Q_OBJECT
    // Q_PROPERTY(QString var READ getVar WRITE setVar NOTIFY varChanged)

public:
    typedef enum connectionType {
        CONNECTION_WS,
        CONNECTION_SERIAL
    } ConnectionType;

#define ACK     0x06
#define DLE     0x10
#define NACK    0x15
#define ETB     0x17
#define REP     0x5A

    IoBoard(QObject* parent = nullptr);
    virtual ~IoBoard();

    Q_INVOKABLE int apriCassetto(int nCassetto);
    Q_INVOKABLE int leggiCassetto(int nCassetto);

    void setType(ConnectionType type) { _type = type;};
    int sendSerial( unsigned char* buffer, int size);

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
    QByteArray _response;

    unsigned char crc( unsigned char* buffer, int size);
};


#endif // IOBOARD_H
