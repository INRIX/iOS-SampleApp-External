/*
 * @header IXCLEvents.h
 * @abstract Definitions for handling events.
 * @author David Potter
 * @updated 06-03-2015
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

//-----------------------------------------------------------------------------
#pragma mark - Enum Definitions

/*!
 * @abstract Client SDK event codes.
 * @discussion These event codes are used for analytics logging.
 */
typedef NS_ENUM (NSInteger, IXCLClientEventCode)
{
    // Core events
    IXCLEventCoreStarted                          = 1000,
    IXCLEventCoreShutDown                         = 1001,
    IXCLEventCoreServerTimeout                    = 1500,

    // Trip events
    IXCLEventTripStarted                          = 2000,
    IXCLEventTripEnded                            = 2001,
    IXCLEventTripUploadSuccess                    = 2002,
    IXCLEventTripUploadRetry                      = 2003,
    IXCLEventTripUploadFailure                    = 2004,
    IXCLEventTripAgedOff                          = 2005,
    IXCLEventTripPersisted                        = 2006,
    IXCLEventTripExtractorReset                   = 2007,
    IXCLEventTripExtractorRestoreState            = 2008,

    // Application and location state events
    IXCLEventApplicationForegrounded              = 3000,
    IXCLEventApplicationBackgrounded              = 3001,
    IXCLEventSignificantLocationChangeModeStarted = 3002,
    IXCLEventSignificantLocationChangeModeEnded   = 3003,
    IXCLEventLocationStartedInBackground          = 3004,

};