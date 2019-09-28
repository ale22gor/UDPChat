import QtQuick 2.0
import QtQuick.Controls 2.5


ListView {
    id: clientList
    objectName: "clientList"
    model: ClientModel
    spacing: 20
    delegate:Row{

        Rectangle {
            color: status === "online"? "lightgreen":"lightred"
            width: clientText.width+10
            height: clientText.height + 5

            Label {
                id:clientText
                anchors.centerIn: parent
                text: name + ":" + status
                font.pixelSize: 30

            }

        }
    }

}
