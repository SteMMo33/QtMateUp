#include "prenotazioni.h"


Prenotazioni::Prenotazioni()
{
    qDebug() << "Costruttore Prenotazioni";
}



/**
 * @brief Prenotazioni::CheckCode
 * @param tipo
 * @param code
 * @return
 */
int Prenotazioni::CheckCode(TipoPrenotazione tipo, QString code)
{
    qDebug() << "[CheckCode] Tipo: " << tipo << " - Code:" << code;
    return 1;
};
