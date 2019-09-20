import QtQuick 2.0

ListView {

    id: messageList
    objectName: "messageList"

    model: MessageModel
    delegate:Text { text: display }

}
