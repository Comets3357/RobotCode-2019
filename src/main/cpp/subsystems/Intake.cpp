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
    intakePivot.SetSensorPhase(true);
    compressor.EnableDigital();
    solenoidExtended = false;
    intakePivotDown = false;
}

void Intake::RobotPeriodic(const RobotData &robotData, IntakeData &subsystemData)
{
    if (solenoidExtended == true)
    {
        if (intakePivotDown == true)
        {
            intakePivot.Set(ctre::phoenix::motorcontrol::ControlMode::Position, 220000);
        }
    }
    else if (solenoidExtended == false)
    {
        intakePivot.Set(ctre::phoenix::motorcontrol::ControlMode::Position, 0);
    }
    if (robotData.controllerData.sRTrigger)
    {
        intakePivotDown = true;
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
        intakePivotDown = false;
    }

    if (robotData.controllerData.sABtn && !robotData.controllerData.sLBumper && !robotData.controllerData.sRBumper)
    {
        intakeTopDrive.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, -0.4);
        intakeDrive.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, -0.4);
    }
    else
    {
        intakeTopDrive.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0);
    }

    if (robotData.controllerData.sLTrigger)
    {
        clawSolenoid.Set(frc::DoubleSolenoid::Value::kForward);
    }
    else if (robotData.controllerData.sXBtn && !robotData.controllerData.sLBumper && !robotData.controllerData.sRBumper)
    {
        extenderSolenoid.Set(frc::DoubleSolenoid::Value::kForward);
        solenoidExtended = !solenoidExtended;
    }
    if (robotData.controllerData.sYBtn && !robotData.controllerData.sLBumper && !robotData.controllerData.sRBumper)
    {
        extenderSolenoid.Set(frc::DoubleSolenoid::Value::kReverse);
        solenoidExtended = !solenoidExtended;
    }
    if (robotData.controllerData.sBBtn && !robotData.controllerData.sLBumper && !robotData.controllerData.sRBumper)
    {
        clawSolenoid.Set(frc::DoubleSolenoid::Value::kReverse);
    }
}