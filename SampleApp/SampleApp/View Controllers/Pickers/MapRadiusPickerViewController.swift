///
/// :header: MapRadiusPickerViewController.swift
///
/// :author: Patrick Winchell
/// :created: 09-08-2016
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
class MapRadiusPickerViewController: MapViewController {

    init(radius: MKCircle, changeHandler: @escaping (_ newValue: ParamValue) -> Void) {
        super.init(nibName: nil, bundle: nil)
        self.radius = radius
        self.changeHandler = changeHandler
    }

    required init?(coder aDecoder: NSCoder) {
        super.init(coder: aDecoder)
    }

    var radius = MKCircle(center: CLLocationCoordinate2D(latitude: 0, longitude: 0), radius: 100) {
        didSet {
            self.updateOverlay()
            self.changeHandler(self.radius)
        }
    }

    var overlay: MKOverlay?

    var centerAnnotation: BasicAnnotation!
    var radiusAnnotation: BasicAnnotation!

    var annotations = [MKAnnotation]()

    var changeHandler: (_ newValue: ParamValue) -> Void = { _ in }

    override func viewDidLoad() {
        super.viewDidLoad()
        self.updateOverlay()

        let rect = self.radius.boundingMapRect

        self.mapView.visibleMapRect = MKMapRectInset(rect, -rect.size.width / 2, -rect.size.height / 2)
        self.updateAnnotations()
    }

    /// Creates or refreshes the corner annotations.
    func updateAnnotations() {
        if self.annotations.count == 0 {
            let center = BasicAnnotation(coordinate: self.radius.coordinate)
            let radiusCoord = CLLocation.ixcl_offsetCoordinate(from: self.radius.coordinate, distance: self.radius.radius, course: 90)
            let radius = BasicAnnotation(coordinate: radiusCoord)
            let annotations = [center, radius]
            self.mapView.removeAnnotations(self.mapView.annotations)
            self.mapView.addAnnotations(annotations)
            self.annotations = annotations
            self.centerAnnotation = center
            self.radiusAnnotation = radius
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
                let overlay = self.radius
                self.overlay = overlay
                mapView.add(overlay)
            }
        }
    }

    func mapView(_ mapView: MKMapView, rendererForOverlay overlay: MKOverlay) -> MKOverlayRenderer {
        if let overlay = overlay as? MKCircle {
            let renderer = MKCircleRenderer(circle: overlay)
            renderer.fillColor = UIColor(red: 0, green: 0, blue: 1.0, alpha: 0.25)
            return renderer
        }
        return MKOverlayRenderer(overlay: overlay)
    }

    static var centerAnnotationImage: UIImage = {
        let rect = CGRect(x: 0, y: 0, width: 30, height: 30)
        UIGraphicsBeginImageContextWithOptions(rect.size, false, 0)
        UIColor(white: 0.0, alpha: 0.25).setFill()
        UIBezierPath(ovalIn: rect).fill()
        let image: UIImage = UIGraphicsGetImageFromCurrentImageContext()!
        UIGraphicsEndImageContext()
        return image
    }()

    static var annotationImage: UIImage = {
        let rect = CGRect(x: 0, y: 0, width: 30, height: 30)
        UIGraphicsBeginImageContextWithOptions(rect.size, false, 0)
        UIColor(white: 1.0, alpha: 0.9).setFill()
        UIBezierPath(ovalIn: rect).fill()
        let image: UIImage = UIGraphicsGetImageFromCurrentImageContext()!
        UIGraphicsEndImageContext()
        return image
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
        pin.image = annotation === self.centerAnnotation ? MapRadiusPickerViewController.centerAnnotationImage : MapRadiusPickerViewController.annotationImage
        return pin
    }

    func annotationLocationUpdated(_ newCoordinate: CLLocationCoordinate2D, annotation: MKAnnotation) {
        if annotation === self.centerAnnotation {
            self.radius = MKCircle(center: newCoordinate, radius: self.radius.radius)
            self.radiusAnnotation.coordinate = CLLocation.ixcl_offsetCoordinate(from: self.radius.coordinate, distance: self.radius.radius, course: 90)
            if let radiusAnnotation = self.radiusAnnotation {
                self.mapView.removeAnnotation(radiusAnnotation)
                self.mapView.addAnnotation(radiusAnnotation)
            }
        }

        if annotation === self.radiusAnnotation {
            let distance = CLLocation.ixcl_distance(inMetersBetweenCoordinate: self.radius.coordinate, andCoordinate: newCoordinate)

            self.radius = MKCircle(center: self.radius.coordinate, radius: distance)
        }
    }

    func mapView(_ mapView: MKMapView, didDeselectAnnotationView view: MKAnnotationView) {
        view.isSelected = true // views have to be selected before they can be dragged. This skips that step.
    }

    override func didLongPress(_ mapView: MKMapView, atCoordinate coordinate: CLLocationCoordinate2D) {
        self.radius = MKCircle(center: coordinate, radius: self.radius.radius)
        self.annotations = []
        self.updateAnnotations()
    }
}
