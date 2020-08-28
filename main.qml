import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    id: window
    width: 900
    height: 600
    visible: true
    title: qsTr("QtLocker")

    Item {
        id: pnlHeader
        y: 0
        height: 150
        anchors.left: parent.left
        anchors.right: parent.right

        Rectangle {
            id: rectHeaderBackg
            color: "#b1a7a7"
            radius: 18
            anchors.fill: parent

            Rectangle {
                id: rectHeaderLeft
                width: 200
                color: "#241b1b"
                radius: 15
                anchors.left: parent.left
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                anchors.topMargin: 10
                anchors.bottomMargin: 10
                anchors.leftMargin: 20
            }

            Rectangle {
                id: rectHeaderCenter
                color: "#241b1b"
                radius: 15
                anchors.left: rectHeaderLeft.right
                anchors.right: rectHeaderRight.left
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                anchors.rightMargin: 20
                anchors.leftMargin: 20
                anchors.bottomMargin: 10
                anchors.topMargin: 10

                Text {
                    id: txtHeaderC1
                    color: "#fdfdfd"
                    text: qsTr("Locker 1 - AMtek - Prova")
                    anchors.left: parent.left
                    anchors.right: parent.right
                    anchors.top: parent.top
                    font.pixelSize: 21
                    horizontalAlignment: Text.AlignHCenter
                    fontSizeMode: Text.HorizontalFit
                    font.bold: true
                    anchors.topMargin: 35
                    anchors.rightMargin: 15
                    anchors.leftMargin: 15
                }

                Text {
                    id: txtHeaderC2
                    y: 43
                    color: "#e88705"
                    text: qsTr("SELEZIONA IL SERVIZIO")
                    anchors.left: parent.left
                    anchors.right: parent.right
                    anchors.bottom: parent.bottom
                    font.pixelSize: 19
                    horizontalAlignment: Text.AlignHCenter
                    anchors.bottomMargin: 20
                    font.bold: true
                    anchors.rightMargin: 30
                    anchors.leftMargin: 30
                }
            }

            Rectangle {
                id: rectHeaderRight
                x: 554
                width: 200
                color: "#241b1b"
                radius: 15
                anchors.right: parent.right
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                anchors.rightMargin: 20
                anchors.bottomMargin: 10
                anchors.topMargin: 10

                BtnLockerForm {
                    id: btnLockerDeposito
                    anchors.fill: parent
                    anchors.rightMargin: 10
                    anchors.leftMargin: 10
                    anchors.bottomMargin: 10
                    anchors.topMargin: 10
                    text2.text: "Clicca per il deposito"
                    text1.text: "DEPOSITO ARTICOLO"
                }
            }
        }

    }

    Item {
        id: pnlHome
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: pnlHeader.bottom
        anchors.bottom: parent.bottom

        Rectangle {
            id: btnHomeRitiro
            x: 275
            y: 282
            width: 263
            height: 200
            radius: 20
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            gradient: Gradient {
                GradientStop {
                    position: 0
                    color: "#c5b703"
                }

                GradientStop {
                    position: 1
                    color: "#e88705"
                }
            }
            Text {
                id: btnHomeRitiroText
                y: 34
                color: "#fdfdfd"
                text: qsTr("RITIRO ARTICOLO")
                anchors.left: parent.left
                anchors.right: parent.right
                font.pixelSize: 26
                horizontalAlignment: Text.AlignHCenter
                wrapMode: Text.WordWrap
                font.bold: true
                style: Text.Sunken
                anchors.rightMargin: 20
                minimumPixelSize: 17
                fontSizeMode: Text.FixedSize
                anchors.leftMargin: 20
            }

            Text {
                id: btnHomeRitiroText2
                y: 120
                color: "#fdfdfd"
                text: qsTr("Clicca qui per ritirare un articolo")
                anchors.left: parent.left
                anchors.right: parent.right
                font.pixelSize: 19
                horizontalAlignment: Text.AlignHCenter
                wrapMode: Text.WordWrap
                font.family: "MS Shell Dlg 2"
                fontSizeMode: Text.FixedSize
                anchors.leftMargin: 20
                anchors.rightMargin: 20
                minimumPixelSize: 17
                font.bold: true
                style: Text.Sunken
            }
        }
    }



    Item {
        id: pnlDeposito
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: pnlHeader.bottom
        anchors.bottom: parent.bottom
    }



    Item {
        id: pnlRitiro
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: pnlHeader.bottom
        anchors.bottom: parent.bottom

        BtnLockerForm {
            id: btnLockerRitiroArticolo
            x: 14
            y: 25
            width: 381
            height: 266
            text2.horizontalAlignment: Text.AlignHCenter
            text1.horizontalAlignment: Text.AlignHCenter
            text2.text: "Clicca qui per ritirare un articolo"
            text1.text: "RITIRO ARTICOLO"
        }

    }


}

/*##^##
Designer {
    D{i:3}D{i:5}D{i:6}D{i:4}D{i:8}D{i:7}D{i:2}D{i:1}D{i:14;invisible:true}D{i:15;invisible:true}
D{i:9}D{i:16;invisible:true}D{i:17;invisible:true}
}
##^##*/
