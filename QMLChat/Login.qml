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
            Layout.fillWidth: true
            Layout.fillHeight: true
            id: name
            maximumLength:12
            placeholderText: "userName"
            onActiveFocusChanged:{
                inputMask: "Aaaaaaaaaaaa"
            }
        }
        TextField {
            Layout.fillWidth: true
            Layout.fillHeight: true
            id: localPort
            validator: RegExpValidator{regExp:{
                    var myRE = new RegExp (['([1-9]|[1-8][0-9]|9[0-9]|[1-8][0-9]{2}|9',
                                            '[0-8][0-9]|99[0-9]|[1-8][0-9]{3}|9[0-8][0-9]{2}|',
                                            '99[0-8][0-9]|999[0-9]|[1-5][0-9]{4}|6[0-4][0-9]{3}|',
                                            '65[0-4][0-9]{2}|655[0-2][0-9]|6553[0-5])'].join(''));
                    return myRE
                }
            }

            placeholderText: "loacl port"

        }
        TextField {
            Layout.fillWidth: true
            Layout.fillHeight: true
            id: serverPort
            validator: RegExpValidator{regExp:{
                    var myRE = new RegExp (['([1-9]|[1-8][0-9]|9[0-9]|[1-8][0-9]{2}|9',
                                            '[0-8][0-9]|99[0-9]|[1-8][0-9]{3}|9[0-8][0-9]{2}|',
                                            '99[0-8][0-9]|999[0-9]|[1-5][0-9]{4}|6[0-4][0-9]{3}|',
                                            '65[0-4][0-9]{2}|655[0-2][0-9]|6553[0-5])'].join(''));
                    return myRE
                }
            }
            placeholderText: "server port"

        }
        TextField {
            Layout.fillWidth: true
            Layout.fillHeight: true
            id: serverIp
            validator: RegExpValidator{regExp:{
                    var ipRange = '(([ 0]+)|([ 0]*[0-9] *)|([0-9][0-9] )|([ 0][0-9][0-9])|(1[0-9][0-9])|([2][0-4][0-9])|(25[0-5]))';
                    var ipRegex = new RegExp (['^',
                                               ipRange,
                                               '\\.',
                                               ipRange,
                                               '\\.',
                                               ipRange,
                                               '\\.',
                                               ipRange,
                                               '$'].join(''));
                    return ipRegex
                }
            }
            placeholderText: "server IP"
            inputMask:"000.000.000.000"


        }
        Button {
            Layout.fillWidth: true
            Layout.fillHeight: true
            text: "Connect"
            onClicked:{
                onClicked: model.setupConnection(name.text,localPort.text,serverPort.text,serverIp.text)
                accepted()
            }
        }
    }

}

