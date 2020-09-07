#ifndef CASSETTI_H
#define CASSETTI_H

#include <QDebug>


class Cassetto
{
public:
    bool    isEmpty() { return _vuoto; };

    void setVuoto(){ _vuoto = true; };
    void setVuoto(bool bVuoto){ _vuoto = bVuoto; };
    void setPieno(){ _vuoto = false; };

private:
    bool _vuoto;
};



class Cassetti : public QList<Cassetto>
{

public:
    Cassetti();

    // int GetNumber() { return _number; };

private:
    //int _number;
    //QList<Cassetto> _cassetti;
};

#endif // CASSETTI_H
