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
    Prenotazioni();
    int CheckCode(QString code);
};

#endif // PRENOTAZIONI_H
