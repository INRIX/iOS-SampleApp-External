///
/// :header: MapPickerViewController.swift
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

/// Picker map that updates a coordinate on long press.
class MapPickerViewController: MapViewController {

    init(coordinate: CLLocationCoordinate2D, changeHandler: @escaping (_ newValue: ParamValue) -> Void) {
        super.init(nibName: nil, bundle: nil)
        self.coordinate = coordinate
        self.changeHandler = changeHandler
    }

    required init?(coder aDecoder: NSCoder) {
        super.init(coder: aDecoder)
    }

    var coordinate = CLLocationCoordinate2D(latitude: 0, longitude: 0) {
        didSet {
            self.updateAnnotation()
        }
    }

    var changeHandler: (_ newValue: ParamValue) -> Void = { _ in }

    override func viewDidLoad() {
        super.viewDidLoad()
        self.updateAnnotation()
        self.mapView.camera.altitude = 25000
        self.mapView.setCenter(self.coordinate, animated: false)
    }

    func updateAnnotation() {
        if let mapView = self.mapView {
            mapView.removeAnnotations(mapView.annotations)
            mapView.addAnnotation(BasicAnnotation(coordinate: self.coordinate))
        }
    }

    override func didLongPress(_ mapView: MKMapView, atCoordinate coordinate: CLLocationCoordinate2D) {
        self.coordinate = coordinate
        self.changeHandler(coordinate)
    }

    func mapView(_ mapView: MKMapView, annotationView view: MKAnnotationView, didChangeDragState newState: MKAnnotationViewDragState, fromOldState oldState: MKAnnotationViewDragState) {
        if newState == .ending {
            if let annotation = view.annotation {
                let newCoordinate = annotation.coordinate
                self.coordinate = newCoordinate
                self.changeHandler(newCoordinate)
            }
        }
    }

    func mapView(_ mapView: MKMapView, viewForAnnotation annotation: MKAnnotation) -> MKAnnotationView? {
        if annotation is MKUserLocation {
            return nil
        }
        let pin = MKPinAnnotationView(annotation: annotation, reuseIdentifier: "pin")
        pin.isDraggable = true
        return pin
    }
}
