import QtQuick 2.2
import QtMultimedia 5.8

Rectangle{
//    property alias imageShutWidth: imageShut.width;
//    property alias imageShutHeight: imageShut.height;
//    implicitWidth: 60;
//    implicitHeight: 88;
//    anchors.bottom: parent.bottom
//    anchors.right: parent.right
//    color: "black"
    width: parent.width;
    height: parent.height;
    Camera {
        id: camera;
        captureMode: Camera.CaptureStillImage;
        focus {
            focusMode: Camera.FocusAuto;
            focusPointMode: Camera.FocusPointCenter;
//            focusPointMode: Camera.FocusPointFaceDetection;
        }

        imageProcessing {
            whiteBalanceMode: CameraImageProcessing.WhiteBalanceAuto;
        }
        flash.mode: Camera.FlashAuto;

        imageCapture {
            property int imageWidth: 800;//parseInt( parent.width)
            property int imageHeight: 600;
            id: imageShut;
            resolution: Qt.size( imageWidth , imageHeight );
            onImageCaptured: {
                camera.stop();
//                photoPreview.visible = true;
//                actionBar.visible = false;
//                viewfinder.visible = false;
                photoPreview.source = preview;
            }
            onImageSaved: {
                console.log(path);
            }
        }
        onLockStatusChanged: {
            console.log( "onLockStatusChanged");
            console.log( lockStatus );
            switch(Camera.lockStatus){
            case Camera.Locked:
                console.log("locked");
                imageCapture.captureToLocation("capture.jpg");
//                unlock();
                Camera.unlock();
                break;
            case Camera.Searching:
                console.log("searching");
                break;
            case Camera.Unlocked:
                console.log("unlocked");
                break;
            }
        }
    }
    VideoOutput {
        id: viewfinder;
        source: camera;
        focus : visible;
        anchors.fill: parent;
        autoOrientation: true;
    }
	//TODO:Capture picture show
}
