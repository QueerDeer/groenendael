import QtQuick 2.0

Item {
    id:sorcerer2
    objectName:sorcerer2
    x: 0
    y: 1210

    Rectangle {
        width: 80
        height: 80
        color: "transparent"

        AnimatedSprite {
            width: 80
            height: 80
            anchors.centerIn: parent
            source: "/sorcerer_villain_idle.png"
            frameCount: 11
            frameRate: 5
            frameWidth: 200
            frameHeight: 200
            running: true
        }
    }

    function hello ()
    {
        visible = false;
        console.log(objectName);

    }
}
