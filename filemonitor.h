#ifndef FILEMONITORING_H
    #define FILEMONITORING_H

    #include <QObject>
    #include <QDebug>
    #include <QDir>
    #include <QFileSystemWatcher>
    #include <thread>
    #include <QTimer>

    class FileMonitor : public QObject
    {
        Q_OBJECT
      public:
        FileMonitor(QString, QObject *parent = nullptr);

      signals:
        void reloadUI();

      public slots:
        void onFileChanged(const QString&);
        void onDirectoryChanged(const QString&);

      private:
        void getFileInDirectory(const QString&);
        QStringList listOfFiles;
        QFileSystemWatcher filewatcher;
        QTimer m_timer;
        QString directoryWatched;

    };

    #endif // FILEMONITORING_H