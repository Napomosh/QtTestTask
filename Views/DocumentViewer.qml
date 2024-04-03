import QtQuick
import QtQuick.Controls
import Qt.labs.qmlmodels

ApplicationWindow {
    visible: true
    id: window
    width: 1024
    height: 768
    
    
    Button {
        id: createButtonId
        width: 91
        height: 34
        text: qsTr("Добавить")
        anchors{
            left: parent.left
            top: parent.top
            leftMargin: 8
            topMargin: 8
        }
    }
    
    Button {
        id: editButtonId
        width: 91
        height: 34
        text: qsTr("Редактировать")
        anchors{
            left: parent.left
            top: parent.top
            leftMargin: 120
            topMargin: 8
        }
    }
    
    Button {
        id: deleteButtonId
        width: 91
        height: 34
        text: qsTr("Удалить")
        anchors{
            left: parent.left
            top: parent.top
            leftMargin: 232
            topMargin: 8
        }
       onClicked: docViewerModel.deleteCurrentRecord();
    }
    
    Button {
        id: docTypesButtonId
        width: 191
        height: 34
        text: qsTr("Справочник видов документа ")
        anchors{
            left: parent.left
            top: parent.top
            leftMargin: 344
            topMargin: 8
        }
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
            implicitWidth: 100
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
            onSelectedIndexesChanged: docViewerModel.setCurrentIndex(selectedIndexes);
        }

        delegate: Rectangle {
            implicitWidth: 100
            implicitHeight: 20
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
                text: TableDataRole
            }
        }
    }
}
