#include "main.h"
// Auton Constants
const int drive_speed = 70, turn_speed = 75, swerve_speed = 50;
const double low_speed_multiplier = .5, normal_speed_multiplier = 1,
             high_speed_multiplier = 1.7, balls_to_the_walls = 2;
// Chassis Constants
void chassis_default_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}
void chassis_exit_conditions() {
  chassis.set_exit_condition(chassis.turn_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.swing_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.drive_exit, 80, 50, 300, 150, 500, 500);
}
// Flywheel Constants
#define flywheel_smooth_size 3
#define flywheel_integral_smoothing 2
double flywheel_speeds[flywheel_smooth_size];
double flywheel_kP = 1.0;
double flywheel_kI = (1.0 / flywheel_integral_smoothing);
double flywheel_integral = 0;
double flywheel_error = 0;
double flywheel_speed = 0;
double flywheel_current_velocity = 0;
int current_tongue_up_speed = 7500;
const int tongue_high_speed = 7500, tongue_low_speed = 7000;
// Intake Constants
const int intake_in_speed = 100;
const int intake_out_speed = -50;
// Indexer Constants
const int indexer_fall_time = 250;
const int indexer_rise_time = 250;