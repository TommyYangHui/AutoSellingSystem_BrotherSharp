import QtQuick 2.2
import QtQuick.Controls 1.4
//import Qt.labs.platform 1.0
import QtQuick.Dialogs 1.2
ToolButton
{
    anchors.top: parent.top;
    width: parent.height;
    height:width;

    MessageDialog {
        id: messageDialogShopCar;
        icon: StandardIcon.Information;
        text: " Sorry\n\n\n The Shopping Car function is constructing! \n\n Thank you for your support!";
        onAccepted: {
            visible = false;
        }
        Component.onCompleted: visible = false;
        onYes: messageDialogShopCar.close();
    }
    Image
    {
        source: "../images/shoppingCar.jpeg";
        anchors.fill: parent;
        anchors.margins: 1;
    }
    MouseArea {
        id: mouseAreaShopCar;
        anchors.fill: parent;
        hoverEnabled: true;
        onClicked: {
            messageDialogShopCar.open();
        }
    }

}
