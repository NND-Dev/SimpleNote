import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import NND.Model 1.0

Page {
    Model {
        id: myModel
    }
    ListView {
        id: list
        spacing: 5
        anchors.fill: parent
        anchors.margins: 10
        clip: true
        currentIndex: -1
        model: myModel

        highlight: Rectangle {
            color: "transparent"
            border.width: 1
            border.color: "orange"
            radius: 10
            z: 1
        }

        delegate: Rectangle {
            width: parent.width
            height: col.implicitHeight + 20
            border.color: "grey"
            border.width: 0.5
            radius: 10

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    list.currentIndex = index
                }
            }

            Column {
                id: col
                anchors.fill: parent
                anchors.margins: 10
                spacing: 5
                Label {
                    width: parent.width
                    text: model.TIEUDE
                    wrapMode: Text.WrapAnywhere
                    font.bold: true
                }
                Label {
                    width: parent.width
                    text: model.NOIDUNG
                    wrapMode: Text.WrapAnywhere
                }
            }
        }
    }
    CustomPopUp {
        id: popUp
        anchors.centerIn: parent
        width: parent.width * 0.8
    }
    footer: ToolBar {
        RowLayout {
            anchors.fill: parent
            ToolButton {
                action: removeRow
                Layout.alignment: Qt.AlignLeft
                Layout.margins: 5
            }
            ToolButton {
                action: cameraAction
                Layout.alignment: Qt.AlignCenter
                Layout.margins: 5

            }
            ToolButton {
                action: addRow
                Layout.alignment: Qt.AlignRight
                Layout.margins: 5
            }
        }
    }
    Action {
        id: addRow
        icon.source: "qrc:/img/add (2).png"
        onTriggered: popUp.open()
    }
    Action {
        id: removeRow
        icon.source: "qrc:/img/trash.png"
        onTriggered: myModel.removeRow(myModel.getId(list.currentIndex))
    }
    Action {
        id: cameraAction
        icon.source: "qrc:/img/camera.png"
        onTriggered: {
            stack.push("CustomCamera.qml")
        }
    }
}
