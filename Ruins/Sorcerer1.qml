import QtQuick 2.0

Item {
    id:sorcerer1
    objectName:sorcerer1
    x: 680
    y: 40

    Rectangle {
        width: 80
        height: 80
        color: "transparent"

        AnimatedSprite {
            width: 80
            height: 80
            anchors.centerIn: parent
            source: "/summoner_idle_animation.png"
            frameCount: 12
            frameRate: 5
            frameWidth: 80
            frameHeight: 80
            running: true
        }

    }

    function hello ()
    {
        visible = false;
        console.log(objectName);

    }
}
