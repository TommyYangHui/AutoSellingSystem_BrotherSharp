import QtQuick 2.2
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1
import QtQuick.XmlListModel 2.0

Rectangle {
    width: parent.width;
    height: parent.height;
    //goodsShow start
    Component{
        id: goodsDetailForm;
        GoodsDetailsForm{}
    }

    Component {
        id: videoDelegate;
        Item {
            id: wrapper;
            width: goodsView.cellWidth;
            height: goodsView.cellHeight;

            MouseArea {
                anchors.fill: parent;
                onClicked:{
                    wrapper.GridView.view.currentIndex = index;
                     //jump to goodsDetailForm
                    stackView.push( goodsDetailForm, { goodsName: name, goodsImage: image, goodsDescription: description, goodsUnitPrice: unitPrice, goodsBranch: branch } );
                }
            }

            Image {
                id: poster;
                anchors.horizontalCenter: parent.horizontalCenter;
                anchors.top: parent.top;
                anchors.topMargin: 3;
                source: image;
                width: parent.width ;
                height: parent.height * 5 / 6;
                fillMode: Image.PreserveAspectFit;

            }
            //unitPrice
            Text {
                anchors.top: poster.bottom;
                anchors.topMargin: 4;
                width: parent.width;
                height: parent.height / 6;
                text: name + "\n" + "¥" + unitPrice;
                color: wrapper.GridView.isCurrentItem ? "blue" : "black";
                font.pixelSize: 16;
                horizontalAlignment: Text.AlignHCenter;
                elide: Text.ElideMiddle;
            }
        }
    }

    GridView {
       id: goodsView;
       anchors.fill: parent;
       cellWidth: parent.width / 5;
       cellHeight: parent.height / 2;
       model: messageCenter.goodsModel;
       delegate: videoDelegate;
       focus: true;
   }
    //goodsShow end
    //camera start:
    Rectangle{
        width: parent.width / 5;
        height: parent.height / 2;
        anchors.bottom: parent.bottom;
        anchors.right: parent.right;
        color: "black";
        CameraForm{

        }
    }
    //camera end:
}
