#include "Robot.h"
#include <frc/livewindow/LiveWindow.h>

void Robot::RobotInit()
{
    subsystem.RobotInit();
    drivebase.RobotInit();
    intake.RobotInit();
    elevator.RobotInit();
}

void Robot::RobotPeriodic()
{
    subsystem.RobotPeriodic(robotData, robotData.subsystemData);
    drivebase.RobotPeriodic(robotData, robotData.drivebaseData);
    intake.RobotPeriodic(robotData, robotData.intakeData);
    elevator.RobotPeriodic(robotData, robotData.elevatorData);
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
    controller.TeleopPeriodic(robotData, robotData.controllerData, robotData.controlData);
}

void Robot::DisabledInit()
{
    subsystem.DisabledInit();
    drivebase.DisabledInit();
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