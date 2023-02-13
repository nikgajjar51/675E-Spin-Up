#include "main.h"
Drive chassis({-13, -12, -11}, {19, 18, 17}, 21, 3.25, 600, 1.667);
void initialize() {
  expansion_pneum.set_value(false);
  pros::Task data_export_task(data_export);
  master.clear();
  ez::print_ez_template();
  pros::delay(500);
  chassis.toggle_modify_curve_with_controller(false);
  chassis.set_active_brake(0);
  chassis.set_curve_default(2, 2);
  chassis_default_constants();
  chassis_exit_conditions();
  ez::as::auton_selector.add_autons({
      Auton("Right Side\n2 Preloads\n6 Scored Disks, 1 Roller", right_side_4),
      Auton("No Auton", no_auton),

  });
  chassis.initialize();
  ez::as::initialize();
  ez::as::limit_switch_lcd_initialize(&auton_selector_button);
}
void disabled() { alliance_selector(); }
void competition_initialize() {}
void autonomous() {
  chassis.reset_pid_targets();
  chassis.reset_gyro();
  chassis.reset_drive_sensor();
  chassis.set_drive_brake(E_MOTOR_BRAKE_HOLD);
  ez::as::auton_selector.call_selected_auton();
}
void opcontrol() {
  pros::Task indexer_task(indexer_control);
  pros::Task intake_task(intake_control);
  pros::Task endgame_task(endgame_control);
  pros::Task tongue_task(tongue_control);
  chassis.set_drive_brake(pros::E_MOTOR_BRAKE_COAST);
  flywheel.set_brake_mode(E_MOTOR_BRAKE_COAST);
  intake.set_brake_mode(E_MOTOR_BRAKE_COAST);
  while (true) {
    flywheel_pid_control();
    chassis.arcade_standard(ez::SPLIT);
    pros::delay(ez::util::DELAY_TIME);
  }
}