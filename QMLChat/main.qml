import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("QMLChat")


    header:ToolBar {
        ToolButton {
            text:{
                return view.currentItem.title === "Clients" ?  "Back" : "Clients"
            }

            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.verticalCenter: parent.verticalCenter
            onClicked: {
                view.currentItem.title !== "Chat" ?  view.currentIndex = 0 : view.currentIndex++
            }
        }

        Label {
            text: view.currentItem.title
            anchors.leftMargin: 10
            anchors.horizontalCenter: parent.horizontalCenter
            padding: 10
            font.pixelSize: 20
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
    }

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

    SwipeView {
        id: view
        currentIndex: 0
        anchors.fill: parent

        ChatWindow{
            title: qsTr("Chat")
        }
        ClientsWindow{
            title: qsTr("Clients")
        }
    }




    // @disable-check M16
    onClosing: {
        model.disconnect()
    }


}
