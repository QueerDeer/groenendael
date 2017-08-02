import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    SwipeView {
        id: swipeView
        anchors.fill: parent

        state: "logging"
        states: [
            State {
                name: "logging"
                PropertyChanges { target: swipeView; interactive: false}
            },
            State {
                name: "verified"
                PropertyChanges { target: swipeView; interactive: true}
            }
        ]

        Page1 {
            AnimatedImage {
                id: animation
                anchors.leftMargin: 8
                anchors.left: parent.left
                anchors.bottom: parent.bottom
                anchors.verticalCenter: parent.verticalCenter
                source: "/images/jumping_cat.gif"
                onFrameChanged: if(currentFrame==frameCount-1) {
                                    playing = false
                                }
                opacity: 0

                OpacityAnimator {
                    id: appearence4
                    target: animation
                    from: 0
                    to: 1
                    duration: 2000
                    running: false
                }

                state: "1"

                states: [
                    State {
                        name: "1"
                        PropertyChanges { target: animation; visible: false}
                        PropertyChanges { target: animation; playing: false}

                    },
                    State {
                        name: "2"
                        PropertyChanges { target: animation; visible: true}
                        PropertyChanges { target: animation; playing: false}
                        PropertyChanges { target: appearence4; running: true}

                    },
                    State {
                        name: "3"
                        PropertyChanges { target: animation; visible: true}
                        PropertyChanges { target: animation; playing: true}
                    }
                ]
            }
        }

        Page2 {
        }

    }

}
