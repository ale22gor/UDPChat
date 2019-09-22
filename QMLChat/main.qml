import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.5

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("QMLChat")

    Popup {
        id: popup
        visible: true;
        anchors.centerIn: Overlay.overlay
        width: 300
        height: 300
        modal: true
        focus: true
        closePolicy: Popup.NoAutoClose

        Login{
            anchors.fill: parent
            onLogin: popup.close()
        }



    }


    GridLayout {
        id: grid
        columns: 2
        rows: 2
        anchors.fill: parent


        MessageList{

            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.minimumWidth: parent.width * 0.7
            Layout.minimumHeight: parent.height * 0.9

        }

        ClientList{
            Layout.minimumWidth : parent.width * 0.3
            Layout.minimumHeight: parent.height * 0.9
            Layout.fillWidth: true
            Layout.fillHeight: true

        }

        Rectangle {
            color: 'plum'
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.minimumWidth: parent.width * 0.7
            Layout.minimumHeight: parent.height * 0.1

            MessageInput{
                Layout.fillWidth: true
                Layout.fillHeight: true
            }

        }

        PingButton{
            Layout.minimumWidth: parent.width * 0.3
            Layout.minimumHeight: parent.height * 0.1
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

    }
    // @disable-check M16
    onClosing: {
        model.disconnect()
    }


}
