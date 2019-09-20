import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12

Item {

    signal login(string name, int localPort, int serverPort, string serverIp)

    ColumnLayout {
        anchors.fill: parent

        TextField {
            Layout.alignment: Qt.AlignCenter
            id: name
        }
        TextField {
            Layout.alignment: Qt.AlignCenter
            id: localPort
        }
        TextField {
            Layout.alignment: Qt.AlignCenter
            id: serverPort
        }
        TextField {
            Layout.alignment: Qt.AlignCenter
            id: serverIp
        }
        Button {
            Layout.alignment: Qt.AlignCenter
            text: "Connect"
            onClicked: login(name.text, localPort.text, serverPort.text, serverIp.text)
        }
    }

}
