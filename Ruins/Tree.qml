import QtQuick 2.0

Item {
    Rectangle {
        width: 50
        height: 50
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
