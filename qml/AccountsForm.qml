import QtQuick 2.2
import QtQuick.Dialogs 1.2

Rectangle{
    id: accountsPanel;
    width: parent.width;
    height: parent.height;
    property bool is_FacePay:false;
    Component{
        id: thanksForm;
        ThanksForm{}
    }

    MessageDialog {
        id: messageDialogFacePay;
        icon: StandardIcon.Question;
        standardButtons:StandardButton.Yes |  StandardButton.No;
        text: " Dear\n Detected your face account. \n Do you want to pay in Face?";
        onAccepted: {
            visible = false;
        }
        Component.onCompleted: {
            if( is_FacePay == false )
                visible = false;
            else
                visible = true;
        }

        onYes:{
            messageDialogFacePay.close();
            timer1.timerLength = 1;

        }
        onNo: {
            messageDialogFacePay.close();

        }
    }
    Rectangle{
        id: accountsPicturePanel;
        width: parent.width / 2;
        height: parent.height / 2;
        anchors.centerIn : parent;

        Image {
            id: imageAlipayLogo;
            anchors.top: parent.top;
            anchors.left: parent.left;
            source: "qrc:/images/alipayLogo.png";
            width: parent.width / 3 ;
            height: parent.height / 3 ;
            fillMode: Image.Stretch;


        }
        Image {
            id: imageAlipay2Code;
            anchors.bottom: parent.bottom;
            anchors.left: parent.left;
            source: "qrc:/images/alipay2Code.png";
            width: parent.width / 3 ;
            height: parent.height * 2 / 3 ;
            fillMode: Image.Stretch;


        }
        Image {
            id: imageWeixinLogo;
            anchors.top: parent.top;
            anchors.right: parent.right;
            source: "qrc:/images/weixinpayLogo.png";
            width: parent.width / 3 ;
            height: parent.height / 3 ;
            fillMode: Image.Stretch;


        }
        Image {
            id: imageWeixin2Code;
            anchors.bottom: parent.bottom;
            anchors.right: parent.right;
            source: "qrc:/images/weixinpay2Code.png";
            width: parent.width / 3 ;
            height: parent.height * 2 / 3 ;
            fillMode: Image.Stretch;


        }
    }

    Rectangle
    {
        id:backButtonPanel2;
        radius: 8;
        width: 440;
        height: 80;
        z: 4;
        anchors.bottom: parent.bottom;
        anchors.left: parent.horizontalCenter;
        anchors.bottomMargin: 8;
        BackButton{}


    }
    Rectangle{
        id: countDownPanel1;
        width: 80;
        height: 80;
        anchors.left: parent.left;
        anchors.bottom: parent.bottom;
        anchors.bottomMargin: 8;

        TimerCountDown{
            id : timer1;
            timerLength: 10;
            onTriggered:{
                if( timerLength < 0 )
                    //jump to thanksForm
                   stackView.push( thanksForm );
            }

        }

     }
}
