/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Motor1               motor         1               
// Motor2               motor         2               
// Motor3               motor         3               
// Controller1          controller                    
// Motor4               motor         4               
// Motor5               motor         5               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

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

//(motor).setTimeout(time,seconds);
//hey this is from online
//total: 5 sec
void autonomous(void) {

//this section to-
Motor1.setTimeout(2,seconds);
Motor3.setTimeout(2,seconds);

Motor1.setVelocity(50,percent);
Motor3.setVelocity(50,percent);

  Motor1.startRotateFor(vex::directionType::fwd,500, vex::rotationUnits::deg);
  Motor3.startRotateFor(vex::directionType::fwd,500, vex::rotationUnits::deg);

  Motor1.setPosition(0,degrees);
  Motor3.setPosition(0,degrees);

Motor1.setTimeout(2,seconds);
Motor3.setTimeout(2,seconds);
//-this section is only 2 sec

//this section to-
Motor2.setTimeout(2,seconds);

Motor2.setVelocity(50,percent);

  Motor2.startRotateFor(vex::directionType::fwd,500, vex::rotationUnits::deg);

  Motor2.setPosition(0,degrees);

Motor2.setTimeout(2,seconds); //try nand see whether its before of after
//-this section is only 2 sec
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

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    //for the wheel not next to the brain
    Motor3.spin(directionType::fwd,Controller1.Axis3.position() , percentUnits::pct);
    
    //this is for the wheel closest to the brain
    Motor1.spin(directionType::fwd,Controller1.Axis2.position() , percentUnits::pct);

     //yk the backwheel, well this garb is for that so mess with this if this doesnt work first go
    if(Controller1.ButtonR1.pressing())
    {
      Motor2.spin(vex::directionType::fwd, 200, vex::velocityUnits::pct);
    }
     else if(Controller1.ButtonL1.pressing())
    {
      Motor2.spin(vex::directionType::rev, 200, vex::velocityUnits::pct);
    }
    else
    {
      Motor2.stop();
    }
    //should dedicate this section to the arm right? if there are the supposed to be a max of 8 servos


    //arm code sorta
    if(Controller1.ButtonDown.pressing())
    {
      Motor4.spin(vex::directionType::fwd, 30, vex::velocityUnits::pct);
    }
     else if(Controller1.ButtonUp.pressing())
    {
      Motor4.spin(vex::directionType::rev, 30, vex::velocityUnits::pct);
    }
    else
    {
      Motor4.stop();
    }

    //CLAW CODE BABY... maybe :D
     if(Controller1.ButtonLeft.pressing())
    {
      Motor5.spin(vex::directionType::fwd, 30, vex::velocityUnits::pct);
    }
     else if(Controller1.ButtonRight.pressing())
    {
      Motor5.spin(vex::directionType::rev, 30, vex::velocityUnits::pct);
    }
    else
    {
      Motor5.stop();
    }
    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
