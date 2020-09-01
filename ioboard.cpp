#include "ioboard.h"



/**
 * @brief IoBoard::IoBoard
 * Costruttore oggetto IoBoard che comunica via websocket
 */
IoBoard::IoBoard(QObject* parent) : QObject(parent)
{
    qDebug() << "Costruttore IoBoard";

    // -- Prova con websocket

    QObject::connect( &_ws, &QWebSocket::connected, this, &IoBoard::onConnected);
    QObject::connect( &_ws, &QWebSocket::disconnected, this, &IoBoard::onDisconnected);

    connect( &_ws, QOverload<QAbstractSocket::SocketError>::of(&QWebSocket::error),
        [=](QAbstractSocket::SocketError error){
            qDebug() << "[IoBoard] Errore: " << error;
        }
    );

    QUrl url ("ws://localhost:7681");
    url.setHost("10.191.40.216");
    qDebug() << "[IoBoard] url: " << url.toString() << " - Scheme: " << url.scheme() << " - Host: " << url.host() << " - Port: " << url.port();
    qDebug() << "[IoBoard] state:" << _ws.state();
    _ws.open(url);
    qDebug() << "[IoBoard] state:" << _ws.state();

    // -- Prova con la porta seriale
#ifdef SERIALE
    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos)
        qDebug() << info.portName();

    QString portName = "ttyS1";
    int waitTimeout = 5000;

    qDebug() << "[IoBoard] Serial:" << portName;
    _serial.setPortName(portName);
    if (!_serial.open(QIODevice::ReadWrite)) {
        qDebug() << tr("!! Can't open %1, error code %2").arg(portName).arg(_serial.error());
    }
    else {

        _serial.setBaudRate(9600);
        _serial.setDataBits(QSerialPort::Data8);
        _serial.setFlowControl(QSerialPort::NoFlowControl);
        _serial.setParity(QSerialPort::NoParity);
        _serial.setStopBits(QSerialPort::OneStop);

        qDebug() << "[] SendCmd";
        char cmd[] = { 0x00, 0x00, 0x7F };
        char fwCmd[] = { 0x02, 0x00, 0x7D };

        int n = _serial.write(cmd);

        if (_serial.waitForBytesWritten(waitTimeout)) {
            qDebug() << "[] Sent..";
            // read response
            if (_serial.waitForReadyRead(waitTimeout*3)) {
                QByteArray responseData = _serial.readAll();
                while (_serial.waitForReadyRead(10))
                    responseData += _serial.readAll();
                qDebug() << "[] Read:" << responseData;
            }
            else {
                qDebug() << "[] TO Read";
            }
        }
        else {
            qDebug() << "[] TO Write";
        }
        _serial.close();
    }
#endif
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
 * @brief IoBoard::onDisconnected
 */
void IoBoard::onDisconnected()
{
    qDebug() << "[IoBoard] WebSocket disconnected";
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



/**
 * @brief IoBoard::onBinMessageReceived
 * @param message
 */
void IoBoard::onBinMessageReceived(QByteArray message)
{
    qDebug() << "[IoBoard] Binary message: " << message;
};


/**
 * @brief IoBoard::onError
 * @param error
 */
void IoBoard::onError(QAbstractSocket::SocketError error)
{
    qDebug() << "[IoBoard] Error: " << error;
};

