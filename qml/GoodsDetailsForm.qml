import QtQuick 2.2
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1
import QtQuick.XmlListModel 2.0
import QtQuick.Window 2.1

Rectangle {
    property string goodsId;
    property string goodsName;
    property string goodsImage;
    property string goodsDescription;
    property string goodsUnitPrice;
    property string goodsBranch;
    width: parent.width;
    height: parent.height;

    Component{
        id: accountsForm;
        AccountsForm{}
    }
    Image {
        id: imageShow;
        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.top: parent.top;
        anchors.topMargin: 3;
        source: goodsImage;
        width: parent.width / 2 ;
        height: parent.height / 2;
        fillMode: Image.Stretch;


    }
    TextArea {
        id: goodsDetailShow;
        text: "name: " + goodsName + "\n" + "¥:" + "\n"+ goodsUnitPrice  +  "description: " + goodsDescription + "\n" +  "taste: " + "\n" + goodsBranch;
        anchors.top: imageShow.bottom;
        anchors.topMargin: 3;
        anchors.horizontalCenter: imageShow.horizontalCenter;
        width: parent.width / 2;
        height: parent.height / 4 ;
        wrapMode: Text.Wrap;
        font.pixelSize: 16;
    }
    Rectangle
    {
        id:toolArea;
        radius: 8;
        width: 440;
        height: 80;
        z: 4;
        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.bottom: parent.bottom;
        anchors.bottomMargin: 8;
        BackButton{}
        AccountsButton{
            anchors.horizontalCenter: parent.horizontalCenter;
            onClicked: {
                //jump to accountsForm
                stackView.push( accountsForm );
//                stackView.push( accountsForm, { is_FacePay: true } );
            }
        }
        ShoppingCarButton{
            anchors.right: parent.right;
            onClicked: {
            //TODO: Add shopping Car function
            }
        }

    }

}
