#include "main.h"
Drive chassis (
  // Left Chassis Ports (negative port will reverse it!)
  {2,3,4}
  // Right Chassis Ports (negative port will reverse it!)
  ,{10,9,8}
  // IMU Port
  ,7
  // Wheel Diameter
  ,3.25
  // Cartridge RPM
  ,600
  // External Gear Ratio (MUST BE DECIMAL)
  ,1.66
);
void initialize() {
  ez::print_ez_template();
  pros::delay(500); // Stop the user from doing anything while legacy ports configure.
  chassis.toggle_modify_curve_with_controller(false); // Enables modifying the controller curve with buttons on the joysticks
  chassis.set_active_brake(0.1); // Sets the active brake kP. We recommend 0.1.
  chassis.set_curve_default(1, 1); // Defaults for curve. If using tank, only the first parameter is used. (Comment this line out if you have an SD card!)  
  default_constants(); // Set the drive to your own constants from autons.cpp!
  ez::as::auton_selector.add_autons({
    Auton("Example Drive\n\nDrive forward and come back.", drive_example),
    Auton("Squiggles", squiggles),
  });
  chassis.initialize();
  ez::as::initialize();
}
void disabled() {
}
void competition_initialize() {
}
void autonomous() {
  chassis.reset_pid_targets(); // Resets PID targets to 0
  chassis.reset_gyro(); // Reset gyro position to 0
  chassis.reset_drive_sensor(); // Reset drive sensors to 0
  chassis.set_drive_brake(MOTOR_BRAKE_HOLD); // Set motors to hold.  This helps autonomous consistency.
  ez::as::auton_selector.call_selected_auton(); // Calls selected auton from autonomous selector.
}
void opcontrol() {
  chassis.set_drive_brake(MOTOR_BRAKE_COAST);
  while (true) {
    chassis.arcade_standard(ez::SPLIT); // Standard split arcade
    pros::delay(ez::util::DELAY_TIME); // This is used for timer calculations!  Keep this ez::util::DELAY_TIME
  }
}
