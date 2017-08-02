import QtQuick 2.7

Page1Form {
    button.onClicked: {
        if(textField.text==="Helen?") {
            swipeView.state = "verified"
            animation.state = "2"
            button.enabled = false
        }
    }

}
