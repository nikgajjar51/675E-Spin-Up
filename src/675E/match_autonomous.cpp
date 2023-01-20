#include "main.h"
#include "pros/rtos.h"
#include "pros/rtos.hpp"
const double low_speed_multiplier = .5, normal_speed_multiplier = 1,
             high_speed_multiplier = 2;
const int drive_speed = 70, turn_speed = 40, swerve_speed = 30;
void left_side_autonomous_win_point() {}
void right_side_autonomous_win_point() {
  intake_power(100);
  flywheel_aysnc_pid_control(7200);
  chassis.set_drive_pid(12, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  chassis.set_turn_pid(12.5, turn_speed * normal_speed_multiplier);
  chassis.wait_drive();
  index_count(3);
  pros::delay(500);
  chassis.set_turn_pid(-45, turn_speed * normal_speed_multiplier);
  chassis.wait_drive();
  chassis.set_drive_pid(-17, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  chassis.set_turn_pid(-45, turn_speed * normal_speed_multiplier);
  chassis.wait_drive();
  chassis.set_turn_pid(0, turn_speed * normal_speed_multiplier);
  chassis.wait_drive();
  chassis.set_drive_pid(5, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  intake_power(25);
  pros::delay(500);
  intake_power(0);
  chassis.set_turn_pid(-45, turn_speed * normal_speed_multiplier);
  chassis.wait_drive();
  /*
   *2 preloads*
   go forwards
   turn to goal
   shoot 2
   swerve backwards
   turn rollers for x ms TODO replace with color detection functions
   swerve to 45 degrees
   start intake
   go forwards
   *intake 3*
   stop drive
    */
}
void right_side_1() {
  intake_power(100);
  chassis.set_drive_pid(28, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  chassis.set_turn_pid(-45, turn_speed * normal_speed_multiplier);
  chassis.wait_drive();
  flywheel_aysnc_pid_control(6000);
  chassis.set_drive_pid(40, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  chassis.set_drive_pid(-4, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  chassis.set_turn_pid(-135, turn_speed * low_speed_multiplier);
  chassis.wait_drive();
  intake_power(0);
  chassis.set_drive_pid(8, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  index_count(3);

  pros::delay(1000);
  flywheel_aysnc_pid_control(0);
}
void right_side_2() {
  intake_power(100);
  chassis.set_drive_pid(28, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  chassis.set_turn_pid(-45, turn_speed * normal_speed_multiplier);
  chassis.wait_drive();
  flywheel_aysnc_pid_control(5500);
  chassis.set_drive_pid(40, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  chassis.set_drive_pid(-4, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  chassis.set_turn_pid(-135, turn_speed * low_speed_multiplier);
  chassis.wait_drive();
  intake_power(0);
  chassis.set_drive_pid(5, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  index_count(3);

  chassis.set_drive_pid(-8, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  intake_power(100);
  flywheel_aysnc_pid_control(5000);
  chassis.set_turn_pid(135, turn_speed * normal_speed_multiplier);
  chassis.wait_drive();
  chassis.set_drive_pid(15, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  pros::delay(500);
  chassis.set_drive_pid(-15, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  pros::delay(500);
  chassis.set_drive_pid(-15, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  pros::delay(500);
  intake_power(0);
  chassis.set_turn_pid(45, turn_speed * normal_speed_multiplier);
  chassis.wait_drive();
  index_count(3);
  flywheel_aysnc_pid_control(0);
}
void right_side_3() {}
void right_side_4() {}
void left_side_1() {}
void left_side_2() {}
void left_side_3() {}
void left_side_4() {}