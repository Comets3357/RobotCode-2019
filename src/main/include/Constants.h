#pragma once

// drivebase:
static const int
    leftLeadDeviceID = 5,
    leftFollowDeviceID = 4,
    rightLeadDeviceID = 2,
    rightFollowDeviceID = 1;

//intake:
static const int
    intakePivotDeviceID = 11,
    intakeDriveDeviceID = 12,
    intakeTopDriveDeviceID = 21,
    intakeElevatorDriveDeviceID = 22,
    
    intakeClawInDeviceID = 2,
    intakeClawOutDeviceID = 3,
    intakeExtenderOutDeviceID = 4, //TODO
    intakeExtenderInDeviceID = 1;

//elevator:
static const int
    notElevatorWheelDeviceID = 21,
    elevatorDriveDeviceID = 22;