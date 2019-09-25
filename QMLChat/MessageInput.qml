import QtQuick 2.0

TextInput {

    id: messageInput
    objectName: "messageInput"
    text: "Message"
    width: parent.width
    height: parent.height

    anchors.fill: parent
    verticalAlignment: Text.AlignVCenter
    anchors.leftMargin: 10
    wrapMode: TextInput.WrapAnywhere
    onAccepted: {
        MessageModel.addMyMessage(text)
        model.sendMessage(text)
    }


}
