#include "subsystems/Drivebase.h"
#include "RobotData.h"
#include <frc/smartdashboard/SmartDashboard.h>


void Drivebase::RobotInit()
{
    dbR.ConfigFactoryDefault();
    dbRF.ConfigFactoryDefault();
    dbL.ConfigFactoryDefault();
    dbLF.ConfigFactoryDefault();
    dbL.SetInverted(true);
    dbR.SetInverted(true);
    dbRF.SetInverted(true);
    dbLF.Follow(dbL);
    dbRF.Follow(dbR);
    
    
}

void Drivebase::RobotPeriodic(const RobotData &robotData, DrivebaseData &subsystemData)
{
    if (robotData.controllerData.pLYStick > 0.08 || robotData.controllerData.pLYStick < -0.08)
    {
        dbL.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, robotData.controllerData.pRYStick * 0.5);
    }
    else
    {
        dbL.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0);
    }
    if (robotData.controllerData.pRYStick > 0.08 || robotData.controllerData.pRYStick < -0.08)
    {
        dbR.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, robotData.controllerData.pLYStick * 0.5);
    }
    else
    {
        dbR.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0);
    } 
}

void Drivebase::DisabledPeriodic(const RobotData &robotData, DrivebaseData &subsystemData)
{

}

void Drivebase::DisabledInit()
{
    dbL.SetNeutralMode(ctre::phoenix::motorcontrol::Coast);
    dbR.SetNeutralMode(ctre::phoenix::motorcontrol::Coast);
    dbLF.SetNeutralMode(ctre::phoenix::motorcontrol::Coast);
    dbRF.SetNeutralMode(ctre::phoenix::motorcontrol::Coast);
}
