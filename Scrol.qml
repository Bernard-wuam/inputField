import QtQuick 2.0

Rectangle{
    color:"black"
    width: 0.01 * parent.width
    radius: 0.5 * width
    anchors.right: parent.right
    anchors.margins:radius

   height: parent.height / (parent.height.contentHeight * parent.height)
//    y: parent.contentY/parent.contentHeight * parent.height
//    visible: parent.height < parent.contentHeight

   Component.onCompleted: console.log(lv.contentHeight)
}
