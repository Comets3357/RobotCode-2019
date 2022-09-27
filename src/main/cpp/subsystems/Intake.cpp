#include "subsystems/Intake.h"
#include "RobotData.h"
#include <frc/smartdashboard/SmartDashboard.h>

void Intake::RobotInit()
{
    intakePivot.ConfigFactoryDefault();
    intakeDrive.ConfigFactoryDefault();
}

void Intake::RobotPeriodic(const RobotData &robotData, IntakeData &subsystemData)
{
    if (robotData.controllerData.sRTrigger)
    {
        intakeDrive.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0.5);
    }
    else
    {
        intakeDrive.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0);
    }
}