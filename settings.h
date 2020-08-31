#ifndef SETTINGS_H
#define SETTINGS_H

#include <QMap>


class Settings
{
public:
    Settings();
    QString operator[](const QString &key){ return _settings[key]; };

private:
    QMap<QString, QString> _settings;
};

#endif // SETTINGS_H
