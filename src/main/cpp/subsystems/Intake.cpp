#include "subsystems/Intake.h"
#include "RobotData.h"
#include <frc/smartdashboard/SmartDashboard.h>

void Intake::RobotInit()
{
    intakePivot.ConfigFactoryDefault();
    intakeDrive.ConfigFactoryDefault();
    intakeTopDrive.ConfigFactoryDefault();

    intakePivot.Config_kP(0, 0.0075);
    intakePivot.Config_kD(0, 0.01);
    intakePivot.ConfigPeakOutputForward(0.6);
    intakePivot.ConfigPeakOutputReverse(-0.6);
    // intakePivot.ConfigContinuousCurrentLimit(15);
    // intakePivot.ConfigPeakCurrentLimit(25);
    // intakePivot.ConfigPeakCurrentDuration(0);
    // intakePivot.EnableCurrentLimit(true);
    intakePivot.ConfigSelectedFeedbackSensor(ctre::phoenix::motorcontrol::TalonSRXFeedbackDevice::QuadEncoder);
    intakePivot.SetSelectedSensorPosition(0);
    intakePivot.SetSensorPhase(true);
}

void Intake::RobotPeriodic(const RobotData &robotData, IntakeData &subsystemData)
{
    if (robotData.controllerData.sRTrigger > 0.1)
    {
        intakeDrive.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0.4);
        intakePivot.Set(ctre::phoenix::motorcontrol::ControlMode::Position, 220000);
        intakeTopDrive.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0);

        intakeTopDriveDelayCounter = 60;
    }
    else
    {
        if (intakeTopDriveDelayCounter == 0) // run intakeTopDrive for a bit after intaking
        {
            intakeTopDrive.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0);
        }
        else
        {
            intakeTopDriveDelayCounter--;
            intakeTopDrive.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0.2);
        }

        intakeDrive.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0);
        intakePivot.Set(ctre::phoenix::motorcontrol::ControlMode::Position, 0);
    }

    if (robotData.controllerData.sRBumper)
    {
        intakeTopDrive.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, -0.4);
    }
    else
    {
        intakeTopDrive.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0);
    }
}