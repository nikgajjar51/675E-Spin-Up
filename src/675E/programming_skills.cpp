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
  flywheel_aysnc_pid_control(8000);
  // Drive towards the roller
  chassis.set_drive_pid(15, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Drive away from the roller
  chassis.set_drive_pid(-9, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Turn away towards high goal
  chassis.set_turn_pid(10, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Drive towards the high goal
  chassis.set_drive_pid(-68, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Shoot the 3 disks
  index_count(1);
  pros::delay(250);
  index_count(1);
  pros::delay(250);
  index_count(1);
  pros::delay(250);
  // Turn home
  chassis.set_turn_pid(0, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Drive forward
  chassis.set_drive_pid(45, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Increase the flywheel speed
  flywheel_aysnc_pid_control(12000);
  // Increase intake speed to intake a disk
  intake_power(100);
  // Turn towards the 3 in-line disks
  chassis.set_turn_pid(-135, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Drive forwards to intake the 3 disks
  chassis.set_drive_pid(65, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  // Turn towards the high goal
  chassis.set_turn_pid(-50, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Drive closer to the goal
  chassis.set_drive_pid(-10, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Shoot the 3 disks
  index_count(1);
  pros::delay(250);
  index_count(1);
  pros::delay(250);
  index_count(1);
  pros::delay(250);
  // Drive away from the high goal
  chassis.set_drive_pid(15, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Decrease the flywheel speed
  flywheel_aysnc_pid_control(7400);
  // Turn towards thr 3-stack
  chassis.set_turn_pid(-135, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Drive forwards to knock over and intake the 3-stack
  chassis.set_drive_pid(70, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  // Turn to face the roller
  chassis.set_turn_pid(0, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Decrease intake speed to spin the roller
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
  // Drive towards the roller
  chassis.set_drive_pid(15, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  // Drive away from the roller
  chassis.set_drive_pid(-9, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
}