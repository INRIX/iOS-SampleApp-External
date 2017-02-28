///
/// :header: MapAnnotationResultsViewController.swift
///
/// :author: Patrick Winchell
/// :created: 08-30-2016
///
/// :copyright: Copyright (c) 2016 INRIX, Inc.
///
///     INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
///     trademark notice(s) contained herein or in related code, files or
///     documentation shall not be altered and shall be included in all copies and
///     substantial portions of the software. This software is "Sample".
///     Refer to the License.pdf file for your rights to use this software.
///

import Foundation

/// Results map that displays basic annotations.
class MapAnnotationResultsViewController: MapViewController {

    init(annotations: [MKAnnotation] = [], overlays: [MKOverlay] = []) {
        super.init(nibName: nil, bundle: nil)
        self.annotations = annotations
        self.overlays = overlays
        self.tabBarItem = UITabBarItem(title: "Map", image: nil, tag: 0)
        self.title = "Map"
    }

    required init?(coder aDecoder: NSCoder) {
        super.init(coder: aDecoder)
    }

    var annotations = [MKAnnotation]()
    var overlays = [MKOverlay]()

    var changeHandler: (_ newValue: ParamValue) -> Void = { _ in }

    override func viewDidLoad() {
        super.viewDidLoad()
        self.updateAnnotations()

        // Figure out the bounding box for the annotations.
        var coordinates = self.annotations.map { $0.coordinate }
        if let first = self.overlays.first {
            let rect = self.overlays.map({ $0.boundingMapRect }).reduce(first.boundingMapRect, { MKMapRectUnion($0.0, $0.1) })
            let region = MKCoordinateRegionForMapRect(rect)
            coordinates.append(region.nw)
            coordinates.append(region.se)
        }

        let latitudes = coordinates.map { $0.latitude }
        let longitudes = coordinates.map { $0.longitude }

        if let minLat = latitudes.min(),
            let maxLat = latitudes.max(),
            let minLon = longitudes.min(),
            let maxLon = longitudes.max() {
            let firstPoint = MKMapPointForCoordinate(CLLocationCoordinate2D(latitude: minLat, longitude: minLon))
            let secondPoint = MKMapPointForCoordinate(CLLocationCoordinate2D(latitude: maxLat, longitude: maxLon))

            let visibleRect = MKMapRect(origin: MKMapPoint(x: min(firstPoint.x, secondPoint.x), y: min(firstPoint.y, secondPoint.y)),
                                        size: MKMapSize(width: abs(secondPoint.x - firstPoint.x), height: abs(secondPoint.y - firstPoint.y)))

            if (visibleRect.size.width > 0) || (visibleRect.size.height > 0) {
                let topOffset = self.navigationController?.navigationBar.frame.height ?? 44
                let bottomOffset = self.tabBarController?.tabBar.frame.height ?? 44
                self.mapView.setVisibleMapRect(visibleRect, edgePadding: UIEdgeInsets(top: 52 + topOffset, left: 18, bottom: 10 + bottomOffset, right: 18), animated: false)
            } else {
                self.mapView.centerCoordinate = CLLocationCoordinate2D(latitude: (minLat + maxLat) / 2, longitude: (minLon + maxLon) / 2)
            }
        }
    }

    func mapView(_ mapView: MKMapView, viewFor annotation: MKAnnotation) -> MKAnnotationView? {
        if let annotation = annotation as? MKAnnotationWithImage {
            let view = MKAnnotationView(annotation: annotation, reuseIdentifier: nil)
            view.image = annotation.image
            view.centerOffset = annotation.imageOffset
            view.canShowCallout = true
            return view
        }
        return nil
    }

    func mapView(_ mapView: MKMapView, rendererForOverlay overlay: MKOverlay) -> MKOverlayRenderer {
        if let circle = overlay as? MKCircle {
            return MKCircleRenderer(circle: circle)
        }
        if let route = overlay as? IXCLRoute {
            let renderer = MKPolylineRenderer(polyline: route.polyline)
            renderer.strokeColor = UIColor(red: 0.25, green: 0.25, blue: 1.0, alpha: 0.75)
            if let index = self.overlays.index(where: { $0 === overlay }) {
                renderer.strokeColor = UIColor(hue: fmod((CGFloat(index) * 50.0 / 360.0) + 0.25, 1.0), saturation: 0.9, brightness: 0.75, alpha: 0.75)
            }
            return renderer
        }

        return MKOverlayRenderer(overlay: overlay)
    }

    func updateAnnotations() {
        if let mapView = self.mapView {
            mapView.removeAnnotations(mapView.annotations)
            mapView.addAnnotations(self.annotations)
            mapView.removeOverlays(mapView.overlays)
            mapView.addOverlays(self.overlays)
        }
    }
}

extension IXCLRoute : MKOverlay {
    public var coordinate: CLLocationCoordinate2D {
        return self.polyline.coordinate
    }

    public var boundingMapRect: MKMapRect {
        return self.polyline.boundingMapRect
    }

    var polyline: MKPolyline {
        var coordinates = [CLLocationCoordinate2D]()

        if let points = self.points {
            coordinates = points.flatMap({ $0 as? IXCLMapPoint}).map({ $0.coordinate })
        }

        return MKPolyline(coordinates: &coordinates, count: coordinates.count)
    }
}
