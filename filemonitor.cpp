#include "filemonitor.h"

FileMonitor::FileMonitor(QString fileName,QObject *parent)
: QObject{parent},directoryWatched{fileName}
{
getFileInDirectory(fileName);
filewatcher.addPaths(listOfFiles);
QObject::connect(&filewatcher, &QFileSystemWatcher::fileChanged,this, &FileMonitor::onFileChanged);
QObject::connect(&filewatcher, &QFileSystemWatcher::fileChanged,this, &FileMonitor::onDirectoryChanged);
QObject::connect(&filewatcher, &QFileSystemWatcher::fileChanged,this, &FileMonitor::reloadUI);
// m_timer.setInterval (150);
// m_timer.setSingleShot (true);
//QObject::connect(&m_timer,&QTimer::timeout, this, &FileMonitor::reloadUI);
}



void FileMonitor::onFileChanged(const QString& file_)
{
QFileInfo check(file_);
while(!check.exists ()){
 std::this_thread::sleep_for(std::chrono::milliseconds(10));
 filewatcher.addPath (file_);
 //m_timer.start ();
}
qInfo() << file_;
}

void FileMonitor::onDirectoryChanged(const QString & file)
{
Q_UNUSED (file);
filewatcher.removePaths (filewatcher.files ());
listOfFiles.clear ();
getFileInDirectory (directoryWatched);
filewatcher.addPaths (listOfFiles);

}

void FileMonitor::getFileInDirectory(const QString& file_){

QDir directory(file_);

if(directory.exists ()){
 QStringList c = directory.entryList( QStringList() << "*.qml");
           if(c.count () > 0){

           for(const auto& m: qAsConst(c)){
           listOfFiles << directory.absoluteFilePath (m);
  }
  }
           auto listOfDirectory = directory.entryList( QStringList() << "*",QDir::Dirs | QDir::NoDotAndDotDot | QDir::NoSymLinks);
    for(const auto& d: qAsConst(listOfDirectory)){
      getFileInDirectory(directory.absoluteFilePath(d));

    }

  }
  else{
    qDebug() << "directory not valid....";
  }

}