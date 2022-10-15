#include "main.h"
// Chassis constructor
Drive chassis (
  // Left Chassis Ports (negative port will reverse it!)
  {-15, -16}

  // Right Chassis Ports (negative port will reverse it!)
  ,{6, 5}

  // IMU Port
  ,1

  // Wheel Diameter
  ,3.25

  // Cartridge RPM
  ,600

  // External Gear Ratio (MUST BE DECIMAL)
  ,1.66
);
void initialize() {
  ez::print_ez_template();
  pros::delay(500);
  chassis.toggle_modify_curve_with_controller(false);
  chassis.set_active_brake(0);
  chassis.set_curve_default(0, 0);
  default_constants();
  ez::as::auton_selector.add_autons({
  });
  chassis.initialize();
  ez::as::initialize();
}
void disabled() {
  expansion.set_value(false);
}
void competition_initialize() {
}
void autonomous() {
  chassis.reset_pid_targets();
  chassis.reset_gyro();
  chassis.reset_drive_sensor();
  chassis.set_drive_brake(MOTOR_BRAKE_HOLD); 
  ez::as::auton_selector.call_selected_auton();
}
void opcontrol() {
  chassis.set_drive_brake(MOTOR_BRAKE_COAST);

  while (true) {

    // chassis.tank(); // Tank control
    chassis.arcade_standard(ez::SPLIT); // Standard split arcade
    // chassis.arcade_standard(ez::SINGLE); // Standard single arcade
    // chassis.arcade_flipped(ez::SPLIT); // Flipped split arcade
    // chassis.arcade_flipped(ez::SINGLE); // Flipped single arcade
    pros::delay(ez::util::DELAY_TIME); // This is used for timer calculations!  Keep this ez::util::DELAY_TIME
  }
}
