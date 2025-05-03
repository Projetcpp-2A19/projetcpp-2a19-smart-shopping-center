import QtQuick 2.9
import QtQuick.Controls 2.2
import QtLocation 5.9
import QtPositioning 5.9

Item {
    id: root
    width: 800
    height: 600

    signal locationSelected(double latitude, double longitude)

    property var events: [
        { nom: "Événement 1", type: "Type 1", latitude: 36.8065, longitude: 10.1815 },
        { nom: "Événement 2", type: "Type 2", latitude: 36.8075, longitude: 10.1825 },
        { nom: "Événement 3", type: "Type 3", latitude: 36.8085, longitude: 10.1835 }
    ]

    Map {
        id: mapView
        anchors.fill: parent
        plugin: Plugin { name: "osm" }
        center: QtPositioning.coordinate(36.8065, 10.1815)
        zoomLevel: 13

        Component.onCompleted: {
            console.log("Map component loaded")
            if (events && events.length > 0) {
                center = QtPositioning.coordinate(events[0].latitude, events[0].longitude)
            }
        }

        MapItemView {
            model: events
            delegate: MapQuickItem {
                coordinate: QtPositioning.coordinate(modelData.latitude, modelData.longitude)
                anchorPoint.x: sourceItem.width/2
                anchorPoint.y: sourceItem.height

                sourceItem: Rectangle {
                    width: 20
                    height: 20
                    radius: width/2
                    color: "lightblue"
                    border.color: "darkblue"
                    border.width: 2

                    Text {
                        anchors.centerIn: parent
                        text: "!"
                        color: "black"
                        font.pixelSize: 12
                        font.bold: true
                    }

                    MouseArea {
                        anchors.fill: parent
                        hoverEnabled: true

                        Rectangle {
                            width: tooltipText.width + 20
                            height: tooltipText.height + 16
                            visible: parent.containsMouse
                            color: "#f0f9ff"
                            border.width: 1
                            border.color: "#2196F3"
                            radius: 6
                            x: parent.width + 5
                            y: -height - 5

                            Text {
                                id: tooltipText
                                x: 10
                                y: 8
                                text: "<b>" + modelData.nom + "</b>\n" + modelData.type
                                font.pixelSize: 12
                                color: "#333333"
                            }
                        }
                    }
                }
            }
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                var coordinate = mapView.toCoordinate(Qt.point(mouseX, mouseY))
                root.locationSelected(coordinate.latitude, coordinate.longitude)
            }
        }
    }

    // Message d'erreur
    Text
    {
        id: errorText
        anchors.centerIn: parent
        color: "red"
        font.pixelSize: 16
        visible: mapView.error !== Map.NoError
        text: "Erreur de chargement de la carte: " + mapView.error
    }
}
