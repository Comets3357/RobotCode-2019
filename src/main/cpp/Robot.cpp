#include "Robot.h"
#include <frc/livewindow/LiveWindow.h>

void Robot::RobotInit()
{
    subsystem.RobotInit();
}

void Robot::RobotPeriodic()
{
    subsystem.RobotPeriodic(robotData, robotData.subsystemData);
}

void Robot::AutonomousInit()
{
    
}

void Robot::AutonomousPeriodic()
{
    
}

void Robot::TeleopInit()
{
    
}

void Robot::TeleopPeriodic()
{
    
}

void Robot::DisabledInit()
{
    subsystem.DisabledInit();
}

void Robot::DisabledPeriodic() 
{
    subsystem.DisabledPeriodic(robotData, robotData.subsystemData);
}


void Robot::TestInit(){
    frc::LiveWindow::SetEnabled(false); // to block their weird dashboard thing

}

//BENCH TEST CODE
void Robot::TestPeriodic(){
    
}

#ifndef RUNNING_FRC_TESTS
int main()
{
    return frc::StartRobot<Robot>();
}
#endif