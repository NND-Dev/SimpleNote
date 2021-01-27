import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.12
import QtGraphicalEffects 1.14
import QtQuick.Layouts 1.3
import QtMultimedia 5.12

ApplicationWindow {
    id: root
    width: 480
    height: 800
    visible: true
    title: qsTr("NND Group")

    Material.primary: Material.DeepOrange

    property var fontSize: Qt.application.font.pixelSize * 1.2

    StackView {
        id: stack
        anchors.fill: parent
        initialItem: MainView {}
    }
}

