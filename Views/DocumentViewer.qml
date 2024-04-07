import QtQuick
import QtQuick.Controls
import QtQuick.Dialogs

ApplicationWindow {
    visible: true
    id: window
    width: 500
    height: 500
    
    
    Button {
        id: createButton
        width: 91
        height: 34
        text: qsTr("Добавить")
        anchors{
            left: parent.left
            top: parent.top
            leftMargin: 8
            topMargin: 8
        }
        onClicked:{
            dialog.open()
        }
    }
    
    Button {
        id: editButton
        width: 91
        height: 34
        text: qsTr("Редактировать")
        enabled: false
        anchors{
            left: parent.left
            top: parent.top
            leftMargin: 120
            topMargin: 8
        }
        onClicked:{
            docEditorModel.receiveDialogParams(docViewerModel.getCurrentDocEntity())
            dialog.open()
        }
    }
    
    Button {
        id: deleteButton
        width: 91
        height: 34
        text: qsTr("Удалить")
        enabled: false
        anchors{
            left: parent.left
            top: parent.top
            leftMargin: 232
            topMargin: 8
        }
       onClicked: docViewerModel.deleteCurrentRecord();
    }

    HorizontalHeaderView {
        id: horizontalHeader
        syncView: tableView

        anchors{
            top: parent.top
            fill: parent
            leftMargin: 8
            topMargin: 45
        }

        delegate: Rectangle {
            implicitWidth: 200
            implicitHeight: 20
            border.color: "black"
            Text {
                text: HeaderRole
                font.weight: Font.Bold
            }
        }
    }

    TableView {
        id: tableView
        columnSpacing: 1
        rowSpacing: 1
        clip: true

        anchors{
            top: horizontalHeader.bottom
            fill: parent
            leftMargin: 8
            topMargin: 65
        }

       model: docViewerModel
       selectionBehavior: TableView.SelectRows
       selectionMode: TableView.SingleSelection

       selectionModel: ItemSelectionModel {
            onSelectedIndexesChanged: {
                docViewerModel.setCurrentIndex(selectedIndexes)
                deleteButton.enabled = tableView.model.hasSelected()
                editButton.enabled = tableView.model.hasSelected()
            }
        }

        delegate: Rectangle {
            implicitWidth: 200
            implicitHeight: 20
            border.color: "black"
            required property bool selected
            MouseArea {
                    anchors.fill: parent
                    onClicked: { 
                    tableView.selectionModel.clearSelection()
                    tableView.selectionModel.select(tableView.model.index(index, 0),
                                                ItemSelectionModel.Select)
                    }
            }

            color: selected ? "blue" : "lightgray"
            Text {
                text: TableDataRole
            }
        }
    }

    Dialog {
        id: dialog
        objectName: "dialog"
        width: 320
        height: 300
        visible: false
        modal: true
        closePolicy: Popup.NoAutoClose

        property bool isEditMode: false

        Connections{
            target: docEditorModel
        }

        anchors{
             centerIn: parent
        }

        title: "Создание документа"
        standardButtons: Dialog.Save | Dialog.Cancel

        onOpened: {
            textInput.text = docEditorModel.getCurrentName();
            comboBox.currentIndex = comboBox.indexOfValue(docEditorModel.getCurrentType());
            timeInput.text = docEditorModel.getCurrentTimeCreated();
        }
        onAccepted: {
            docViewerModel.closeDocumentEditor(textInput.text, comboBox.currentText,
                                        timeInput.text, docEditorModel.getMode())
        }
        onClosed: {
            docEditorModel.resetState()
            tableView.selectionModel.clearSelection()
        }

        Text {
            x: 8
            y: 8
            width: 276
            height: 33
            text: qsTr("Наименование:")
            font.pixelSize: 20
        }
    
        TextField {
            id: textInput
            x: 8
            y: 47
            width: 188
            height: 19
            placeholderText: "Введите наименование"
            font.pixelSize: 12
        }
    
        Text {
            x: 8
            y: 84
            width: 276
            height: 33
            text: qsTr("Вид документа:")
            font.pixelSize: 20
        }
    
        ComboBox {
            id: comboBox
            x: 12
            y: 123
            width: 188
            height: 35

            model: docViewerModel.getDocTypes()
        }

        Text {
            x: 8
            y: 170
            width: 276
            height: 33
            text: qsTr("Дата создания:")
            font.pixelSize: 20
        }
    
        TextField {
            id: timeInput
            x: 8
            y: 205
            width: 188
            height: 19
            inputMask: "99.99.9999 dd:dd"
            text: ""
            font.pixelSize: 12
        }
    }
}
