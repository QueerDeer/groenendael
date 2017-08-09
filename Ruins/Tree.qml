import QtQuick 2.0

Item {
    Rectangle {
        width: 40
        height: 40
        color: "transparent"

        Image {
            anchors.fill: parent
        }
    }

    function hello ()
    {
        visible = false;
        console.log(objectName);

    }
}
