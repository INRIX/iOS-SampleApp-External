///
/// :header: VeryDraggableAnnotationView.swift
///
/// :author: Patrick Winchell
/// :created: 09-09-2016
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

/// Annotation view that calls an update handler as it is moved.
class VeryDraggableAnnotationView: MKAnnotationView {

    weak var mapView: MKMapView?
    var updateHandler: (CLLocationCoordinate2D) -> Void = { _ in}

    override var center: CGPoint {
        didSet {
            if self.dragState != .none {
                self.update()
            }
        }
    }

    convenience init(annotation: MKAnnotation?, reuseIdentifier: String?, mapView: MKMapView, updateHandler: @escaping (CLLocationCoordinate2D) -> Void) {
        self.init(annotation: annotation, reuseIdentifier: reuseIdentifier)
        self.mapView = mapView
        self.updateHandler = updateHandler
    }

    override init(annotation: MKAnnotation?, reuseIdentifier: String?) {
        super.init(annotation: annotation, reuseIdentifier: reuseIdentifier)
        self.isDraggable = true
        self.canShowCallout = false
        self.isSelected = true // views have to be selected before they can be dragged. This skips that step.
    }

    required init?(coder aDecoder: NSCoder) {
        super.init(coder: aDecoder)
        self.isDraggable = true
        self.canShowCallout = false
        self.isSelected = true // views have to be selected before they can be dragged. This skips that step.
    }

//    override init(frame: CGRect) {
//        super.init(frame: frame)
//    }

    override func setDragState(_ newDragState: MKAnnotationViewDragState, animated: Bool) {
        super.setDragState(newDragState, animated: false)

        if newDragState == .none || newDragState == .ending {
            self.isSelected = true // views have to be selected before they can be dragged. This skips that step.
        }
    }

    /// Since there is no 'annotationWasDragged' method this updates the annotation's location
    /// as it is being dragged.
    func update() {
        if let mapView = self.mapView {
            let point = CGPoint(x: self.frame.midX, y: self.frame.midY)
            let coord = mapView.convert(point, toCoordinateFrom: mapView)
            if let annotation = self.annotation as? BasicAnnotation {
                annotation.coordinate = coord
            }
            self.updateHandler(coord)
        }
    }
}
