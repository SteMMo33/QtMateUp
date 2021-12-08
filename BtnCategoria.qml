import QtQuick 2.0

Item {
    id: btnCategoria
    width: 300
    height: 200
    property alias image: image
    property alias txtNome: txtNome
    Rectangle {
        id: rectangle
        color: "#ffffff"
        radius: 20
        anchors.bottomMargin: 45
        anchors.fill: parent

        Image {
            id: image
            anchors.rightMargin: 10
            anchors.leftMargin: 10
            anchors.bottomMargin: 10
            anchors.topMargin: 10
            anchors.fill: parent
            source: "qrc:/images/qr_code.png"
            fillMode: Image.PreserveAspectFit
        }

    }

    Text {
        id: txtNome
        x: 111
        y: 77
        color: "#e90000"
        text: qsTr("Nome")
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 4
        font.bold: true
        font.pixelSize: 28
    }

}













/*##^## Designer {
    D{i:1;anchors_height:200;anchors_width:449;anchors_x:55;anchors_y:60}
}
 ##^##*/
