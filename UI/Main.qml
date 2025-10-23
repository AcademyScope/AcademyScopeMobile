import QtQuick
import QtQuick.Controls 2.15
import QtQuick.Controls.Material

Window {
    Material.theme: Material.Light
    Material.accent: Material.Blue
    width: 640
    height: 480
    visible: true
    title: qsTr("AcademyScope")

    ComboBox {
        id: universityComboBox
        model: controller.universities
        /*onCurrentIndexChanged: controller.selectUniversity(currentIndex)*/
        x: 95
        y: 24
        width: 316
        height: 33
        editable: true
    }

    ComboBox {
        id: departmentComboBox
        model: controller.departments
        /*onCurrentTextChanged: controller.selectDepartment(currentText)*/
        x: 95
        y: 64
        width: 316
        height: 33
        editable: true
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
}
