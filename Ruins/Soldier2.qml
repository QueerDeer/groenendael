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
            width: 15
            height: 20
            anchors.centerIn: parent
            source: "/Skeleton_Idle.png"
            frameCount: 11
            frameRate: 9
            frameWidth: 24
            frameHeight: 32
            running: true
        }
    }

    function hello ()
    {
        visible = false;
        console.log(objectName);
    }
}
