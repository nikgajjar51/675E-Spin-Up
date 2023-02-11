#pragma once
#include "api.h"
// Auton Constants
extern const int drive_speed, turn_speed, swerve_speed;
extern const double low_speed_multiplier, normal_speed_multiplier,
    high_speed_multiplier, balls_to_the_walls;
void chassis_default_constants();
void chassis_exit_conditions();
// Flywheel Constants
#define flywheel_smooth_size 3
#define flywheel_integral_smoothing 2
extern double flywheel_speeds[flywheel_smooth_size], flywheel_kP, flywheel_kI,
    flywheel_integral, flywheel_error, flywheel_speed,
    flywheel_current_velocity;
extern const int tongue_up_speed, tongue_down_speed;
extern int current_speed;
// Intake Constants
extern const int intake_in_speed, intake_out_speed;

// Indexer Constants
extern const int indexer_fall_time, indexer_rise_time;