import QtQuick 2.0
import QtQuick.Controls 2.5

ListView {

    id: messageList
    objectName: "messageList"
    model: MessageModel


    spacing: 18
    clip: true

    delegate:Row{
        anchors.right: sendByMe ? parent.right : parent.left
        spacing: 6
        Label {
            id:messageText
            text: message
            color: sendByMe ? "black" : "white"
            wrapMode: Label.Wrap
            font.pixelSize: 14
            verticalAlignment: Text.AlignVCenter


            width: Math.min(messageText.implicitWidth,messageList.width)

            background: Rectangle {
                anchors.centerIn: parent.Center
                color: sendByMe ? "lightgrey" : "steelblue"
                height: messageText.implicitHeight + 7
                width: messageText.implicitWidth + 14

            }
        }
    }
    ScrollBar.vertical: ScrollBar {}

}
