import QtQuick 2.7
import QtMultimedia 5.9

Page2Form {
    button.onReleased: {
        simpletimer.stop()
}
    button.onPressed: {
        simpletimer.start()
    }

    Audio {
        id: playMusic
        source: "/music/love_me_tender.mpga"
    }

    Timer {
        id: simpletimer
        interval: 60
        repeat: true
        running: false
        onTriggered: if(progressBar.value < progressBar.to) progressBar.value += 1.0
                     else {
                         animation.state = "3"
                         item1.state = "State1"
                         appearence5.running = true
                         button.enabled = false
                         simpletimer.stop()
                         playMusic.play()
                     }

    }

}
