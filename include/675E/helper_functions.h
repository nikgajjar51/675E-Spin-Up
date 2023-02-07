#include "api.h"
extern std::string alliance_color;
extern bool alliance_color_toggle;
extern pros::c::optical_rgb_s_t roller_optical_RGB;
extern const int red_threshold, blue_threshold;
extern int get_flywheel_temp();
void flywheel_power(double percent);
void intake_power(double percent);
extern double mean(double x, double y);
extern double clamp(double val, double max, double min);
extern int constrain(int value, int min, int max);
extern double flywheel_get_velocity();
void index_count(int count);
void flywheel_pid(double target_speed);
void flywheel_aysnc_pid_control(int target_speed);
void alliance_selector_function();
void disabled_data_export();
void autonomous_data_export();
void driver_data_export();