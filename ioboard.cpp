/*!
    @author SM

    @abstract
  Protocollo per la porta seriale Protocollo PC - scheda CPU Locker 80 vers. 1.00.doc

!*/

#include "ioboard.h"


#define SERIALE


/**
 * @brief IoBoard::IoBoard
 * Costruttore oggetto IoBoard che comunica via websocket
 */
//! [constructor]
IoBoard::IoBoard(QObject* parent) : QObject(parent), _type(CONNECTION_SERIAL)
{
    qDebug() << "Costruttore IoBoard" << this;

    if (_type == CONNECTION_WS) {

        // -- Collegamento con websocket

        QObject::connect( &_ws, &QWebSocket::connected, this, &IoBoard::onConnected);
        QObject::connect( &_ws, &QWebSocket::disconnected, this, &IoBoard::onDisconnected);
        QObject::connect( &_ws, &QWebSocket::destroyed, this, &IoBoard::onDestroyed);
        QObject::connect( &_ws, &QWebSocket::stateChanged, this, &IoBoard::onStateChanged);

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

    }
    else {

        // -- Collegamento con la porta seriale
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
        // char cmd[] = { 0x00, 0x00, 0x7F };
        // char fwCmd[] = { 0x02, 0x00, 0x7D };
        // char cmdLista01[] = { 0x3B, 0x04, 0x00, 0x00, 0x00, 0x01, 0x41};
        // char cmdLista02[] = { 0x3B, 0x04, 0x00, 0x00, 0x00, 0x02, 0x42};
        char cmd[] = { 0x03, 0x01, 0x01, 0x7C };

        _serial.write(cmd);

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
    }

    } // if SERIAL
}
//! [constructor]



IoBoard::~IoBoard()
{
    qDebug() << "[IoBoard] Des'ctor" << this;

    if (_type == CONNECTION_WS)
        _ws.close();
    else
        _serial.close();
};


/**
 * @brief IoBoard::onConnected
 */
//! [onConnected]
void IoBoard::onConnected()
{
    qDebug() << "[IoBoard] WebSocket connected";

    QObject::connect( &_ws, &QWebSocket::textMessageReceived, this, &IoBoard::onTextMessageReceived);
    QObject::connect( &_ws, &QWebSocket::binaryMessageReceived, this, &IoBoard::onBinMessageReceived);

    // _ws.sendTextMessage(QStringLiteral("{ \"LetturaCassetto\": 1}"));
    _ws.sendTextMessage(QStringLiteral("startKiosk"));
}
//! [onConnected]


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


/**
 * @brief IoBoard::onDestroyed
 */
void IoBoard::onDestroyed()
{
    qDebug() << "[IoBoard] Destroyed";
};


void IoBoard::onStateChanged(QAbstractSocket::SocketState state)
{
    qDebug() << "[IoBoard] StateChanged:" << state;
};



unsigned char IoBoard::crc( unsigned char* buffer, int size)
{
    unsigned char crc = 0x7F;
    int i = 0;
    while(i<size)   crc ^= buffer[i++];
    return crc;
}


/**
 * @brief IoBoard::apriCassetto
 * @param nCassetto
 * @return
 */
int IoBoard::apriCassetto(int nCassetto)
{
    qDebug() << "[IoBoard] apriCassetto:" << nCassetto;

    if (_type==CONNECTION_WS){
        _ws.sendTextMessage(QString("{\"AperCassetto\":%1}").arg(nCassetto));
    }
    else {
        unsigned char cmd[] = { 0x3B, 0x04, 0x00, 0x00, 0x00, 0x02, 0x42 };
        cmd[6] = crc( cmd, 6);
        int ret = sendSerial(cmd, 7);
        if (ret){
            if (_response.at(0)==ACK)
                qDebug() << "[] Apertura OK";
        }
    }
    return 1;
};



/**
 * @brief IoBoard::leggiCassetto
 * @param nCassetto
 * @return
 */
int IoBoard::leggiCassetto(int nCassetto)
{
    qDebug() << "[IoBoard] leggiCassetto:" << nCassetto;

    if (_type==CONNECTION_WS){
        qDebug() << "ToDo";
    }
    else {
        unsigned char cmd[] = { 0x3C, 0x01, 0xFF, 0xFF };
        cmd[2] = (char)nCassetto;
        cmd[3] = crc( cmd, 3);
        int ret = sendSerial(cmd, 4);
        if (ret > 0){
            if (_response.at(1)==0x3C){   // Controlla che sia una sua risposta
                // Decodifica risposta
                qDebug() << "[] index:" << QChar(_response.at(3)) << " - " << (_response.at(4) ? "aperto" : "chiuso");
            }
        }
        else {
            qDebug() << "[IoBoard] Errore comando: " << ret;
        }
    }
    return 1;
};



/**
 * @brief IoBoard::sendSerial
 * @param buffer
 * @param size
 * @return
 */
int IoBoard::sendSerial(unsigned char* buffer, int size)
{
    int waitTimeout = 5000;

    qDebug() << "TX:" << QByteArray((char*)buffer).toHex() << this;
    _serial.write((char*)buffer, size);

    if (_serial.waitForBytesWritten(waitTimeout)) {
        // qDebug() << "[] Sent.." << this;
        // read response
        if (_serial.waitForReadyRead(waitTimeout*3)) {
            _response = _serial.readAll();
            while (_serial.waitForReadyRead(10))
                _response += _serial.readAll();
            qDebug() << "[] Read:" << _response.toHex();
        }
        else {
            qDebug() << "[] TO Read";
            return -1;
        }
    }
    else {
        qDebug() << "[] TO Write";
        return -2;
    }
    //
    // Controllo risposta
    if (_response.at(0)==REP)
        return _response.length();
    else if (_response.at(0)==DLE){
        qDebug() << "[] DLE";
    }
    else if (_response.at(0)==ETB){
        qDebug() << "[] ETB";
    }
    return -4;
}
