///
/// :header: MapRegionPickerViewController.swift
///
/// :author: Patrick Winchell
/// :created: 09-01-2016
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

/// Picker map displays a rect that the user can drag.
class MapRegionPickerViewController: MapViewController {

    init(region: MKCoordinateRegion, changeHandler: @escaping (_ newValue: ParamValue) -> Void) {
        super.init(nibName: nil, bundle: nil)
        self.region = region
        self.changeHandler = changeHandler
    }

    required init?(coder aDecoder: NSCoder) {
        super.init(coder: aDecoder)
    }

    var region = MKCoordinateRegion() {
        didSet {
            self.updateOverlay()
            self.changeHandler(self.region)
        }
    }

    var overlay: MKPolygon?
    var annotations = [BasicAnnotation]()

    var changeHandler: (_ newValue: ParamValue) -> Void = { _ in }

    override func viewDidLoad() {
        super.viewDidLoad()
        self.updateOverlay()
        let doubleRegion = MKCoordinateRegion(center: self.region.center, span: MKCoordinateSpan(latitudeDelta: self.region.span.latitudeDelta * 2, longitudeDelta: self.region.span.longitudeDelta * 2))
        self.mapView.setRegion(doubleRegion, animated: false)

        self.updateAnnotations()
    }

    /// Creates or refreshes the corner annotations.
    func updateAnnotations() {
        if self.annotations.count == 0 {
            let corners = [self.region.ne, self.region.sw]
            let annotations = corners.map({ return BasicAnnotation(coordinate: $0) })
            self.mapView.removeAnnotations(self.annotations)
            self.mapView.addAnnotations(annotations)
            self.annotations = annotations
        } else {
            self.mapView.removeAnnotations(self.annotations)
            self.mapView.addAnnotations(annotations)
        }

    }

    func updateOverlay() {
        DispatchQueue.main.async {
            if let mapView = self.mapView {
                if let overlay = self.overlay {
                    mapView.remove(overlay)
                }
                let overlay = self.region.polygon
                self.overlay = overlay
                mapView.add(overlay)
            }
        }
    }

    func mapView(_ mapView: MKMapView, rendererForOverlay overlay: MKOverlay) -> MKOverlayRenderer {
        if let overlay = overlay as? MKPolygon {
            let renderer = MKPolygonRenderer(polygon: overlay)
            renderer.fillColor = UIColor(red: 0, green: 0, blue: 1.0, alpha: 0.25)
            return renderer
        }
        return MKOverlayRenderer(overlay: overlay)
    }

    static var annotationImage: UIImage = {
        let rect = CGRect(x: 0, y: 0, width: 40, height: 40)
        UIGraphicsBeginImageContextWithOptions(rect.size, false, 0)
        UIColor(white: 1.0, alpha: 0.9).setFill()
        UIBezierPath(ovalIn: rect).fill()
        let image = UIGraphicsGetImageFromCurrentImageContext()
        UIGraphicsEndImageContext()
        return image ?? UIImage()
    }()

    func mapView(_ mapView: MKMapView, annotationView view: MKAnnotationView, didChangeDragState newState: MKAnnotationViewDragState, fromOldState oldState: MKAnnotationViewDragState) {

        if let annotation = view.annotation {
            self.annotationLocationUpdated(annotation.coordinate, annotation: annotation)
        }

        if newState == .ending {
            self.updateAnnotations()
        }
    }

    func mapView(_ mapView: MKMapView, viewForAnnotation annotation: MKAnnotation) -> MKAnnotationView? {
        if annotation is MKUserLocation {
            return nil
        }
        let pin = VeryDraggableAnnotationView(annotation: annotation, reuseIdentifier: nil, mapView: mapView) {
            [weak self, weak annotation] coordinate in
            if let sannotation = annotation {
                self?.annotationLocationUpdated(coordinate, annotation: sannotation)
            }
        }
        pin.image = MapRegionPickerViewController.annotationImage
        return pin
    }

    func annotationLocationUpdated(_ newCoordinate: CLLocationCoordinate2D, annotation: MKAnnotation) {
        if let index = self.annotations.index(where: { $0 === annotation }) {
            let modIndex = (index + 1) % self.annotations.count
            let modAnnotation = self.annotations[modIndex]
            if let newRegion = MKCoordinateRegion(coordinates: [newCoordinate, modAnnotation.coordinate]) {
                self.region = newRegion
            }
        }
    }

    func mapView(_ mapView: MKMapView, didDeselectAnnotationView view: MKAnnotationView) {
        view.isSelected = true // views have to be selected before they can be dragged. This skips that step.
    }
}
