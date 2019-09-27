import QtQuick 2.0
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.5


GridLayout {
    id: grid
    columns: 2
    rows: 2
    anchors.fill: parent


    MessageList{
        Layout.columnSpan: 2
        Layout.fillWidth: true
        Layout.fillHeight: true
        Layout.minimumWidth: parent.width
        Layout.minimumHeight: parent.height * 0.9

    }
    Rectangle {
        color: 'plum'
        Layout.fillWidth: true
        Layout.fillHeight: true
        Layout.minimumWidth: parent.width * 0.7
        Layout.minimumHeight: parent.height * 0.1

        MessageInput{
        }

    }

    PingButton{
        Layout.minimumWidth: parent.width * 0.3
        Layout.minimumHeight: parent.height * 0.1
        Layout.fillWidth: true
        Layout.fillHeight: true
    }

}


