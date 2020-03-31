import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

import tuduweb 1.0

ApplicationWindow {
    visible: true
    width: 1280
    height: 720
    title: qsTr("Scroll")
    font.family: "Microsoft YaHei"

    header: Label {
        text: qsTr("Page 1")
        font.pixelSize: Qt.application.font.pixelSize * 2
        padding: 10

    }

//    Label {
//        text: qsTr("You are on Page 1.")
//        anchors.centerIn: parent
//    }

    ColumnLayout{
        anchors.fill: parent



        RowLayout{
            Layout.fillWidth: true
            Layout.maximumHeight: 400
            Layout.preferredHeight: 300

            Rectangle{
                id: picShow
                Layout.fillWidth: true
                Layout.fillHeight: true

                color: "#ccc"

                Text{
                    anchors.centerIn: parent
                    font.pixelSize: 24
                    text: "indexPicShow"
                }

                PicShow{
                    id: picShowPanel
                    anchors.centerIn: parent
                    width: 400; height: 300
                    name: "A simple pie chart"
                    //这里自动转换为C++中的QColor类型
                    color: "red"
                    uri: "F:/qt/road/podao1.bmp"

                    onColorChanged: {

                    }

                    Text{
                        anchors.centerIn: parent
                        font.pixelSize: 24
                        color: "#FFF"
                        text: "DDD"
                    }

                }

                Behavior on color {
                    ColorAnimation {
                        easing.type: Easing.OutQuad
                        duration: 500
                    }
                }

                DropArea{
                    anchors.fill: parent
//                    onDropped: {
//                        console.log("dropArea has received something:")
//                        console.log(drop.urls)
//                        header.text = drop.urls[0]
//                    }
                    //keys: ["text/plain"]//该字段对应draggable[id]中mimeData //This property holds a list of drag keys a DropArea will accept.
                    onEntered: {
                        picShow.color = "#FCC"
                    }
                    onExited: {
                        picShow.color = "#EEE"//鼠标拖拽退出时恢复常规背景色
                    }
                    onDropped: {//鼠标拖拽完成  释放时触发
                        picShow.color = "#EEE"
                        console.log("drop" + drop);
                        if(drop.hasUrls)
                        {

                            console.log("dropArea has received something:")
                            console.log(drop.urls)
                            header.text = drop.urls[0]
                            picShowPanel.uri = drop.urls[0]
                        }
                        else if (drop.hasText) {//拖拽含有文本字符串
                            if (drop.proposedAction == Qt.MoveAction || drop.proposedAction == Qt.CopyAction) {
                                picShowPanel.color = drop.text//重置当前的颜色
                                header.text = "color" + drop.text
                                drop.acceptProposedAction()//接受目标动作，停止事件传递

                            }
                        }
                    }
                }
            }
        }

        RowLayout{
            id: picShowListPanel
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.maximumWidth: parent.width
            //Layout.minimumHeight: 300

            Repeater{
                id : recRep
                model: 20
                Rectangle{
                    id: item
                    width: 400
                    height: 200
                    //Layout.fillHeight: true
                    color:Qt.rgba(Math.random(), Math.random(), Math.random(), 1)

                    Text{
                        anchors.centerIn: parent
                        font.family: "Microsoft YaHei"
                        font.pixelSize: 24
                        text: index + 1
                    }

                    MouseArea{
                        id: mouseArea
                        anchors.fill: parent
                        drag.target: draggable
                    }

                    Item {
                        id: draggable//
                        anchors.fill: parent
                        Drag.active: mouseArea.drag.active
                        Drag.hotSpot.x: 10//热点位置
                        Drag.hotSpot.y: 10
                        Drag.mimeData: { "text/plain": item.color }//设置拖拽时内部数据,也就是拖拽出的数据类型
                        Drag.dragType: Drag.Automatic//拖拽类型
                        Drag.onDragStarted: {//拖拽开始
                            parent.border.width = 5
                            parent.border.color = "#333"
                        }
                        Drag.onDragFinished: {//拖拽结束  拖拽操作状态为接受
                            parent.border.width = 0
                            parent.border.color = "white"
                            if (dropAction == Qt.MoveAction) {//如果是移动操作，将显示置空
                                //item.display = ""//清空被拖拽文本框
                            }
                        }
                    } // Item

                }


            }
            //on x: because we only change picShowListPanel
            Behavior on x {
                NumberAnimation {
                    easing.type: Easing.Linear
                    duration: 500
                }
            }
        }

        RowLayout{
            Layout.fillHeight: true
            Layout.fillWidth: true
            //Layout.maximumHeight: 20
            Slider{
                //width: parent.width
                Layout.fillHeight: false
                Layout.fillWidth: true
                to: recRep.count - 1
                stepSize: 1.0


                onValueChanged: {
                    picShowListPanel.x = -value * (recRep.itemAt(0).width + picShowListPanel.spacing)
                    console.log(recRep.itemAt(0).width + picShowListPanel.spacing)
                    console.log(picShowListPanel.x)

                    sliderLabel.text = (value + 1) + "/" + recRep.count
                }

                Component.onCompleted: {
                    console.log(parent + "loaded")
                    sliderLabel.text = "1/" + recRep.count
                }
            }

            Label{
                id: sliderLabel
                padding: 10
                font.pixelSize: Qt.application.font.pixelSize * 2
                text : "1/29"
            }


        }

        RowLayout{
            Layout.fillHeight: true
            Layout.fillWidth: true

            Rectangle{
                Layout.fillHeight: true
                Layout.fillWidth: true

                color: "GRAY"

            }
        }

    }


}
