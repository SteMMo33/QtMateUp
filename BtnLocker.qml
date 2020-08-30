import QtQuick 2.4

BtnLockerForm {
    signal click()

    mouseArea.onClicked: click()
}
