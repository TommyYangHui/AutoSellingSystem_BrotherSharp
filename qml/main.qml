import QtQuick 2.9
import QtQuick.Controls 2.3

ApplicationWindow {
    id: window;
    visible: true;
    width: 800;
    height: 480;
    minimumWidth: 800;
    minimumHeight: 480;
    objectName: "qmlWin";
    color: "black";
    title: qsTr("Face Recognition Auto Sales System")
    Component{
        id: goodsShowForm;
        GoodsShowForm{}
    }

    StackView {
        id: stackView;
        initialItem: goodsShowForm;
        anchors.fill: parent;
    }
}
