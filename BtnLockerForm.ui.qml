import QtQuick 2.4

Item {
    id: bottone
    width: 350
    height: 250
    property alias text2: text2
    property alias text1: text1

    Rectangle {
        id: rectBackground
        width: 200
        height: 200
        radius: 18
        anchors.fill: parent
        gradient: Gradient {
            GradientStop {
                position: 0
                color: "#c5b703"
            }

            GradientStop {
                position: 1
                color: "#fbdf5a"
            }
        }

        Text {
            id: text1
            x: 75
            y: 117
            width: 200
            height: 24
            color: "#fdfdfd"
            text: qsTr("Text")
            font.pixelSize: 20
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
            height: 24
            color: "#fdfdfd"
            text: qsTr("Text")
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
            fontSizeMode: Text.HorizontalFit
        }
    }
}

/*##^##
Designer {
    D{i:5}D{i:6}D{i:1}
}
##^##*/

