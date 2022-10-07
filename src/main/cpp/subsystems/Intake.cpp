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
    intakePivot.ConfigSelectedFeedbackSensor(ctre::phoenix::motorcontrol::TalonSRXFeedbackDevice::QuadEncoder);
    intakePivot.SetSelectedSensorPosition(0);
}

void Intake::RobotPeriodic(const RobotData &robotData, IntakeData &subsystemData)
{
    frc::SmartDashboard::PutNumber("pos", intakePivot.GetSelectedSensorPosition());
    if (robotData.controllerData.sRTrigger > 0.1)
    {
        intakeDrive.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0.2);
        //intakePivot.Set(ctre::phoenix::motorcontrol::ControlMode::Position, 100000);
        if (intakeTopDriveDelayCounter == 0)
        {
            intakeTopDrive.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0.2);
        }
        else
        {
            intakeTopDriveDelayCounter++;
        }
    }
    else
    {
        intakeDrive.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0);
        intakeTopDrive.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0);
        //intakePivot.Set(ctre::phoenix::motorcontrol::ControlMode::Position, 0);
        intakeTopDriveDelayCounter = 0;
    }
}