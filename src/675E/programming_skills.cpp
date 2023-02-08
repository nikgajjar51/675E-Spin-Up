#include "constants.h"
#include "main.h"
void programming_skills() {
  // Set the tongue up
  tongue_pneum.set_value(true);
  // Start the intake to turn the roller
  intake_power(25);
  // Drive towards the roller
  chassis.set_drive_pid(5, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Drive away from the roller
  chassis.set_drive_pid(-6, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Increase intake speed to intake a disk
  intake_power(100);
  // Turn towards singular disk
  chassis.set_turn_pid(110, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Drive to intake disk
  chassis.set_drive_pid(25, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  // Turn towards the roller
  chassis.set_turn_pid(90, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Decrease the intake speed to turn the roller
  intake_power(25);
  // Start the flywheel
  flywheel_aysnc_pid_control(6900);
  // Drive towards the roller
  chassis.set_drive_pid(15, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Drive away from the roller
  chassis.set_drive_pid(-9, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Turn away towards high goal
  chassis.set_turn_pid(0, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Drive towards the high goal
  chassis.set_drive_pid(-68, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Turn towards high goal
  chassis.set_turn_pid(8, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Shoot the 3 disks
  index_count(1);
  pros::delay(500);
  index_count(1);
  pros::delay(500);
  index_count(1);
  pros::delay(500);
  // Turn home
  chassis.set_turn_pid(0, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Drive forward
  chassis.set_drive_pid(45, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Increase the flywheel speed
  flywheel_aysnc_pid_control(7400);
  // Increase intake speed to intake a disk
  intake_power(100);
  // Turn towards the 3 in-line disks
  chassis.set_turn_pid(-135, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Drive forwards to intake the 3 disks
  chassis.set_drive_pid(85, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  // Drive reverse to intake the 3 disks
  chassis.set_drive_pid(-22, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  // Turn towards the high goal
  chassis.set_turn_pid(-45, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Drive closer to the goal
  chassis.set_drive_pid(-10, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Shoot the 3 disks
  index_count(1);
  pros::delay(500);
  index_count(1);
  pros::delay(500);
  index_count(1);
  pros::delay(500);
  // Drive away from the high goal
  chassis.set_drive_pid(15, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Turn towards the 3-stack
  chassis.set_turn_pid(-135, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Drive forwards to knock over the 3-stack
  chassis.set_drive_pid(30, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Drive away from the 3-stack
  chassis.set_drive_pid(-10, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Drive forwards to intake the 3-stack
  chassis.set_drive_pid(50, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  chassis.set_turn_pid(-100, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  chassis.set_drive_pid(-50, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
}