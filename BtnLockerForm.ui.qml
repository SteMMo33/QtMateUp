import QtQuick 2.5

Item {
    id: bottone
    width: 350
    height: 250
    property alias mouseArea: mouseArea
    property alias text1Main: text1.text
    property alias textSec: text2.text

    Rectangle {
        id: rectBackground
        width: 200
        height: 200
        radius: 18
        anchors.fill: parent
        gradient: Gradient {
            GradientStop {
                position: 0
                color: "#9f8505"
            }

            GradientStop {
                position: 1
                color: "#fedb34"
            }
        }

        Text {
            id: text1
            x: 75
            y: 96
            width: 200
            height: 47
            color: "#fdfdfd"
            text: qsTr("Pri")
            anchors.horizontalCenterOffset: 0
            style: Text.Sunken
            font.pixelSize: 40
            horizontalAlignment: Text.AlignHCenter
            wrapMode: Text.WordWrap
            anchors.horizontalCenter: parent.horizontalCenter
            font.bold: true
            fontSizeMode: Text.Fit
        }

        Text {
            id: text2
            x: 164
            y: 160
            width: 100
            height: 40
            color: "#fdfdfd"
            text: qsTr("Sec")
            anchors.horizontalCenter: parent.horizontalCenter
            wrapMode: Text.WordWrap
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
            fontSizeMode: Text.Fit
        }

        MouseArea {
            id: mouseArea
            anchors.fill: parent
        }
    }
}

/*##^##
Designer {
    D{i:5}D{i:6}D{i:1}
}
##^##*/





/*##^## Designer {
    D{i:7;anchors_height:100;anchors_width:100}
}
 ##^##*/
