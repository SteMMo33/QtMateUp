#ifndef DATASOURCE_H
#define DATASOURCE_H


#include "cassetti.h"
#include "prenotazioni.h"
#include "settings.h"

class DataSource
{
public:
    DataSource();
    virtual ~DataSource();

    Cassetti* getCassetti();
    Prenotazioni* getPrenotazioni();
    MachineSettings* getSettings();

private:
    QSqlDatabase db;
    bool _open;
};

#endif // DATASOURCE_H
