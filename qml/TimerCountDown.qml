import QtQuick 2.2

Rectangle{
    id: timerMoudle;
    property alias timerLength: attrs.counter;
    signal triggered;
    width: parent.width;
    height: parent.height;

    QtObject{
        id: attrs;
        property int counter;
    }

    Text {
        id: countShow;
        anchors.centerIn: parent;
        color: "black";
        font.pixelSize: 40;
    }

    Timer {
        id: countDown;
        interval: 1000;
        repeat: true;
        triggeredOnStart: true;
        onTriggered:{
            countShow.text = attrs.counter;
            attrs.counter -= 1;
            if(attrs.counter < 0)
            {
                countDown.stop();
            }
            timerMoudle.triggered();
        }
    }
    Component.onCompleted: {
        countDown.start();
    }



}
