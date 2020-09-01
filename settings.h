#ifndef SETTINGS_H
#define SETTINGS_H

#include <QMap>
#include <QDebug>
#include <QtSql/QSqlQuery>


class Settings : public QObject
{
    Q_OBJECT

public:
    Settings();
    QString operator[](const QString &key){ return _settings[key]; };

private:
    QMap<QString, QString> _settings;
};

#endif // SETTINGS_H
