#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QQmlContext>

#include "settings.h"
#include "ioboard.h"
#include "cassetti.h"
#include "prenotazioni.h"
#include "datasource.h"



/**
 * @brief main
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);


    //
    IoBoard ioboard;
    ioboard.setType((IoBoard::CONNECTION_SERIAL));


    DataSource dataSource;
    Prenotazioni* prenotazioni = dataSource.getPrenotazioni();
    MachineSettings* settings = dataSource.getSettings();
    Cassetti* cassetti = dataSource.getCassetti();

    // Oggetti pubblicati verso QML
    // qmlRegisterType<Settings>("com.amtek.locker", 1, 0, "Settings");
    // qmlRegisterType<Prenotazioni>("com.amtek.locker", 1, 0, "Prenotazioni");
    // qmlRegisterType<IoBoard>("com.amtek.locker", 1, 0, "IoBoard"); Permette di istanziare da QML

    engine.rootContext()->setContextProperty( "ioBoard", &ioboard);
    engine.rootContext()->setContextProperty( "prenotazioni", prenotazioni);
    engine.rootContext()->setContextProperty( "mysettings", settings);

    qRegisterMetaType<TipoPrenotazione>("TipoPrenotazione");
    qmlRegisterUncreatableType<TipoPrenotazioneClass>("com.amtek.locker", 1, 0, "TipoPrenotazione", "Not creatable as it is an enum type");

    engine.load(url);

    qDebug() << "Platform: " << app.platformName();


    // Prova accesso 'settings'

    qDebug() << "Farmacia: " << settings->value("farmacia");
/*    qDebug() << "Cassetti: " << settings->get("numColumn");
    qDebug() << "email: " << settings->get("emailFarmacia");
    qDebug() << "serial: " << settings->get("serial_port");
*/
    qDebug() << settings->value("serial_port");

    // Cassetti
    qDebug() << "Cassetti da DB: " << cassetti->length();

    // Prenotazioni
    //prenotazioni.checkCode( TipoPrenotazione::TIPO_DEPOSITO, "99887766");
	
    return app.exec();
}

