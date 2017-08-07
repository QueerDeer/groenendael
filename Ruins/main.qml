import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

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
                Image {
                    id: menush
        //            anchors.fill: parent
                    x: 72
                    y: 160
                    z: 0
                    width: 216
                    height: 263
                    source: "/menu.png"
                }

                ColumnLayout {
                x: 107
                y: 279
                width: 148
                height: 105

                    Button {
                        id: button
                        Layout .fillWidth: true
                        Layout .fillHeight: true
                        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                        onClicked: {qmlGenerateField(); qmlStartEngine();}
                        onPressedChanged: {
                                if( pressed ) {
                                    opacity = 0.75
                                }
                                else {
                                    opacity = 1
                                }
                            }

                        Image {
                            id: but1
                            anchors.fill: parent
                            source: "/but1.png"
                        }
                    }

                    Button {
                        id: button1
                        Layout .fillWidth: true
                        Layout .fillHeight: true
                        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                        onPressedChanged: {
                                if( pressed ) {
                                    opacity = 0.75
                                }
                                else {
                                    opacity = 1
                                }
                            }

                        Image {
                            id: but2
                            anchors.fill: parent
                            source: "/but2.png"
                        }
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
//                        mmm.itemAt(pos).color = msg; //Math.floor(Math.random() * (24 + 1)).toString()
                        mmm.itemAt(pos).children[0].source = "/" + msg + ".png"
                        mmm.itemAt(pos).children[0].sourceChanged()
                    }

                    function createsoldier(pos) {
                        if (pos < 288) {
                            var component = Qt.createComponent("Soldier1.qml");
                            component.createObject(page, {"x": 20*(pos%18), "y": 20*Math.floor(pos/18)});
                        }
                        else {
                            var component2 = Qt.createComponent("Soldier2.qml");
                            component2.createObject(page, {"x": 20*(pos%18), "y": 20*Math.floor(pos/18)});
                        }
                        }

                    Rectangle {
                        width: 20
                        height: 20
                        color: "black"

                        Image {
                            anchors.fill: parent
                        }

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

//    footer: TabBar {
//        id: tabBar
//        currentIndex: swipeView.currentIndex
//        contentHeight: 47
//        opacity: 0.2

//        TabButton {
//            text: qsTr("Menu")
//        }
//        TabButton {
//            text: qsTr("Field")
//        }
//        TabButton {
//            text: qsTr("Log")
//        }
//    }
}
