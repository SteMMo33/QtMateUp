import QtQuick 2.0
import QtQuick.Window 2.2



    Item {
        id: pageAssistenza
        width: 900
        height: 600

        anchors.fill: parent
    BtnKeyboard {
        id: btnKeyboard
        x: 41
        y: 140
        width: 212
        height: 78
        keyName: "Cassetto 1"
    }

    BtnKeyboard {
        id: btnKeyboard1
        x: 41
        y: 224
        width: 212
        height: 90
        keyName: "Cassetto 2"
    }

    Text {
        id: element
        x: 185
        y: 23
        text: qsTr("ASSISTENZA")
        font.pixelSize: 46
        font.bold: true
        anchors.horizontalCenterOffset: 0
        anchors.horizontalCenter: parent.horizontalCenter
    }

    BtnKeyboard {
        id: btnKeyboard2
        x: 80
        y: 506
        width: 624
        height: 68
        anchors.horizontalCenterOffset: 0
        anchors.horizontalCenter: parent.horizontalCenter
        keyName: "RITORNA ALLA PAGINA INIZIALE"
        onPressedChanged: Loader.source = "qrc:/main.qml"
    }

    BtnKeyboard {
        id: btnKeyboard3
        x: 446
        y: 140
        width: 309
        height: 78
        keyName: "Abilita tutti i cassetti"
    }

    BtnKeyboard {
        id: btnKeyboard4
        x: 446
        y: 224
        width: 309
        height: 90
        keyName: "Apri motore a vite"
    }

    BtnKeyboard {
        id: btnKeyboard5
        x: 41
        y: 320
        width: 212
        height: 90
        keyName: "Cassetto 3"
    }

}




