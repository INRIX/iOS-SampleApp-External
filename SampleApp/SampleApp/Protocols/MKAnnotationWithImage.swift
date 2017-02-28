///
/// :header: MKAnnotationWithImage
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

protocol MKAnnotationWithImage : MKAnnotation {
    var image: UIImage? { get }
    var imageOffset: CGPoint { get }
}

extension MKAnnotationWithImage {
    var imageOffset: CGPoint { return CGPoint(x: 0, y: -15) }
}
