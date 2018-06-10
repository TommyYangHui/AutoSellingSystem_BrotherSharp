import QtQuick 2.2

Rectangle{
    id: thanksPanel;
    width: parent.width;
    height: parent.height;

    Image {
        id: imageThanks;
        anchors.centerIn: parent;
        width: parent.width / 2;
        height: parent.height / 2;
        source: "qrc:/images/thankyou.jpeg";
        fillMode: Image.Stretch;
    }


    Rectangle
    {
        id:backButtonPanel3;
        radius: 8;
        width: 440;
        height: 80;
        z: 4;
        anchors.left: parent.horizontalCenter;
        anchors.bottom: parent.bottom;
        anchors.bottomMargin: 8;
        BackButton{}


    }
    Rectangle{
        id: countDownPanel2;
        width: 80;
        height: 80;
        anchors.left: parent.left;
        anchors.bottom: parent.bottom;
        anchors.bottomMargin: 8;

        TimerCountDown{
            id : timer2
            timerLength:3;
            onTriggered:{
                if( timerLength < 0)
                    //jump to the the first ui
                   stackView.pop( null );
            }

        }

     }
}

