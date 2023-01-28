#include "main.h"
const double low_speed_multiplier = .5, normal_speed_multiplier = 1,
             high_speed_multiplier = 2;
const int drive_speed = 50, turn_speed = 40, swerve_speed = 30;
void programming_skills_1() {
  intake_power(75);
  flywheel_aysnc_pid_control(4750);
  chassis.set_drive_pid(24, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  chassis.set_turn_pid(180, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  chassis.set_drive_pid(-12, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  chassis.set_turn_pid(203, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  index_count(3);
  pros::delay(700);
  intake_power(0);
  chassis.set_turn_pid(135, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  chassis.set_drive_pid(38, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  chassis.set_turn_pid(180, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  intake_power(25);
  chassis.set_drive_pid(8, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  pros::delay(1000);
  chassis.set_drive_pid(-5, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  chassis.set_turn_pid(-45, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  intake_power(100);
  chassis.set_drive_pid(90, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  intake_power(0);
  chassis.set_turn_pid(55, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  index_count(2);
  chassis.set_turn_pid(-45, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  chassis.set_drive_pid(30, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  intake_power(25);
  chassis.set_turn_pid(-90, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  chassis.set_drive_pid(8, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  pros::delay(1000);
  chassis.set_drive_pid(-5, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
}
void programming_skills_2() {
  turn_roller_to("Red");
  chassis.set_drive_pid(-5, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  chassis.set_turn_pid(-135, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  intake_power(60);
  chassis.set_drive_pid(-20, drive_speed * low_speed_multiplier);
  chassis.wait_drive();
}