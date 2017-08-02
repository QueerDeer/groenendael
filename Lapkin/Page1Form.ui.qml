import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.2

Item {
    id: item1
    width: 360
    height: 640
    property alias button: button
    property alias textField: textField


    ColumnLayout {
        id: columnLayout
        x: 0
        width: 120
        height: 195
        anchors.horizontalCenterOffset: 0
        transformOrigin: Item.Center
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 65

        Label {
            id: label
            text: qsTr("Hi, who are you?")
            opacity: 0
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

            OpacityAnimator {
                id: appearence1
                target: label
                from: 0
                to: 1
                duration: 3000
                running: true
                onStopped: appearence2.running = true;
            }

        }

        TextField {
            id: textField
            text: "Helen?"
            opacity: 0
            horizontalAlignment: Text.AlignHCenter
            Material.accent: Material.Cyan

            OpacityAnimator {
                id: appearence2
                target: textField
                from: 0
                to: 1
                duration: 3000
                running: false
                onStopped: appearence3.running = true
            }
        }

        Button {
            id: button
            text: qsTr("It's me")
            opacity: 0
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Material.background: Material.Cyan

            OpacityAnimator {
                id: appearence3
                target: button
                from: 0
                to: 1
                duration: 3000
                running: false
            }

        }
    }
}
