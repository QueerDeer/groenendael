import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.2

Item {
    id: item1
    width: 360
    height: 640
    property alias button: button
    property alias item1: item1
    property alias progressBar: progressBar
    property alias appearence5: appearence5


    ColumnLayout {
        id: columnLayout
        x: 130
        width: 122
        height: 236
        anchors.horizontalCenterOffset: 0
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 23

        Label {
            id: label
            text: qsTr("GOTCHA!")
            opacity: 0
            visible: false
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            onVisibleChanged: label1.visible = true

            OpacityAnimator {
                id: appearence5
                target: label
                from: 0
                to: 1
                duration: 2000
                running: false
                onStopped: appearence6.running = true
            }
        }

        Label {
            id: label1
            text: qsTr("Helen")
            opacity: 0
            visible: false
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            onVisibleChanged: label2.visible = true

            OpacityAnimator {
                id: appearence6
                target: label1
                easing.type: Easing.OutCubic
                from: 0
                to: 1
                duration: 10000
                running: false
                onStopped: appearence7.running = true
            }
        }

        Label {
            id: label2
            text: qsTr("I love you, my dear ♡")
            opacity: 0
            visible: false
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

            OpacityAnimator {
                id: appearence7
                target: label2
                easing.type: Easing.OutCubic
                from: 0
                to: 1
                duration: 10000
                running: false
            }
        }
    }

    RowLayout {
        id: rowLayout
        x: 21
        y: 540
        width: 282
        height: 100
        anchors.horizontalCenterOffset: 0
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 7

        ColumnLayout {
            id: columnLayout1
            width: 100
            height: 100

            Label {
                id: label3
                text: qsTr("Push it to the limit :3")
            }

            ProgressBar {
                id: progressBar
                indeterminate: false
                width: 165
                height: 7
                value: 0
                from: 0
                to: 100
                Material.accent: Material.Cyan
            }
        }

        Button {
            id: button
            text: qsTr("Hold!")
            Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
            Material.background: Material.Cyan
        }
    }
    states: [
        State {
            name: "State1"

            PropertyChanges {
                target: label
                text: qsTr("GOTCHA!")
                visible: true
            }

            PropertyChanges {
                target: rowLayout
                x: 21
                y: 540
                width: 282
                height: 100
                anchors.horizontalCenterOffset: 0
                anchors.bottomMargin: 7
            }

            PropertyChanges {
                target: label1
                text: qsTr("Helen,")
            }
        }
    ]
}
