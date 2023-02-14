#include "main.h"
void programming_skills() {
  // Start the flywheel
  intake_power(100);
  flywheel_async_pid_control(9500);
  // Drive towards the roller
  chassis.set_drive_pid(5, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  // TODO - Spin the roller to Red
  // Drive away from the roller
  chassis.set_drive_pid(-6, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Start the intake
  // Turn to face the singular disk
  chassis.set_turn_pid(125, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Drive to intake the disk
  chassis.set_drive_pid(23, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  // Turn to face the roller
  chassis.set_turn_pid(90, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Stop the intake
  // Drive towards the roller
  chassis.set_drive_pid(10, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  // TODO - Spin the roller to Red
  // Drive away from the roller
  chassis.set_drive_pid(-8, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  intake_power(0);
  // Turn to face the high goal
  chassis.set_turn_pid(0, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Drive forward to shoot
  chassis.set_drive_pid(-25, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Shoot 3 disks
  index_count(1);
  pros::delay(250);
  index_count(1);
  pros::delay(250);
  index_count(1);
  pros::delay(500);
  chassis.set_drive_pid(15, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  flywheel_async_pid_control(4000);
  intake_power(100);
  chassis.set_turn_pid(-135, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  chassis.set_drive_pid(75, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  chassis.set_drive_pid(-20, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  chassis.set_turn_pid(-45, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  index_count(1);
  pros::delay(250);
  index_count(1);
  pros::delay(250);
  index_count(1);
  pros::delay(500);
  chassis.set_turn_pid(-135, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  flywheel_async_pid_control(9500);
  chassis.set_drive_pid(45, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  chassis.set_drive_pid(-10, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  chassis.set_drive_pid(30, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  chassis.set_turn_pid(-100, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  index_count(1);
  pros::delay(250);
  index_count(1);
  pros::delay(250);
  index_count(1);
  pros::delay(500);
  chassis.set_turn_pid(-90, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  chassis.set_drive_pid(15, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  chassis.set_turn_pid(-180, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  chassis.set_drive_pid(10, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  // TODO - Spin the roller to Red
  chassis.set_drive_pid(-6, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Start the intake
  intake_power(100);
  // Turn to face the singular disk
  chassis.set_turn_pid(-35, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Drive to intake the disk
  chassis.set_drive_pid(23, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  // Turn to face the roller
  chassis.set_turn_pid(-90, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  intake_power(0);
  // Drive towards the roller
  chassis.set_drive_pid(10, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  // TODO - Spin the roller to Red
  // Drive away from the roller
  chassis.set_drive_pid(-8, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Turn to face the high goal
  chassis.set_turn_pid(0, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Drive forward to shoot
  chassis.set_drive_pid(25, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
}
void backup_programming_skills() {}