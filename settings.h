#ifndef MACHINESETTINGS_H
#define MACHINESETTINGS_H

#include <QMap>
#include <QDebug>
// #include <QtSql/QSqlQuery>


class MachineSettings : public QObject, public QMap<QString, QString> // QObject
{
    Q_OBJECT

public:
    MachineSettings();

    //QString operator[](const QString &key){ return this[key]; };
    //void insert(QString &key, QString &value);
    //QString get(QString key){ return _settings[key]; };

private:
    // QMap<QString, QString> _settings;
};

#endif // MACHINESETTINGS_H
