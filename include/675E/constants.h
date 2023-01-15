#pragma once

#include "api.h"
void chassis_default_constants();
void chassis_exit_conditions();
// Flywheel Constants
#define flywheel_smooth_size 3
#define flywheel_integral_smoothing 2
extern double flywheel_speeds[flywheel_smooth_size];
extern double flywheel_kP;
extern double flywheel_kI;
extern double flywheel_integral;
extern double flywheel_error;
extern double flywheel_speed;
extern double flywheel_current_velocity;
// Intake Constants
// Indexer Constants
extern const int indexer_fall_time, indexer_rise_time;