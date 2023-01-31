#include "api.h"
void flywheel_power(double percent);
void intake_power(double percent);
double clamp();
double flywheel_get_velocity();
void index_count(int count);
void flywheel_pid(double target_speed);
void flywheel_pid_2(double target_speed);
void flywheel_aysnc_pid_control(int target_speed);
void alliance_selector_function();
void controller_data_export();
void match_auto_roller();
void skills_auto_roller();