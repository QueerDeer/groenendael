import QtQuick 2.0

Item {
    id:sorcer2
    objectName:"sorcer2"
    x: 0
    y: 1228

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
