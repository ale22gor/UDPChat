import QtQuick 2.0
import QtQuick.Controls 2.5

ListView {

    id: messageList
    objectName: "messageList"
    model: MessageModel

    verticalLayoutDirection: ListView.BottomToTop
    spacing: 12


    delegate:Row{
        anchors.right: sendByMe ? parent.right : parent.left
        spacing: 6

        Rectangle {

            color: sendByMe ? "lightgrey" : "steelblue"
            width: childrenRect.width + 20
            height: childrenRect.height + 20

            Label {
                anchors.centerIn: parent
                text: message
                color: sendByMe ? "black" : "white"
            }
        }
    }
    ScrollBar.vertical: ScrollBar {}

}
