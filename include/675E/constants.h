#pragma once

#include "api.h"
void chassis_default_constants();
void chassis_exit_conditions();
// Flywheel Constants
#define flywheel_smooth_size 3
#define flywheel_integral_smoothing 2
extern double flywheel_speeds[flywheel_smooth_size], flywheel_kP, flywheel_kI,
    flywheel_integral, flywheel_error, flywheel_speed,
    flywheel_current_velocity;

extern const int tongue_up_speed;
extern const double tongue_up_multiplier;
extern int current_tongue_up_speed;

// Intake Constants
// Indexer Constants
extern const int indexer_fall_time, indexer_rise_time;