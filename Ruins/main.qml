import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.2

ApplicationWindow {
    visible: true
    width: 360
    height: 640
    title: qsTr("Ruin")

    signal qmlChangeField(string msg, string pos)
    signal qmlGenerateField()
    signal qmlStartEngine()
    signal qmlCreateSoldier(string pos)

    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        Page {
            Item {
                ColumnLayout {
                x: 80
                y: 160
                width: 200
                height: 200

                    Button {
                        id: button
                        text: qsTr("Go")
                        Material.background: "#FFCC80"
                        Layout .fillWidth: true
                        Layout .fillHeight: true
                        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                        onClicked: {qmlStartEngine()}
                    }

                    Button {
                        id: button1
                        text: qsTr("Generate")
                        Material.background: "#FFCC80"
                        Layout .fillWidth: true
                        Layout .fillHeight: true
                        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                        onClicked: {qmlGenerateField()}
                    }

                    Button {
                        id: button2
                        text: qsTr("Quit")
                        Material.background: "#FFCC80"
                        Layout .fillWidth: true
                        Layout .fillHeight: true
                        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                        onClicked: {Qt.quit()}
                    }
                }
            }

        }

        Page {
            id:page
            Grid {
                columns: 18
                rows: 32
                spacing: 0

                Repeater {
                    id:mmm
                    objectName: "mmm"
                    model: 576

                    function changecolor(pos, msg) {
                        mmm.itemAt(pos).color = msg;
                    }

                    function createsoldier(pos) {
                        if (pos < 288) {
                            var component = Qt.createComponent("Soldier1.qml");
                            component.createObject(page);
                        }
                        else {
                            var component2 = Qt.createComponent("Soldier2.qml");
                            component2.createObject(page);
                        }
                        }

                    Rectangle {
                        width: 20
                        height: 20
                        color: "#FFCC80"

                        MouseArea {
                            anchors.fill: parent
                            onClicked: {qmlCreateSoldier(index)}
                        }
                    }

                }

            }
        }

        Page {
            Item {
                width: 360
                height: 640

                ScrollView {
                    id: scrollView
                    x: 59
                    y: 8
                    width: 293
                    height: 572

                    TextArea {
                        id: textArea
                        text: qsTr("Log\nLog\nLog\nLog\nLog\nLog\nLog\nLog\nLog\nLog\nLog\nLog\nLog\nLog\nLog\nLog\nLog\nLog\nLog\nLog\nLog\nLog\nLog\nLog\nLog\nLog\nLog\nLog\nLog\nLog\nLog\nLog\nLog\nLog\nLog\nLog\nLog\nLog\nLog\nLog\nLog\nLog\nLog\nLog\nLog\nLog\nLog\nLog\nLog\nLog\nLog\nLog\nLog\nLog\nLog\nLog\nLog\nLog\nLog\nLog\n")
                        readOnly: true
                    }
                }
            }

        }
    }

    footer: TabBar {
        id: tabBar
        currentIndex: swipeView.currentIndex
        contentHeight: 47

        TabButton {
            text: qsTr("Menu")
        }
        TabButton {
            text: qsTr("Field")
        }
        TabButton {
            text: qsTr("Log")
        }
    }
}
