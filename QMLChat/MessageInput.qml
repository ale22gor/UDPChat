import QtQuick 2.0

TextInput {

        id: messageInput
        objectName: "messageInput"

        text: "Message"
        anchors.leftMargin: 2
        verticalAlignment: Qt.AlignVCenter
        horizontalAlignment: Qt.AlignLeft

        onAccepted: {
                MessageModel.addMessage(text)
                model.sendMessage(text)
        }


}
