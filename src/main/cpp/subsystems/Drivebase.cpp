#include "subsystems/Drivebase.h"
#include "RobotData.h"
#include <frc/smartdashboard/SmartDashboard.h>

#define DEAD_ZONE 0.08


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
    if (robotData.controllerData.pLYStick > DEAD_ZONE || robotData.controllerData.pLYStick < -DEAD_ZONE)
    {
        dbL.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, robotData.controllerData.pRYStick * 0.9f);
    }
    else
    {
        dbL.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0);
    }
    if (robotData.controllerData.pRYStick > DEAD_ZONE || robotData.controllerData.pRYStick < -DEAD_ZONE)
    {
        dbR.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, robotData.controllerData.pLYStick * 0.9f);
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
