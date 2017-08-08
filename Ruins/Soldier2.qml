import QtQuick 2.0

Item {
    Rectangle {
        width: 20
        height: 20
        color: "transparent"

        MouseArea {
            anchors.fill: parent
        }

        AnimatedSprite {
            width: 20
            height: 20
            anchors.centerIn: parent
            source: "/goblin_idle.png"
            frameCount: 3
            frameRate: 5
            frameWidth: 672
            frameHeight: 672
            running: true
        }
    }

    function hello ()
    {
        visible = false;
        console.log(objectName);
    }
}
