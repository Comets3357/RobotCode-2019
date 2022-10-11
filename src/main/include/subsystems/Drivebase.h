#pragma once

#include "Constants.h"
#include <ctre/Phoenix.h>



struct RobotData;

struct DrivebaseData 
{

};

class Drivebase 
{
public:
    void RobotInit();
    void RobotPeriodic(const RobotData &robotData, DrivebaseData &subsystemData);  
    void DisabledPeriodic(const RobotData &robotData, DrivebaseData &subsystemData);
    void UpdateData(const RobotData &robotData, DrivebaseData &elevatorData);
    void DisabledInit();
private:
    ctre::phoenix::motorcontrol::can::TalonSRX dbL{leftLeadDeviceID};
    ctre::phoenix::motorcontrol::can::TalonSRX dbR{rightLeadDeviceID}; 
    ctre::phoenix::motorcontrol::can::TalonSRX dbLF{leftFollowDeviceID}; 
    ctre::phoenix::motorcontrol::can::TalonSRX dbRF{rightFollowDeviceID};  
};