import QtQuick
import QtQuick.Controls
import QtQuick.Dialogs

ApplicationWindow {
    visible: true
    id: window
    width: 450
    height: 500

    minimumWidth: 450
    minimumHeight: 500
    
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
            documentEditorDlg.open()
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
            documentEditorDlg.open()
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
        resizableColumns: false
        resizableRows: false

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
            implicitHeight: 20
            // Попытка динамически подгонять ширину под внутренности. TODO Вместо второго числа хорошо бы подставить ширину заголовка
            implicitWidth: Math.max(textCell.implicitWidth * 1.2, 200)

            border.color: "black"
            MouseArea {
                    anchors.fill: parent
                    onClicked: { 
                    tableView.selectionModel.clearSelection()
                    tableView.selectionModel.select(tableView.model.index(index, 0),
                                                ItemSelectionModel.Select)
                    }
            }

            required property bool selected
            color: selected ? "blue" : "lightgray"
            Text {
                id: textCell
                text: TableDataRole
            }
        }
    }

    Dialog {
        id: documentEditorDlg
        objectName: "documentEditorDlg"
        title: "Создание документа"
        standardButtons: Dialog.Save | Dialog.Cancel
        width: 320
        height: 300
        visible: false
        modal: true
        closePolicy: Popup.NoAutoClose

        Connections{
            target: docEditorModel
        }

        anchors{
             centerIn: parent
        }

        onOpened: {
            textInput.text = docEditorModel.getCurrentName();
            comboBox.currentIndex = comboBox.indexOfValue(docEditorModel.getCurrentType());
            timeInput.text = docEditorModel.getCurrentTimeCreated();
        }
        onAccepted: {
            docViewerModel.applyChangesDocumentEditor(textInput.text, comboBox.currentText,
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
            font.pixelSize: 12
        }
    }
}
