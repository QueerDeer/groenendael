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
        orientation: Qt.Vertical
        interactive:false
        currentIndex: 0

        Page {
            Item {
                Image {
                    id: menush
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
                        onClicked: {
                            qmlGenerateField();
                            qmlStartEngine();
                            swipeView.interactive = true;
                            timer.running = true;
                        }
                        onPressedChanged: {
                            if( pressed ) {
                                opacity = 0.75
                            }
                            else {
                                opacity = 1
                            }
                        }

                        Timer {
                            id: timer
                            interval: 2000; running: false; repeat: false
                            onTriggered: swipeView.currentIndex = 1
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

                    function createsoldier(pos, idshka) {
                        if (pos < 288) {
                            var component = Qt.createComponent("Soldier1.qml");
                            component.createObject(page, {"x": 20*(pos%18)-5, "y": 20*Math.floor(pos/18)-10, "id":idshka, "objectName":idshka});
                        }
                        else {
                            var component2 = Qt.createComponent("Soldier2.qml");
                            component2.createObject(page, {"x": 20*(pos%18), "y": 20*Math.floor(pos/18)-5, "id":idshka, "objectName":idshka});
                        }
                    }

                    function createtree (pos, idshka) {
                        var component3 = Qt.createComponent("Tree.qml");
                        component3.createObject(page, {"x": 20*(pos%18)-10, "y": 20*Math.floor(pos/18)-30, "id":idshka, "objectName":idshka});
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

    }

}
