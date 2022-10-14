#pragma once

#include "Constants.h"
#include <ctre/Phoenix.h>
#include <ctre/phoenix/sensors/CANCoder.h>
#include <frc/Compressor.h>
#include <frc/Solenoid.h>
#include <frc/DoubleSolenoid.h>

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
    ctre::phoenix::motorcontrol::can::VictorSPX intakeTopDrive{intakeTopDriveDeviceID};
    frc::Compressor compressor{0, frc::PneumaticsModuleType::CTREPCM};
    frc::Solenoid extenderSolenoid{frc::PneumaticsModuleType::CTREPCM, intakeExtenderDeviceID};
    frc::DoubleSolenoid clawSolenoid{frc::PneumaticsModuleType::CTREPCM, intakeClawInDeviceID, intakeClawOutDeviceID};

    int intakeTopDriveDelayCounter;
};