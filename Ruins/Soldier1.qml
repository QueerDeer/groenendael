import QtQuick 2.0

Item {
    Rectangle {
        width: 20
        height: 20
        color: "#FFCC80"

        MouseArea {
            anchors.fill: parent
        }

        Image {
            anchors.fill: parent
            source: "/sold1.png"
        }
    }
}
