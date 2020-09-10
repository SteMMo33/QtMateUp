#ifndef DATASOURCE_H
#define DATASOURCE_H

#include <QtSql/QSqlQuery>

#include "cassetti.h"
#include "prenotazioni.h"
#include "settings.h"



class DataSource : public QObject
{
    Q_OBJECT

    // Q_PROPERTY(Prenotazione prenotazione READ getPrenotazione WRITE setCounter NOTIFY counterChanged);
    // Q_PROPERTY(Prenotazione prenotazione READ getPrenotazione NOTIFY checkResultReady);

public:
    DataSource();
    virtual ~DataSource();

    Cassetti* getCassetti();
    Prenotazioni* getPrenotazioni();
    MachineSettings* getSettings();

    Q_INVOKABLE Prenotazione* checkCode(TipoPrenotazione tipo, QString codice);


    // Prenotazione getPrenotazione() { return prenotazioneEsito; };

signals:
    void checkResultReady();

private:
    QSqlDatabase db;
    bool _open;

    Prenotazione prenotazioneEsito;
};


#endif // DATASOURCE_H
