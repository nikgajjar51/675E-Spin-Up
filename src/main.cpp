#include "main.h"
Drive chassis({-13, -12, -11}, {19, 18, 17}, 21, 3.25, 600, 1.667);
void initialize() {
  disabled_data_export_task.suspend();
  driver_data_export_task.suspend();
  intake_task.suspend();
  indexer_task.suspend();
  endgame_task.suspend();
  tongue_task.suspend();
  expansion_pneum.set_value(false);
  master.clear();
  ez::print_ez_template();
  pros::delay(500);
  chassis.toggle_modify_curve_with_controller(false);
  chassis.set_active_brake(0);
  chassis.set_curve_default(8, 8);
  chassis_default_constants();
  chassis_exit_conditions();
  ez::as::auton_selector.add_autons({
      // Auton("Drive Example", drive_example),
      // Auton("Turn Example", turn_example),
      Auton("Left Side AWP/n 2 Preloads", left_side_autonomous_win_point),
      Auton("Right Side AWP/n 2 Preloads", right_side_autonomous_win_point),
      Auton("Programming Skills\n 2 Preloads", programming_skills),
      Auton("Left Side\nNo Preloads\n3 Scored Disks", left_side_1),
      Auton("Left Side\nNo Preloads\n3 Scored Disks", left_side_2),
      Auton("Right Side\nNo Preloads\n3 Scored Disks", right_side_1),
      Auton("Right Side\nNo Preloads\n3 Scored Disks", right_side_2),
  });
  chassis.initialize();
  ez::as::initialize();
  ez::as::limit_switch_lcd_initialize(&auton_selector_button);
}
void disabled() {
  disabled_data_export_task.resume();
  driver_data_export_task.suspend();
  intake_task.suspend();
  indexer_task.suspend();
  endgame_task.suspend();
  tongue_task.suspend();
  driver_selector();
  alliance_selector();
}
void competition_initialize() {}
void autonomous() {
  driver_data_export_task.resume();
  disabled_data_export_task.suspend();
  intake_task.suspend();
  indexer_task.suspend();
  endgame_task.suspend();
  tongue_task.suspend();
  chassis.reset_pid_targets();
  chassis.reset_gyro();
  chassis.reset_drive_sensor();
  chassis.set_drive_brake(E_MOTOR_BRAKE_HOLD);
  ez::as::auton_selector.call_selected_auton();
}
void opcontrol() {
  driver_data_export_task.resume();
  intake_task.resume();
  indexer_task.resume();
  endgame_task.resume();
  tongue_task.resume();
  disabled_data_export_task.suspend();
  chassis.set_drive_brake(pros::E_MOTOR_BRAKE_COAST);
  flywheel.set_brake_mode(E_MOTOR_BRAKE_COAST);
  intake.set_brake_mode(E_MOTOR_BRAKE_COAST);
  while (true) {
    flywheel_pid_control();
    chassis.arcade_standard(ez::SPLIT);
    pros::delay(ez::util::DELAY_TIME);
  }
}