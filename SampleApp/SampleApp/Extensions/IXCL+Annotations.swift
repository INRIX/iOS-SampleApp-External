///
/// :header: IXCL+Annotations.swift
///
/// :author: Patrick Winchell
/// :created: 02-27-2017
///
/// :copyright: Copyright (c) 2017 INRIX, Inc.
///
///     INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
///     trademark notice(s) contained herein or in related code, files or
///     documentation shall not be altered and shall be included in all copies and
///     substantial portions of the software. This software is "Sample".
///     Refer to the License.pdf file for your rights to use this software.
///

import Foundation

extension IXCLMapPoint : MKAnnotation {
    public var title: String? { return  CLLocation.ixcl_coordinateString(from: self.coordinate, separator: ", ") }
}

extension IXCLIncident : MKAnnotationWithImage {
    public override var title: String? {
        switch self.type {
        case .accident:
            return "Accident"
        case .congestion:
            return "Congestion"
        case .construction:
            return "Construction"
        case .event:
            return "Event"
        case .fixedCameraTrap:
            return "Fixed Camera Trap"
        case .hazard:
            return "Hazard"
        case .laneClosure:
            return "Lane Closure"
        case .police:
            return "Police"
        case .roadClosure:
            return "Road Closure"
        default:
            break
        }
        return super.title
    }

    public var subtitle: String? {
        if let fullDescription = self.fullDescription?.text {
            return fullDescription
        }
        if let shortDescription = self.shortDescription?.text {
            return shortDescription
        }
        return nil
    }

    var image: UIImage? {
        switch self.type {
        case .accident:
            return #imageLiteral(resourceName: "AccidentPin")
        case .congestion:
            return #imageLiteral(resourceName: "CongestionPin")
        case .construction:
            return #imageLiteral(resourceName: "ConstructionPin")
        case .event:
            return #imageLiteral(resourceName: "EventPin")
        case .fixedCameraTrap:
            return #imageLiteral(resourceName: "CameraPin")
        case .hazard:
            return #imageLiteral(resourceName: "HazardPin")
        case .laneClosure:
            return #imageLiteral(resourceName: "LaneClosurePin")
        case .police:
            return #imageLiteral(resourceName: "PolicePin")
        case .roadClosure:
            return #imageLiteral(resourceName: "RoadClosurePin")
        default:
            break
        }
        return nil
    }
}

extension IXCLParkingLot : MKAnnotationWithImage {
    public override var title: String? { return "Parking Lot" }

    public var subtitle: String? {
        return self.parkingLotName
    }

    var image: UIImage? { return #imageLiteral(resourceName: "ParkingLotPin") }
}

extension IXCLParkingBlock : MKAnnotationWithImage {
    public override var title: String? { return "On-Street Parking" }

    public var subtitle: String? {
        return self.streetName
    }

    var image: UIImage? { return #imageLiteral(resourceName: "ParkingBlockPin") }
}

extension IXCLDangerousSlowdown : MKAnnotationWithImage {
    public override var title: String? { return "Dangerous Slowdown" }
    public var subtitle: String? {
        return self.slowdownDescription?.roadNames?.first as? String
    }

    var image: UIImage? {
        switch self.severity {
        case .severity1:
            return #imageLiteral(resourceName: "SlowdownSev1Pin")
        case .severity2:
            return #imageLiteral(resourceName: "SlowdownSev2Pin")
        case .severity3:
            return #imageLiteral(resourceName: "SlowdownSev3Pin")
        case .severity4:
            return #imageLiteral(resourceName: "SlowdownSev4Pin")
        case .severity5:
            return #imageLiteral(resourceName: "SlowdownSev5Pin")
        default:
            break
        }
        return nil
    }
}

extension IXCLServerCamera : MKAnnotationWithImage {
    public override var title: String? { return "Traffic Camera" }

    public var subtitle: String? { return self.name }

    var image: UIImage? { return #imageLiteral(resourceName: "CameraPin") }
}

extension IXCLGasStation : MKAnnotationWithImage {
    public override var title: String? { return "Gas Station" }

    public var subtitle: String? { return self.brand }

    var image: UIImage? { return #imageLiteral(resourceName: "GasStationPin") }
}
