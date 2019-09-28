import QtQuick 2.0
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.5


GridLayout {
    id: grid
    columns: 2
    rows: 7
    anchors.fill: parent
    MessageList{
        Layout.rightMargin: 10
        Layout.leftMargin: 5
        Layout.topMargin: 5

        Layout.columnSpan: 2
        Layout.fillWidth: true
        Layout.fillHeight: true
        Layout.rowSpan:  6
    }
    MessageInput{
        Layout.fillWidth: true
        Layout.minimumWidth: 100
        Layout.preferredHeight: 50
    }
    PingButton{
        Layout.preferredHeight: 50
    }

}


