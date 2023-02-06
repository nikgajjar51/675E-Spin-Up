#include "main.h"

Drive chassis({-13, -12, -11}, {19, 18, 17}, 21, 3.25, 600, 1.667);
void initialize() {
  expansion_pneum.set_value(false);
  master.clear();
  ez::print_ez_template();
  pros::delay(500);
  chassis.toggle_modify_curve_with_controller(false);
  chassis.set_active_brake(00);
  chassis.set_curve_default(8, 8);
  chassis_default_constants();
  chassis_exit_conditions();
  ez::as::auton_selector.add_autons({
      Auton("Programming Skills\n Left Side", programming_skills),
      // Auton("Programming Skills 2\n Left Side", programming_skills_2),
      // Auton("Right Side\nAWP/n 2 Preloads", right_side_autonomous_win_point),
      Auton("Left Side\nAWP/n 2 Preloads", left_side_autonomous_win_point),
      Auton("Right Side\nNo Preloads\n3 Scored Disks", right_side_1),
      Auton("Right Side\nNo Preloads\n3 Scored Disks", right_side_2),
      Auton("Right Side\n2 Preloads\n5 Scored Disks", right_side_3),
      Auton("Left Side\n0 Preloads\n6 Scored Disks\n2 Rollers", left_side_4),
  });
  chassis.initialize();
  ez::as::initialize();
  //ez::as::limit_switch_lcd_initialize(&auton_selector_button);
}
void disabled() {}
void competition_initialize() {}
void autonomous() {
  master.clear();
  pros::Task controller_data_export_task(controller_data_export);
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
  pros::Task controller_data_export_task(controller_data_export);
  chassis.set_drive_brake(pros::E_MOTOR_BRAKE_COAST);
  flywheel.set_brake_mode(E_MOTOR_BRAKE_COAST);
  intake.set_brake_mode(E_MOTOR_BRAKE_COAST);
  while (true) {
    flywheel_pid_control();
    chassis.arcade_standard(ez::SPLIT);
    pros::delay(ez::util::DELAY_TIME);
  }
}