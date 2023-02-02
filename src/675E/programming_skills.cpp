#include "main.h"
void programming_skills_1() {
  intake_power(100);
  flywheel_aysnc_pid_control(7400);
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
  chassis.set_drive_pid(-28, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  intake_power(100);
  chassis.set_turn_pid(90, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  chassis.set_drive_pid(30, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  intake_power(-25);
  pros::delay(500);
  intake_power(0);
  chassis.set_drive_pid(-50, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  chassis.set_turn_pid(-45, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  intake_power(100);
  flywheel_aysnc_pid_control(7000);
  chassis.set_drive_pid(80, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  chassis.set_drive_pid(-22, drive_speed * normal_speed_multiplier);
  chassis.wait_drive();
  chassis.set_turn_pid(-135, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  chassis.set_drive_pid(-65, drive_speed * normal_speed_multiplier);
  tongue_pneum.set_value(true);
  chassis.wait_drive();
  intake_power(0);
  index_count(3);
  pros::delay(1000);
  flywheel_aysnc_pid_control(0);
}
void programming_skills_2() {
  // turn_roller_to("Red");
  intake_power(-25);
  pros::delay(300);
  intake_power(0);
  chassis.set_drive_pid(-10, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  chassis.set_turn_pid(135, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  intake_power(60);
  chassis.set_drive_pid(2, drive_speed * low_speed_multiplier);
  chassis.wait_drive();
  chassis.set_drive_pid(10, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  intake_power(0);
  chassis.set_turn_pid(90, turn_speed * high_speed_multiplier);
  chassis.wait_drive();
  chassis.set_drive_pid(25, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
  intake_power(-25);
  pros::delay(300);
  intake_power(0);
  chassis.set_drive_pid(-25, drive_speed * high_speed_multiplier);
  chassis.wait_drive();
}
void programming_skills(){
  /*
  Backwards (approach rollers)
  Spin roller to red
  Forwards (away from roller)
  Start intake
  Turn 180-220 (towards single disk)
  Forwards (intake disk)
  Turn towards other roller (90)
  Stop intake
  Backwards (approach other roller)
  Spin roller to red
  Forwards
  Turn towards Goal (0-25) 
  Shoot 3 disks
  Turn towards 3 stack (-90)
  */
}