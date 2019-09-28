import QtQuick 2.0
import QtQuick.Controls 2.5


TextField {

    id: messageInput
    objectName: "messageInput"
    placeholderText: "Input Message"
    maximumLength:2000
    verticalAlignment: Text.AlignVCenter
    anchors.leftMargin: 10
    wrapMode: TextField.Wrap
    onAccepted: {
        MessageModel.addMyMessage(text)
        model.sendMessage(text)
        text = ""
    }


}
