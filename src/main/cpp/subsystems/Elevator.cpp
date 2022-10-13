#include "subsystems/Elevator.h"
#include "RobotData.h"
#include "frc/smartdashboard/SmartDashboard.h"

void Elevator::RobotInit()
{
    elevatorDrive.Config_kP(0, 1.75);
    elevatorDrive.SetSelectedSensorPosition(0);
    //elevatorDrive.SetSensorPhase(true);
    elevatorDrive.ConfigSelectedFeedbackSensor(ctre::phoenix::motorcontrol::TalonSRXFeedbackDevice::QuadEncoder);
<<<<<<< Updated upstream
    elevatorDrive.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
=======
    elevatorDrive.SetNeutralMode(ctre::phoenix::motorcontrol::Brake);
>>>>>>> Stashed changes
}
void Elevator::RobotPeriodic(const RobotData &robotData, ElevatorData &elevatorData)
{
    UpdateData(robotData, elevatorData);
    if(robotData.controllerData.sLBumper) //  Ball Set Positions
    {
        if(robotData.controllerData.sABtn)
        {
            elevatorDrive.Set(ctre::phoenix::motorcontrol::ControlMode::Position, -1252); // Low
        }
        else if (robotData.controllerData.sXBtn)
        {
            elevatorDrive.Set(ctre::phoenix::motorcontrol::ControlMode::Position, -8600); // Mid (Hendrik)
        }
        else if (robotData.controllerData.sYBtn)
        {
            elevatorDrive.Set(ctre::phoenix::motorcontrol::ControlMode::Position, -15251); // High
        }
        else if (robotData.controllerData.sBBtn)
        {
            elevatorDrive.Set(ctre::phoenix::motorcontrol::ControlMode::Position, 0); // Zero
        }
    }
    if(robotData.controllerData.sRBumper)
    {
        if(robotData.controllerData.sABtn) // Disc Set Positions
        {
            elevatorDrive.Set(ctre::phoenix::motorcontrol::ControlMode::Position, -1670); // Low
        }
        else if (robotData.controllerData.sXBtn)
        {
            elevatorDrive.Set(ctre::phoenix::motorcontrol::ControlMode::Position, -7898); // Mid (Hendrik)
        }
        else if (robotData.controllerData.sYBtn)
        {
            elevatorDrive.Set(ctre::phoenix::motorcontrol::ControlMode::Position, -14900);// High
        }
        else if (robotData.controllerData.sBBtn)
        {
            elevatorDrive.Set(ctre::phoenix::motorcontrol::ControlMode::Position, 0); // Zero
        }
    }
}

void Elevator::Manual(const RobotData &robotData, ElevatorData &elevatorData)
{
    // Manual
}

void Elevator::SemiAuto(const RobotData &robotData, ElevatorData &elevatorData)
{
    // SemiAuto
}

void Elevator::DisabledPeriodic(const RobotData &robotData, ElevatorData &elevatorData)
{
    // Disabled Periodic
}

void Elevator::DisabledInit()
{
    // Disabled Init
}

void Elevator::UpdateData(const RobotData &robotData, ElevatorData &elevatorData)
{
    // Update Data
}
