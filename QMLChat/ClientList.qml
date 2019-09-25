import QtQuick 2.0
import QtQuick.Controls 2.5


ListView {
    id: clientList
    objectName: "clientList"
    model: ClientModel

    spacing: 20

    delegate:Row{

        Rectangle {
            color: "lightblue"
            width: childrenRect.width + 10
            height: childrenRect.height+ 5

            Label {
                anchors.centerIn: parent
                text: name + ":"
                font.pixelSize: 30

            }

        }
        Rectangle {
            color: status === "online"? "lightgreen":"lightred"
            width: childrenRect.width + 10
            height: childrenRect.height + 5

            Label {
                anchors.centerIn: parent
                text: status
                font.pixelSize: 30

            }

        }
    }

}
