import QtQuick 2.0

Item {
    id: btnProdotto
    width: 500
    height: 400
    property alias txtPrezzo: txtPrezzo.text
    property alias txtNome: txtNome.text
    Rectangle {
        id: rectangle
        color: "#ffffff"
        radius: 30
        anchors.fill: parent

        Text {
            id: txtNome
            x: 46
            y: 156
            text: qsTr("Nome")
            font.bold: true
            font.pixelSize: 37
        }

        Text {
            id: txtPrezzo
            color: "#0000f2"
            text: qsTr("NN.00")
            font.bold: true
            horizontalAlignment: Text.AlignRight
            anchors.right: parent.right
            anchors.rightMargin: 10
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 10
            font.pixelSize: 38
        }

    }

}








