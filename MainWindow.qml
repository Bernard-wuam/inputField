import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.3
import QtGraphicalEffects 1.12

Rectangle{
    id:mainWindow
    color: "green"

    Rectangle{
        width: 250
        height: dl.height + 15
        anchors.centerIn: parent
        radius: 20
        clip: true
        FlickableTextField{
            id:dl
            anchors.left: parent.left
            anchors.top: parent.top
            //anchors.bottom: parent.bottom
            anchors.margins: 10


        }
    }
}
