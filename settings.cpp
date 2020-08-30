
#include <QDebug>
#include <QtSql/QSqlQuery>


#include "settings.h"

/**
 * @brief Settings::Settings
 * Costruttore che carica il contenuto della tabella 'settings'
 */
Settings::Settings()
{
    qDebug() << "Costruttore Settings";

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("bigblue");
        db.setDatabaseName("flightdb");
        db.setUserName("root");
        db.setPassword("amtek");
        bool ok = db.open();

    QSqlQuery query("select * from settings;");
    while (query.next()) {
        QString country = query.value(0).toString();
            // doSomething(country);
        qDebug()<< query.value("name") << " -> " << query.value("value");
    }
    db.close();
}
