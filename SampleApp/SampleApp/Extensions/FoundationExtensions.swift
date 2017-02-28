///
/// :header: FoundationExtensions.swift
///
/// :author: Patrick Winchell
/// :created: 02-23-2017
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

extension String {
    func unCamelCaseString() -> String {
        // Use regex to split name at camel casing.
        if let regex = try? NSRegularExpression(pattern: "([a-z])([A-Z])", options: NSRegularExpression.Options(rawValue: 0)) {
            return regex.stringByReplacingMatches(in: self, options: NSRegularExpression.MatchingOptions(rawValue: 0), range: NSRange(location: 0, length: self.unicodeScalars.count), withTemplate: "$1 $2")
        }

        return self
    }

    func titleCasedString() -> String {
        var output: String = ""
        var lastWhiteSpace = true
        for char in self.unicodeScalars {
            let stringed = String(char)
            if lastWhiteSpace == true {
                output += stringed.uppercased()
            } else {
                output += stringed
            }
            lastWhiteSpace = stringed.rangeOfCharacter(from: CharacterSet.whitespacesAndNewlines) != nil
        }
        return output
    }
}
