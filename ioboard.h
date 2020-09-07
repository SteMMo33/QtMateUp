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

    enum {
        ACK =    0x06,
        DLE =    0x10,
        NAK =    0x15,
        ETB =    0x17,
        REP =    0x5A
    };

    IoBoard(QObject* parent = nullptr);
    virtual ~IoBoard();

    Q_INVOKABLE int apriCassetto(int nCassetto);
    Q_INVOKABLE int leggiCassetto(int nCassetto);
    Q_INVOKABLE int setInternalTable(int nCassetti);


    int setType(ConnectionType type, QString serialName);


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
    QString _serialName;
    QSerialPort _serial;
    ConnectionType _type;
    QByteArray _response;
    int _waitTimeout = 5000;

    unsigned char crc( unsigned char* buffer, int size);
    int sendSerial( unsigned char* buffer, int size);
};


#endif // IOBOARD_H
