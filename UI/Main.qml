import QtQuick
import QtQuick.Controls 2.15
import QtQuick.Controls.Material

Window {
    /*
    Material.theme: Material.Light
    Material.accent: Material.Blue*/
    width: 640
    height: 480
    visible: true
    title: qsTr("AcademyScope")

    ComboBox {
        id: universityComboBox
        model: controller.universities
        x: 95
        y: 24
        width: 240
        height: 33
        editable: true
        onEditTextChanged: controller.setUniversity(editText)
    }

    ComboBox {
        id: departmentComboBox
        model: controller.departments
        /*onCurrentTextChanged: controller.selectDepartment(currentText)*/
        x: 95
        y: 64
        width: 240
        height: 33
        editable: true
        onEditTextChanged: controller.setDepartment(editText)
    }

    Label {
        id: labelUniversity
        x: 23
        y: 32
        text: qsTr("Üniversite")
    }

    Label {
        id: labelDepartment
        x: 23
        y: 72
        text: qsTr("Bölüm")
    }
    ListView {
        id: listView
        x: 8
        y: 120
        width: 337
        height: 320
        spacing:4
        model: ListModel {
            ListElement { name: "Fizik"; score: "380" }
            ListElement { name: "Kimya"; score: "360" }
            ListElement { name: "Biyoloji"; score: "340" }
            ListElement { name: "Matematik"; score: "340" }
            ListElement { name: "Bilgisayar Mühendisliği"; score: "340" }
            ListElement { name: "Tıp"; score: "340" }
        }

        delegate: Rectangle {
                    width: parent.width - 20   // Kenarlardan boşluk
                    height: 65
                    radius: 8
                    color: "#1E1E1E"           // Satır arka planı (açık siyah)
                    anchors.horizontalCenter: parent.horizontalCenter

                    Column {
                        anchors.fill: parent
                        anchors.margins: 12

                        Text {
                            text: name
                            font.pixelSize: 16
                            color: "white"
                            font.bold: true
                            elide: Text.ElideRight
                        }

                        Text {
                            text: score
                            font.pixelSize: 13
                            color: "#AAAAAA"
                        }
                    }

                    MouseArea {
                        anchors.fill: parent
                        onClicked: console.log("Clicked:", name)
                    }
                }
    }

}
