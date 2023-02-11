#pragma once
#include "api.h"
extern std::string alliance;
extern int get_flywheel_temp();
extern int get_intake_temp();
extern void flywheel_power(double percent);
extern void intake_power(double percent);
extern double mean(double x, double y);
extern double clamp(double val, double max, double min);
extern int constrain(int value, int min, int max);
extern double flywheel_get_velocity();
void index_count(int count);
void flywheel_pid(double target_speed);
void flywheel_async_pid_control(int target_speed);
void data_export();
void disabled_data_export();
void turn_roller_to(std::string color);