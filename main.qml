import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.3


ApplicationWindow {
    id:root
    width:280
    height: 640
    visible: true

    title: qsTr("Hello World")

    function reload(){
        mainwindow.source = ""
        _EnhanceEngine.clearCache()
        mainwindow.source = "./MainWindow.qml"
    }

    Loader{
        id:mainwindow
        anchors.fill: parent
        source: "./MainWindow.qml"
        Connections{
            target: _EnhanceEngine
            function onReloadUI(){
                root.reload()
            }
        }
    }
}