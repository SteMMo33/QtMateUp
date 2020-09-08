#ifndef PRENOTAZIONI_H
#define PRENOTAZIONI_H

#include <QObject>
#include <QDebug>

#include "sendemail.h"




class Prenotazione : public QObject
{
    Q_OBJECT
public:
    int value;
    bool isDepositato;
    bool isPrelevato;
    bool isScaduto;
};


class TipoPrenotazioneClass: public QObject
{
    Q_GADGET
private:
    explicit TipoPrenotazioneClass();
public:
    enum Value {
        TIPO_DEPOSITO,
        TIPO_RITIRO
    };
    Q_ENUM(Value)

};

typedef TipoPrenotazioneClass::Value    TipoPrenotazione;



/**
 * @brief The Prenotazioni class
 */
class Prenotazioni : public QObject
{
    Q_OBJECT

public:
    Prenotazioni();

    Q_INVOKABLE int checkCode(TipoPrenotazione tipo, QString code);
    Q_INVOKABLE int sendEmail();

private:
    // DataSource* ds;
};

#endif // PRENOTAZIONI_H
