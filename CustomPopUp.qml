import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.3

Popup {
    id: popUp
    ColumnLayout {
        width: parent.width
        TextField {
            id: titleInput
            Layout.fillWidth: true
            placeholderText: "Tiêu đề"

        }
        TextField {
            id: noteInput
            Layout.fillWidth: true
            placeholderText: "Nội dung"

        }
        Button {
            Layout.alignment: Qt.AlignHCenter
            text: "OK"

            onClicked: {
                myModel.addRow(titleInput.text, noteInput.text)
                popUp.close()
            }
        }
    }
}

