#include "main.h"
#include "pros/rtos.hpp"
std::string alliance_color;
bool alliance_color_toggle = false;
void flywheel_power(double percent) { flywheel.move(120 * percent); }
void intake_power(double percent) { intake.move_velocity(6 * percent); }
double mean(double x, double y) { return ((x + y) / 2); }
double clamp(double val, double max, double min) {
  return (std::max(std::min(val, max), min));
}
double flywheel_get_velocity() {
  double sum = 0;
  for (int i = 0; i < flywheel_smooth_size; i++) {
    sum += flywheel_speeds[i];
  }
  return sum / flywheel_smooth_size;
}
void index_count(int count) {
  for (int i = 0; i < count; i++) {
    indexer_pneum.set_value(true);
    pros::delay(indexer_fall_time);
    indexer_pneum.set_value(false);
    pros::delay(indexer_rise_time);
  }
}
void flywheel_pid(double target_speed) {
  double current_velocity = (flywheel_get_velocity() * 36);
  flywheel_error = target_speed - current_velocity;
  for (int i = 0; i < flywheel_smooth_size - 1; i++) {
    flywheel_speeds[i] = flywheel_speeds[i - 1];
  }
  flywheel_speeds[flywheel_smooth_size - 1] = mean(
      abs(flywheel.get_actual_velocity()), abs(flywheel.get_actual_velocity()));
  flywheel_integral = clamp(flywheel_integral + ez::util::sgn(flywheel_error),
                            10 * flywheel_integral_smoothing,
                            -10 * flywheel_integral_smoothing);
  if (abs(flywheel_error) > 200) {
    flywheel_integral = 0;
  }
  flywheel_speed = clamp(
      flywheel_kP * flywheel_error + flywheel_kI * flywheel_integral, 100, 0);
  flywheel_power(flywheel_speed);
  std::cout << (int)(current_velocity) << "\t" << (int)flywheel_error << "\t"
            << (int)flywheel_integral << "\t" << (int)flywheel_speed << endl;
}
void flywheel_aysnc_pid_control(int target_speed) {
  flywheel_integral = 0;
  for (int i = 0; i < flywheel_smooth_size; i++) {
    flywheel_speeds[i] = 0;
  }
  std::cout << endl << endl << "new power:" << endl << endl;
  flywheel_pid(target_speed);
}
void alliance_selector_function() {
  if (alliance_selector_button.get_new_press()) {
    if (alliance_color_toggle) {
      alliance_color_toggle = !alliance_color_toggle;
      alliance_color = "Red";
      master.clear();
      master.set_text(0, 0, alliance_color);

    } else {
      alliance_color_toggle = !alliance_color_toggle;
      alliance_color = "Blue";
      master.clear();
      master.set_text(0, 0, alliance_color);
    }
  }
}
void roller_to_color() {}