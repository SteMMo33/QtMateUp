#ifndef CASSETTI_H
#define CASSETTI_H

#include <QDebug>
#include <QtSql/QSqlQuery>



class Cassetto
{
public:
    bool    isEmpty;
};



class Cassetti
{

public:
    Cassetti();
    int GetNumber() { return _number; };

private:
    int _number;
    QList<Cassetto> _cassetti;
};

#endif // CASSETTI_H
