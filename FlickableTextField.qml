import QtQuick 2.0
import QtQuick.Controls 2.5

Flickable {
     id: flick

     width: 100;
     height: Math.min(50,edit.contentHeight)
     contentWidth: edit.paintedWidth
     contentHeight: edit.paintedHeight
     clip: true

     ScrollBar.vertical:ScrollBar{
         policy:ScrollBar.AsNeeded

     }

     function ensureVisible(r)
     {
         if (contentX >= r.x)
             contentX = r.x;
         else if (contentX+width <= r.x+r.width)
             contentX = r.x+r.width-width;
         if (contentY >= r.y)
             contentY = r.y;
         else if (contentY+height <= r.y+r.height)
             contentY = r.y+r.height-height;
     }

     TextEdit {
         id: edit
         width: flick.width
         focus: true
         wrapMode: TextEdit.Wrap
         onCursorRectangleChanged: flick.ensureVisible(cursorRectangle)
     }
 }