
#include "constants.h"
#include "main.h"
/* Left Side AWP
 * 2 Preloads
 * 8 scored disks, 2 rollers
 */
void left_side_autonomous_win_point() {
  // Start flywheel
  flywheel_power(99);
  // flywheel_aysnc_pid_control(13000);
  // Drive towards the roller
  chassis.set_drive_pid(2, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Spin roller to other color
  intake.move_relative(.75, 600);
  // Wait for roller to spin
  pros::delay(500);
  // Drive away from the roller
  chassis.set_drive_pid(-5, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Turn towards high goal
  chassis.set_turn_pid(-8, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Shoot 2 disks
  index_count(2);
  // Turn towards the 3 stack
  chassis.set_turn_pid(-130, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Go forward to knock over the 3 stack
  chassis.set_drive_pid(35, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Start the intake
  intake_power(100);
  // Go forward to intake the 3 stack
  chassis.set_drive_pid(30, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  // Turn towards the goal
  chassis.set_turn_pid(-42, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Drive towards from the auton line
  chassis.set_drive_pid(-10, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  // Stop the intake
  intake_power(0);
  // Shoot the 3 disks
  index_count(1);
  pros::delay(300);
  index_count(1);
  pros::delay(300);
  index_count(1);
  pros::delay(300);
  // Drive away from the auton line 
  chassis.set_drive_pid(10, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  flywheel_power(0);
  // Start the intake
  intake_power(100);
  // Turn towards the other 3 disks
  chassis.set_turn_pid(-135, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Go forward to intake the 3 disks and approach the roller
  chassis.set_drive_pid(70, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Stop the intake
  intake_power(0);
  // Turn towards the roller
  chassis.set_turn_pid(-90, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Go towards the roller
  chassis.set_drive_pid(5, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  // Spin roller to other color
  intake.move_relative(1, 600);
}
/* Right Side AWP
 * 2 Preloads
 * 5 scored disks, 2 rollers
 */
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
/* Right Side 1
 * No Preloads
 * 3 scored disks, no Rollers
 */
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
/* Right Side 2
 * 2 Preloads
 * 5 scored disks, no rollers
 */
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
/* Right Side 3
 * 2 Preloads
 * 5 scored disks, 1 roller
 */
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
/* Right Side 4
 * 2 Preloads
 * 8 scored disks, 2 rollers
 */
void right_side_4() {}
void left_side_1() {}
void left_side_2() {}
void left_side_3() {}
void left_side_4() {}