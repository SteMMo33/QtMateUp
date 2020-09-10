#ifndef PRENOTAZIONI_H
#define PRENOTAZIONI_H

#include <QObject>
#include <QDebug>

#include "sendemail.h"




class Prenotazione : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int cassetto MEMBER _cassetto READ cassetto)
    Q_PROPERTY(float importo MEMBER _importo READ importo)

public:
    int _id;
    int _value;
    bool _isDepositata;
    bool _isRitirata;
    bool _isScaduta;
    float _importo;
    int _cassetto;


    Prenotazione() = default;
    ~Prenotazione() = default;

    Q_INVOKABLE int getCassetto() { return this->_cassetto; };
    Q_INVOKABLE float getImporto() { return this->_importo; };

    friend QDebug operator<<(QDebug dbg, Prenotazione const& prenotazione){
        qDebug() << prenotazione._id;
        qDebug() << prenotazione._cassetto;
        qDebug() << prenotazione._isDepositata;
        qDebug() << prenotazione._isRitirata;
        return dbg;
    };

    friend QDebug operator<<(QDebug dbg, Prenotazione* prenotazione){
        qDebug() << "Prenotazione:";
        qDebug() << "! id: " << prenotazione->_id;
        qDebug() << "! cassetto: " << prenotazione->_cassetto;
        qDebug() << "! importo: " << prenotazione->_importo;
        qDebug() << "! depositata: " << prenotazione->_isDepositata;
        qDebug() << "! ritirata: " << prenotazione->_isRitirata;
        return dbg;
    };

    int cassetto() { return _cassetto; };
    float importo() { return _importo; };

private:
    //int cassetto;
};



/**
 * @brief The TipoPrenotazioneClass class
 * Classe che racchiude un enum
 */
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
