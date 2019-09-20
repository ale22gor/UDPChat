import QtQuick 2.0

ListView {
    id: clientList
    objectName: "clientList"

    model: ClientModel
    delegate:Text { text: name+":"+status }

}
