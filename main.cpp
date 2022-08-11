#include <QGuiApplication>
 #include <QQmlApplicationEngine>
 #include <QQmlContext>
 #include "enhancedqmlapplicationengine.h"

 int main(int argc, char *argv[])
 {
 #if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
   QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
 #endif
  qputenv ("MAIN_QML", "../newtestings/main.qml");  QGuiApplication app(argc, argv);


  // QQmlApplicationEngine engine;
   EnhancedQmlApplicationEngine engine;  engine.addImportPath ("../newtestings/component_library");  engine.rootContext ()->setContextProperty ("_EnhanceEngine",&engine);
   const QUrl url(qgetenv("MAIN_QML"));
   QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                    &app, [url](QObject *obj, const QUrl &objUrl) {
     if (!obj && url == objUrl)
       QCoreApplication::exit(-1);
   }, Qt::QueuedConnection);
   engine.load(url);

   return app.exec();
 }