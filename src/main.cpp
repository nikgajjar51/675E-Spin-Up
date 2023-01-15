#include "main.h"

Drive chassis({-13, -12, -11}, {19, 18, 17}, 21, 3.25, 600, 1.667);
void initialize() {
  ez::print_ez_template();
  pros::delay(500);
  chassis.toggle_modify_curve_with_controller(false);
  chassis.set_active_brake(0.1);
  chassis.set_curve_default(2, 2);
  chassis_default_constants();
  chassis_exit_conditions();
  ez::as::auton_selector.add_autons({});
  chassis.initialize();
  ez::as::initialize();
}
void disabled() {}
void competition_initialize() {}
void autonomous() {
  chassis.reset_pid_targets();
  chassis.reset_gyro();
  chassis.reset_drive_sensor();
  chassis.set_drive_brake(MOTOR_BRAKE_HOLD);
  ez::as::auton_selector.call_selected_auton();
}
void opcontrol() {
  master.clear();
  chassis.set_drive_brake(MOTOR_BRAKE_COAST);
  flywheel.set_brake_mode(MOTOR_BRAKE_COAST);
  intake.set_brake_mode(MOTOR_BRAKE_COAST);
  pros::Task indexer_task(indexer_control);
  pros::Task intake_task(intake_control);
  pros::Task endgame_task(endgame_control);
  pros::Task manual_control_task(manual_control);
  while (true) {
    drive_lock_control();
    flywheel_pid_control();
    op_control_toggle();
    chassis.arcade_standard(ez::SPLIT);
    pros::delay(ez::util::DELAY_TIME);
  }
}