/*
 * --------------
 * Match Autonomi
 * --------------
 * This file holds all of the code used during the 0:15 minute autonomous
 * period. Specifically, this file has the control values, not nessecarily all
 * the raw values used, any background functions or helper functions like PID's
 * and functions to convert motor voltagee to percent, etc.
 */

/* Includes
 * --------
 * Here, I 'include' any external files header files that we need.y Header
 * files make any function or variable global by finding a function or
 * varibable of the same type and name. In the end, this makes it easier so all
 * of my code does not need to be included in 1 file. In this case, I included
 * all of my files in 1 header file: main.h
 */
#include "main.h"
/* Speeds
 * ------
 * In order to make coding an autonomous easier and more consistent, I use
 * preset integers for my drive speeds. Our chassis is very back-heavy so to
 * avoid having the chassis tip over duing the auton period, we set our normal
 * drive speed as 70. Our turn speed is set to 75 as of right now, and our swerve
 * speed is less in order to minimize inwards tipping while swerving.
 */
const int drive_speed = 70, turn_speed = 75, swerve_speed = 50;
const double low_speed_multiplier = .5, normal_speed_multiplier = 1,
             high_speed_multiplier = 1.7, balls_to_the_walls = 2;

void left_side_autonomous_win_point() {}
void right_side_autonomous_win_point() {
  intake_power(75);
  flywheel_aysnc_pid_control(7000);
  chassis.set_drive_pid(24, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  chassis.set_turn_pid(180, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  chassis.set_drive_pid(-12, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  chassis.set_turn_pid(203, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  index_count(3);
  pros::delay(700);
  intake_power(0);
  chassis.set_turn_pid(135, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  flywheel_aysnc_pid_control(0);
  chassis.set_drive_pid(38, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  chassis.set_turn_pid(180, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  intake_power(25);
  chassis.set_drive_pid(3, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  pros::delay(500);
  intake_power(0);
  chassis.set_drive_pid(-5, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  chassis.set_turn_pid(-45, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  intake_power(100);
  chassis.set_drive_pid(90, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  intake_power(-25);
  chassis.set_drive_pid(40, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  chassis.set_turn_pid(-90, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  chassis.set_drive_pid(10, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  chassis.set_drive_pid(-5, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
}
void right_side_1() {
  intake_power(100);
  chassis.set_drive_pid(28, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  chassis.set_turn_pid(-42, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  flywheel_aysnc_pid_control(7000);
  chassis.set_drive_pid(40, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  chassis.set_drive_pid(-5, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  chassis.set_turn_pid(-135, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  chassis.set_drive_pid(-8, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  intake_power(0);
  index_count(1);
  pros::delay(500);
  index_count(1);
  pros::delay(500);
  index_count(1);
  pros::delay(500);
  index_count(1);
  pros::delay(500);
  flywheel_aysnc_pid_control(0);
}
void right_side_2() {
  intake_power(100);
  chassis.set_drive_pid(28, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  chassis.set_turn_pid(-42, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  flywheel_aysnc_pid_control(7000);
  chassis.set_drive_pid(40, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  chassis.set_drive_pid(-5, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  chassis.set_turn_pid(-135, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  chassis.set_drive_pid(-8, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  intake_power(0);
  index_count(1);
  pros::delay(500);
  index_count(1);
  pros::delay(500);
  index_count(1);
  pros::delay(500);
  index_count(1);
  pros::delay(1000);
  chassis.set_drive_pid(8, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  chassis.set_turn_pid(-42, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  intake_power(-100);
  chassis.set_drive_pid(70, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  chassis.set_turn_pid(-90, turn_speed * high_speed_multiplier);
  intake_power(-25);
  chassis.set_drive_pid(8, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  pros::delay(500);
  intake_power(0);
}
void right_side_3() {
  intake_power(100);
  flywheel_aysnc_pid_control(5500);
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
  flywheel_aysnc_pid_control(0);
  chassis.set_drive_pid(35, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  chassis.set_turn_pid(180, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  chassis.set_drive_pid(6, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  intake_power(-25);
  pros::delay(500);
  intake_power(0);
  chassis.set_drive_pid(-10, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  chassis.set_turn_pid(-45, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  intake_power(100);
  chassis.set_drive_pid(80, drive_speed * normal_speed_multiplier);
  chassis.set_drive_pid(-4, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  chassis.set_turn_pid(-135, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  chassis.set_drive_pid(-8, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  intake_power(0);
  index_count(3);
  pros::delay(1000);
  flywheel_aysnc_pid_control(0);
}
void right_side_4() {}
void left_side_1() {
  intake_power(100);
  pros::delay(500);
  intake_power(0);
  chassis.set_drive_pid(-5, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  chassis.set_turn_pid(-125, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  intake_power(100);
  flywheel_aysnc_pid_control(3000);
  chassis.set_drive_pid(25, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  chassis.set_drive_pid(20, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  chassis.set_turn_pid(-50, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  index_count(3);
  intake_power(0);
}
void left_side_2() {}
void left_side_3() {}
void left_side_4() {}