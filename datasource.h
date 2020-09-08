#ifndef DATASOURCE_H
#define DATASOURCE_H

#include <QtSql/QSqlQuery>

#include "cassetti.h"
#include "prenotazioni.h"
#include "settings.h"



class DataSource : public QObject
{
    Q_OBJECT

public:
    DataSource();
    virtual ~DataSource();

    Cassetti* getCassetti();
    Prenotazioni* getPrenotazioni();
    MachineSettings* getSettings();

    Q_INVOKABLE Prenotazione* checkCode(TipoPrenotazione tipo, QString codice);

private:
    QSqlDatabase db;
    bool _open;
};


#endif // DATASOURCE_H
