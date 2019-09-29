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
                if(view.currentItem.title === "Chat"){
                    return "Clients"
                }
                if(view.currentItem.title === "Clients"){
                    return "Back"
                }
            }
            visible: {
                return view.currentItem.title !== "Login"? true:false
            }

            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.verticalCenter: parent.verticalCenter
            onClicked: {
                if(view.currentItem.title === "Clients"){
                    view.currentIndex = 1
                }
                else if(view.currentItem.title === "Chat"){
                    view.currentIndex = 2
                }

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
    SwipeView {
        id: view
        currentIndex: 0
        anchors.fill: parent
        interactive: false


        Page{
            title: qsTr("Login")

           Login{
                onAccepted:{
                    view.currentIndex++
                    visible=false
                }
            }
        }
        Page{
            title: qsTr("Chat")


            ChatWindow{
            }
        }
        Page{
            title: qsTr("Clients")
            ClientsWindow{
            }
        }
    }

    onClosing: {
        model.disconnect()
    }


}
