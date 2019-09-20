import QtQuick 2.0
import QtQuick.Controls 2.5

Button {
    id: pingButton
    objectName: "pingButton"
    text: "Ping"
    onClicked: model.submit()
}
