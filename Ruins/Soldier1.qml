import QtQuick 2.0

Item {
    Rectangle {
        width: 30
        height: 30
        color: "transparent"

        MouseArea {
            anchors.fill: parent
        }

        AnimatedSprite {
            width: 30
            height: 30
            anchors.centerIn: parent
            source: "/templar_3_idle.png"
            frameCount: 4
            frameRate: 5
            frameWidth: 42
            frameHeight: 42
            running: true
        }
    }

    function hello ()
    {
        visible = false;
        console.log(objectName);

    }
}
