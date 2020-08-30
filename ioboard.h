#ifndef IOBOARD_H
#define IOBOARD_H

#include <QtCore/QObject>
#include <QtWebSockets>


class IoBoard
{
public:
    IoBoard();

private Q_SLOTS:
      void onConnected();
      void onTextMessageReceived(QString message);

private:
    QWebSocket m_ws;
};

#endif // IOBOARD_H
