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
// RightF               motor         1               
// RightB               motor         2               
// LeftF                motor         3               
// LeftB                motor         4               
// FlyWheel             motor         5               
// Controller1          controller                    
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

void autonomous(void) {
  /*------MOVEMENT--------*/
  // Stop all motors
  void stops() {
    RightF.stop();
    RightB.stop();
    LeftF.stop();
    LeftB.stop();
    FlyWheel.stop();
  }
  // Stop FlyWheel
  void stopFlyWheel() {
    FlyWheel.stop();
  }
  // goForward, insert speed as percentage, time in seconds
  void goForward(double speed, double time) {
    RightF.spin(forward, speed, pct);
    RightF.spin(forward, speed, pct);
    LeftB.spin(forward, speed, pct);
    LeftF.spin(forward, speed, pct);
    wait(time * 1000, msec);
  }
  // goBackward, insert speed as percentage, time in seconds
  void goBackward(double speed, double time) {
    RightF.spin(reverse, speed, pct);
    RightF.spin(reverse, speed, pct);
    LeftB.spin(reverse, speed, pct);
    LeftF.spin(reverse, speed, pct);
    wait(time * 1000, msec);
  }
  // turnLeft, insert speed as percentage, time in seconds
  void turnLeft(double speed, double time)
  {
    RightF.spin(forward, speed, pct);
    RightF.spin(forward, speed, pct);
    LeftB.spin(reverse, speed, pct);
    LeftF.spin(reverse, speed, pct);
    wait(time * 1000, msec);
  }
  // turnRight, insert speed as percentage, time in seconds
  void turnRight(double speed, double time)
  {
    RightF.spin(forward, speed, pct);
    RightF.spin(forward, speed, pct);
    LeftB.spin(reverse, speed, pct);
    LeftF.spin(reverse, speed, pct);
    wait(time * 1000, msec);
  }
  
  // Pick up disc and store
  void intake() {
    
  }
  // Shoot disc, insert speed as percent, will keep spinning until stopFlyWheel() is called
  void shoot(double speed) {
    FlyWheel.spin(forward, speed, pct);
  }
  
  
  // Autonomous start:
  void run() {
    
  }

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
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

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
