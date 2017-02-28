///
/// :header: MapViewController.swift
///
/// :author: Patrick Winchell
/// :created: 08-31-2016
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
class MapViewController: UIViewController, MKMapViewDelegate {

    var mapView: MKMapView!

    override func viewDidLoad() {
        super.viewDidLoad()
        let mapView = MKMapView(frame: self.view.frame)
        mapView.translatesAutoresizingMaskIntoConstraints = true
        self.view.addSubview(mapView)
        self.mapView = mapView
        self.mapView.showsUserLocation = true
        mapView.delegate = self

        let gestureRecognizer = UILongPressGestureRecognizer(target: self, action: #selector(MapViewController.handleLongPress))
        self.mapView.addGestureRecognizer(gestureRecognizer)

        self.navigationItem.rightBarButtonItem = UIBarButtonItem(barButtonSystemItem: .reply, target: self, action: #selector(MapViewController.moveToUserLocation))

    }

    @objc fileprivate func handleLongPress(_ gesture: UILongPressGestureRecognizer) {
        if gesture.state != UIGestureRecognizerState.ended {
            return
        }
        let p = gesture.location(in: self.mapView)

        let newCoordinate = self.mapView.convert(p, toCoordinateFrom: self.mapView)
        self.didLongPress(self.mapView, atCoordinate: newCoordinate)
    }

    @objc fileprivate func moveToUserLocation() {
        if let userLocation = self.mapView.userLocation.location {
            self.mapView.centerCoordinate = userLocation.coordinate
        }
    }

    func didLongPress(_ mapView: MKMapView, atCoordinate coordinate: CLLocationCoordinate2D) {

    }

    deinit {
        self.mapView?.delegate = nil
        self.mapView = nil
    }
}
