#include "enhancedqmlapplicationengine.h"

EnhancedQmlApplicationEngine::EnhancedQmlApplicationEngine(QObject *parent)
  : QQmlApplicationEngine {parent}
{m_filemonitor = new FileMonitor("C:/Users/USER/source/QtRepos/newtestings",this);
  QObject::connect (m_filemonitor,&FileMonitor::reloadUI,this,&EnhancedQmlApplicationEngine::reloadUI);
}

void EnhancedQmlApplicationEngine::clearCache()
{
  this->clearComponentCache ();
}
