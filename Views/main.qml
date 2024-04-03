/*
 *
 * Created by Napomosh on 1.4.2024
 *
 */

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ApplicationWindow {
    visible: true

    header: ToolBar {
        RowLayout {
            anchors.fill: parent
            Button {
                text: "Create"
                onClicked: model.Revert
            }
            Button {
                text: "Edit"
                onClicked: model.Revert
            }
            Button {
                text: "Delete"
                onClicked: model.Revert
            }
        }
    Grid {
        columns: 3
        spacing: 2
        Rectangle { color: "red"; width: 50; height: 50 }
        Rectangle { color: "green"; width: 20; height: 50 }
        Rectangle { color: "blue"; width: 50; height: 20 }
        Rectangle { color: "cyan"; width: 50; height: 50 }
        Rectangle { color: "magenta"; width: 10; height: 10 }
    }
    }
}