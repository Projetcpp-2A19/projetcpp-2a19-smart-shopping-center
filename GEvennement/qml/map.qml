import QtQuick 2.9
import QtLocation 5.9
import QtPositioning 5.9

Item {
    id: root
    width: parent.width
    height: parent.height

    Plugin {
        id: mapPlugin
        name: "osm"
        
        PluginParameter {
            name: "osm.useragent"
            value: "GEvennement"
        }
    }

    Map {
        id: mapView
        anchors.fill: parent
        plugin: mapPlugin
        center: QtPositioning.coordinate(36.8065, 10.1815)
        zoomLevel: 13
        
        gesture.enabled: true
        gesture.acceptedGestures: MapGestureArea.PinchGesture | MapGestureArea.PanGesture

        MouseArea {
            anchors.fill: parent
            onClicked: {
                var coordinate = mapView.toCoordinate(Qt.point(mouseX, mouseY))
                root.locationSelected(coordinate.latitude, coordinate.longitude)
            }
        }
    }

    signal locationSelected(double latitude, double longitude)

    function centerOnCoordinate(lat, lng) {
        mapView.center = QtPositioning.coordinate(lat, lng)
    }
} 