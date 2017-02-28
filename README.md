# iOS-SampleApp

This is the sample application for the INRIX SDK.

## Introduction

In this project are a collection of sample actions, each one showcasing a feature of the INRIX SDK. Each sample action takes an array of parameters and uses those parameters to make a request, if the request is successful it will present a view controller with the results.

## Requirements

- Xcode 8
- INRIX SDK
- CocoaPods

## Getting Started

- Open SampleApp.xcworkspace.
- Input your applicationId and applicationKey values for the SDK into the SampleApp/KeysAndSettings.swift file.
- To use the Facebook auth example you must input your facebookApplicationId into SampleApp/KeysAndSettings.swift and set your Facebook url scheme in the info.plist file.
- Build and run.

## Samples actions

- Auth
	- Facebook login.
- Cameras
	- Cameras in box.
	- Cameras in radius.
- Dangerous Slowdowns
	- Dangerous slowdowns in box.
	- Dangerous slowdowns in radius.
- Gas stations
	- Gas stations in box.
	- Gas stations in radius.
- Incidents
	- Incidents in box.
	- Incidents in radius.
	- XDIncidents in box.
	- XDIncidents in radius.
- Parking
	- Parking in box.
	- Parking in radius.
- Routes
	- Find route from points.
- Traffic Tiles
	- Traffic tile for quadkey.
