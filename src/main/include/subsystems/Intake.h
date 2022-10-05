#pragma once

#include "Constants.h"
#include <ctre/Phoenix.h>
#include <ctre/phoenix/sensors/CANCoder.h>

struct RobotData;

struct IntakeData
{

};

class Intake
{
public:
    void RobotInit();
    void RobotPeriodic(const RobotData &robotData, IntakeData &subsystemData);  
    void DisabledPeriodic(const RobotData &robotData, IntakeData &subsystemData); 
    void DisabledInit();

private:
    ctre::phoenix::motorcontrol::can::VictorSPX intakeDrive{intakeDriveDeviceID};
    ctre::phoenix::motorcontrol::can::TalonSRX intakePivot{intakePivotDeviceID};
};