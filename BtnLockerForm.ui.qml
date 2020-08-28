import QtQuick 2.4

Item {
    width: 350
    height: 300
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
                color: "#fed513"
            }

            GradientStop {
                position: 1
                color: "#fbdf5a"
            }
        }

        Text {
            id: text1
            y: 97
            width: 200
            height: 24
            color: "#fdfdfd"
            text: qsTr("Text")
            anchors.left: parent.left
            anchors.right: parent.right
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
            wrapMode: Text.WordWrap
            fontSizeMode: Text.VerticalFit
            anchors.rightMargin: 40
            anchors.leftMargin: 40
        }

        Text {
            id: text2
            y: 223
            color: "#fdfdfd"
            text: qsTr("Text")
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
            anchors.bottomMargin: 50
            fontSizeMode: Text.HorizontalFit
            anchors.rightMargin: 30
            anchors.leftMargin: 30
        }
    }
}

/*##^##
Designer {
    D{i:5}D{i:6}D{i:1}
}
##^##*/

