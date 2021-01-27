import QtQuick 2.0
import QtMultimedia 5.12
import QtQuick.Controls 2.12
Item
{
    Camera {
        id: camera

        exposure.exposureCompensation: -1.0
        exposure.exposureMode: Camera.ExposurePortrait
        flash.mode:  Camera.FlashRedEyeReduction
        imageCapture{
            onImageCaptured: {
                photopreview.source = preview
            }
        }
    }

    VideoOutput {
        anchors.fill: parent
        source: camera
    }

    Rectangle {
        width: 50
        height: 50
        radius: width/2
        color: "red"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        MouseArea {
            anchors.fill: parent
            onClicked: {
                if(camera.imageCapture.ready)
                {
                    camera.imageCapture.capture()
                    camera.imageCapture.captureToLocation(" QStandardPaths :: writeableLocation ( QStandardPaths :: PicturesLocation )")
                }

            }
        }
    }

    Label {
        id: labNote
        visible: false
        text: "Chức năng chưa có sẵn. \nĐang phát triển bởi NND"
    }

    Image {
        id: back
        source: "qrc:/img/undo.png"

        anchors{
            bottom: parent.bottom
            right: parent.right
            rightMargin: 5
            bottomMargin: 5
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                stack.pop()
            }
        }
    }
    Image {
        id: photopreview
    }
}
