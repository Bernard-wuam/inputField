#ifndef ENHANCEDQMLAPPLICATIONENGINE_H
#define ENHANCEDQMLAPPLICATIONENGINE_H

#include <QObject>
#include <QQmlApplicationEngine>
#include "filemonitor.h"

class EnhancedQmlApplicationEngine : public QQmlApplicationEngine
{
    Q_OBJECT
  public:
    explicit EnhancedQmlApplicationEngine(QObject *parent = nullptr);

    Q_INVOKABLE void clearCache();

  signals:
    void reloadUI();


  private:
    FileMonitor* m_filemonitor;

};

#endif // ENHANCEDQMLAPPLICATIONENGINE_H