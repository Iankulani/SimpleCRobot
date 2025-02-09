#include "WPILib.h"
#include "SimpleCRobot.h"
static const UINT32 LEFT_MOTOR_PORT = 1; 
static const UINT32 RIGHT_MOTOR_PORT = 2; 
static const UINT32 JOYSTICK_PORT = 1; 
void Initialize(void) 
{ 
 CreateRobotDrive(LEFT_MOTOR_PORT, RIGHT_MOTOR_PORT); 
 SetWatchdogExpiration(0.1); 
} 
void Autonomous(void) 
{ 
 SetWatchdogEnabled(false); 
 Drive(0.5, 0.0); 
 Wait(2.0); 
 Drive(0.0, 0.0); 
} 
void OperatorControl(void) 
{ 
 SetWatchdogEnabled(true); 
 while (IsOperatorControl()) 
 { 
 WatchdogFeed(); 
 ArcadeDrive(JOYSTICK_PORT); 
 } 
} 
START_ROBOT_CLASS(SimpleCRobot);