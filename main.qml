import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    id: window
    width: 800
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
        }
    }

    Item {
        id: pnlHome
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: pnlHeader.bottom
        anchors.bottom: parent.bottom

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
    }

}

/*##^##
Designer {
    D{i:2}D{i:1}D{i:3}D{i:4}
}
##^##*/
