import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12


Dialog {
    visible: true
    width: parent.width
    height:  parent.height

    ColumnLayout {
        anchors.fill: parent

        TextField {
            Layout.alignment: Qt.AlignCenter
            Layout.fillWidth: true
            Layout.fillHeight: true
            id: name
            maximumLength:12
            placeholderText: "userName"
        }
        TextField {
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.alignment: Qt.AlignCenter
            id: localPort
            validator: IntValidator {bottom: 0; top: 65535;}
            placeholderText: "loacl port"

        }
        TextField {
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.alignment: Qt.AlignCenter
            id: serverPort
            validator: IntValidator {bottom: 0; top: 65535;}
            placeholderText: "server port"

        }
        TextField {
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.alignment: Qt.AlignCenter
            id: serverIp
            inputMask: "000.000.000.000;_"
            placeholderText: "server IP"

        }
        Button {
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.alignment: Qt.AlignCenter
            text: "Connect"
            onClicked:{
                onClicked: model.setupConnection(name.text,localPort.text,serverPort.text,serverIp.text)
                accepted()
            }
        }
    }

}

