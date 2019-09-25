import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12

Item {

    signal login()

    ColumnLayout {
        anchors.fill: parent

        TextField {
            Layout.alignment: Qt.AlignCenter
            id: name
            placeholderText: "userName"
        }
        TextField {
            Layout.alignment: Qt.AlignCenter
            id: localPort
            placeholderText: "loacl port"

        }
        TextField {
            Layout.alignment: Qt.AlignCenter
            id: serverPort
            placeholderText: "server port"

        }
        TextField {
            Layout.alignment: Qt.AlignCenter
            id: serverIp
            placeholderText: "server IP"

        }
        Button {
            Layout.alignment: Qt.AlignCenter
            text: "Connect"
            onClicked:{
                onClicked: model.setupConnection(name.text,localPort.text,serverPort.text,serverIp.text)
                login()
            }
        }
    }

}
