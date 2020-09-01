#ifndef PRENOTAZIONI_H
#define PRENOTAZIONI_H

#include <QObject>
#include <QDebug>



class Prenotazione
{
public:
    int value;
    bool isDepositato;
    bool isPrelevato;
    bool isScaduto;
};



class Prenotazioni
{
public:
    typedef enum _tipo {
        TIPO_DEPOSITO,
        TIPO_RITIRO
    } TipoPrenotazione;


public:
    Prenotazioni();
    int CheckCode(TipoPrenotazione tipo, QString code);

};

#endif // PRENOTAZIONI_H
