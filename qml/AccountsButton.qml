import QtQuick 2.2
import QtQuick.Controls 1.4

ToolButton
{
    anchors.top: parent.top
    width: parent.height
    height:width

    Image
    {
        source: "../images/cash.jpeg"
        anchors.fill: parent
        anchors.margins: 1
    }
//    onClicked: stackView.pop();
}
