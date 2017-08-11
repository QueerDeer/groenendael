import QtQuick 2.0

Item {
    id:sorcer1
    objectName:"sorcer1"
    x: 650
    y: 10

    Rectangle {
        width: 60
        height: 60
        color: "transparent"

        AnimatedSprite {
            width: 60
            height: 60
            anchors.centerIn: parent
            source: "/summoner_idle_animation.png"
            frameCount: 7
            frameRate: 4
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
