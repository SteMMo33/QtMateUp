#include "prenotazioni.h"


Prenotazioni::Prenotazioni()
{
    qDebug() << "Cstruttore Prenotazioni";
}



int Prenotazioni::CheckCode(QString code)
{
    qDebug() << "check: " << code;
    return 1;
};
