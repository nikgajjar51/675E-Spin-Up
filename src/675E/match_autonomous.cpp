#include "main.h"
void left_side_autonomous_win_point() {
  // Start the flywheel
  flywheel_async_pid_control(9000);
  // Drive towards the roller
  chassis.set_drive_pid(6, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Spin the roller
  // Drive awat from the roller
  chassis.set_drive_pid(-6, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Turn towards the other roller
  chassis.set_turn_pid(-135, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Start the intake (to block disks from being intook)
  intake_power(-100);
  // Drive forward halfway to the field
  chassis.set_drive_pid(45, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Turn to the high goal
  chassis.set_turn_pid(-45, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Shoot the 2 preloads
  auton_index_count(2);
  flywheel_async_pid_control(0);
  // Turn towards the other roller
  chassis.set_turn_pid(-135, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Intake the 2 disks
  intake_power(100);
  // Drive towards the other roller
  chassis.set_drive_pid(45, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Turn towards the roller
  chassis.set_turn_pid(-90, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Drive towards the roller
  chassis.set_drive_pid(6, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Spin the roller
  // Drive awat from the roller
  chassis.set_drive_pid(-6, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
}
void right_side_autonomous_win_point() {}
void right_side_1() {
  intake_power(100);
  chassis.set_drive_pid(28, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  chassis.set_turn_pid(-42, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  flywheel_async_pid_control(7000);
  chassis.set_drive_pid(45, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  chassis.set_drive_pid(-10, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  chassis.set_turn_pid(-140, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  chassis.set_drive_pid(-8, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  auton_index_count(3);
  intake_power(0);
  flywheel_async_pid_control(0);
}
void right_side_2() {
  intake_power(100);
  chassis.set_drive_pid(28, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  chassis.set_turn_pid(135, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  chassis.set_drive_pid(35, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  chassis.set_turn_pid(180, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  chassis.set_drive_pid(6, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  intake_power(-25);
  pros::delay(200);
  intake_power(0);
  flywheel_async_pid_control(9500);
  chassis.set_drive_pid(-6, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  chassis.set_turn_pid(-45, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  intake_power(100);
  chassis.set_drive_pid(70, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  chassis.set_drive_pid(-4, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  chassis.set_turn_pid(-135, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  auton_index_count(3);
  intake_power(0);
  flywheel_async_pid_control(0);
}
void right_side_3() {
  intake_power(100);
  flywheel_async_pid_control(11000);
  chassis.set_drive_pid(28, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  chassis.set_turn_pid(200, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  auton_index_count(3);
  intake_power(0);
  flywheel_async_pid_control(0);
  chassis.set_turn_pid(135, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  chassis.set_drive_pid(35, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  chassis.set_turn_pid(180, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  chassis.set_drive_pid(6, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  intake_power(-25);
  pros::delay(200);
  intake_power(0);
  flywheel_async_pid_control(7500);
  chassis.set_drive_pid(-6, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  chassis.set_turn_pid(-48, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  intake_power(100);
  chassis.set_drive_pid(70, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  chassis.set_drive_pid(-4, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  chassis.set_turn_pid(-135, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  auton_index_count(3);
  intake_power(0);
  flywheel_async_pid_control(0);
}
void right_side_4() {
  intake_power(100);
  flywheel_async_pid_control(11000);
  chassis.set_drive_pid(28, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  chassis.set_turn_pid(200, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  auton_index_count(3);
  intake_power(0);
  chassis.set_turn_pid(-42, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  flywheel_async_pid_control(7000);
  chassis.set_drive_pid(45, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  chassis.set_drive_pid(-10, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  chassis.set_turn_pid(-140, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  chassis.set_drive_pid(-8, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  auton_index_count(3);
  intake_power(0);
  flywheel_async_pid_control(0);
}
void left_side_1() {}
void left_side_2() {}
void left_side_3() {}
void left_side_4() {}
void no_auton() {}