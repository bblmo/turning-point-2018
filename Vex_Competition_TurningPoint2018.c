#pragma config(Motor,  port1,           rightForwardMotor, tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           frontSideMotor, tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           armMotor,      tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port4,           gunMotor,      tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port5,           clawMotor,     tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port6,           rubberGearMotor, tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port7,           miniWheelMotor, tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port8,           lowerPlatformMotors, tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port9,           rearSideMotor, tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port10,          leftForwardMotor, tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR (Turn                     */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/
#define DEADBAND 10

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks
  // running between Autonomous and Driver controlled modes. You will need to
  // manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task autonomous()
{
	//make the robot flip the flag with the assumption that were staring closer
  // to the flag
  // we are gonna go 47 inchs to the flag
//we are going to move the robot 4263 millaseconds
 motor[rightForwardMotor]=127;
 motor[leftForwardMotor]=127;
 wait1Msec(4263);
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task usercontrol()
{
  // User control code here, inside the loop

  while (true)
  {
    //Left Joystick Y-axis controls Left Forward Motor
  	if(abs(vexRT[Ch3]) > DEADBAND) // If the left joystick is greater than or less than the threshold:
		{
			motor[leftForwardMotor] = (vexRT[Ch3]); // Left Joystick Y value / 2.
		}
		else // If the left joystick is within the threshold:
		{
			motor[leftForwardMotor] = 0; // Stop the left motor (cancel noise)
		}

    //Right Joystick Y-axis controls Right Forward Motor
  	if(abs(vexRT[Ch2]) > DEADBAND) // If the Right joystick is greater than or less than the threshold:
		{
			motor[rightForwardMotor] = (vexRT[Ch2]); // Right Joystick Y value / 2.
		}
		else // If the Right joystick is within the threshold:
		{
			motor[rightForwardMotor] = 0; // Stop the left motor (cancel noise)
		}

	  //Right Joystick X-axis controls Right Forward Motor
  	if(abs(vexRT[Ch1]) > DEADBAND) // If the Right joystick is greater than or less than the threshold:
		{
			motor[frontSideMotor] = (vexRT[Ch1]); // Right Joystick Y value / 2.
		}
		else // If the Right joystick is within the threshold:
		{
			motor[frontSideMotor] = 0; // Stop the left motor (cancel noise)
		}

	  //Right Joystick X-axis controls Right Forward Motor
  	if(abs(vexRT[Ch4]) > DEADBAND) // If the Right joystick is greater than or less than the threshold:
		{
			motor[rearSideMotor] = (vexRT[Ch4]); // Right Joystick Y value / 2.
		}
		else // If the Right joystick is within the threshold:
		{
			motor[rearSideMotor] = 0; // Stop the left motor (cancel noise)
		}

    // Check if button to lift arm is pressed
    if(vexRT[Btn5U]==1)
    {
    	motor[armMotor]=127;
    }
    // Check if button to drop arm is pressed
    else if(vexRT[Btn5D]==1)
    {
      motor[armMotor]=-127;
    }
    // Neither arm button is pressed
    else
    {
    	motor[armMotor]=0;
    }

    // Check if button to turn the claw arm is pressed
    if(vexRT[Btn6U]==1)
    {
    	motor[clawMotor]=127;
    }
    // Check if button to turn the claw the opposite direction is pressed
    else if(vexRT[Btn6D]==1)
    {
      motor[clawMotor]=-127;
    }
    // Neither arm button is pressed
    else
    {
    	motor[clawMotor]=0;
    }

    // Add Code to shoot gun
    // if 8l is pressed then draw back trigger
    if(vexRT[Btn8L]==1)
    {
  		motor[gunMotor]=-127;
		}
  	//if released shoots ball
		else
		{
			motor[gunMotor]=0;
		}

		//press 8u to raise platform
		if(vexRT[Btn8U]==1)
		{
			motor[lowerPlatformMotors]=127;
		}
		//if you are pressing 8d lower the platform
		else if(vexRT[Btn8D]==1)
		{
			motor[lowerPlatformMotors]=-127;
		}
		//if no pressing 8u stop
		else
		{
			motor[lowerPlatformMotors]=0;
		}

		// if pressing 7u move motor forward
		if(vexRT[Btn7U]==1)
		{
			motor[miniWheelMotor]=127;
		}
		//if you are pressing 7D lower the platform
		else if(vexRT[Btn7D]==1)
		{
			motor[miniWheelMotor]=-127;
		}
		//if no pressing 7 button stop
		else
		{
			motor[miniWheelMotor]=0;
		}

		//if pressing 7L spin gear
		if(vexRT[Btn7L]==1)
		{
			motor[rubberGearMotor]=127;
		}
		//if pressing 7R spin gear
		else if(vexRT[Btn7R]==1)
		{
			motor[rubberGearMotor]=-127;
		}
		//if no pressing 7L stop
		else
	  {
			motor[rubberGearMotor]=0;
		}
	}// end of while loop;
}
