#pragma once

#include "Constants.h"
#include <ctre/Phoenix.h>



struct RobotData;

struct ElevatorData 
{

};

class Elevator
{
public:
    void RobotInit();
    void RobotPeriodic(const RobotData &robotData, ElevatorData &elevatorData);  
    void DisabledPeriodic(const RobotData &robotData, ElevatorData &elevatorData); 
    void SemiAuto(const RobotData &robotData, ElevatorData &elevatorData);
    void UpdateData(const RobotData &robotData, ElevatorData &elevatorData);
    void Manual(const RobotData &robotData, ElevatorData &elevatorData);
    void DisabledInit();
private: 
    ctre::phoenix::motorcontrol::can::TalonSRX elevatorDrive {intakeElevatorDriveDeviceID};  
};