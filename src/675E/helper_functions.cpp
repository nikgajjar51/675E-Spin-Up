#include "EZ-Template/auton.hpp"
#include "constants.h"
#include "main.h"
std::string alliance_color;
bool alliance_color_toggle = false;
pros::c::optical_rgb_s_t roller_optical_RGB = roller_optical.get_rgb();
const int red_threshold = 25, blue_threshold = 25;
int get_flywheel_temp() { return flywheel.get_temperature(); }
void flywheel_power(double percent) { flywheel.move(120 * percent); }
void intake_power(double percent) { intake.move(120 * percent); }
double mean(double x, double y) { return ((x + y) / 2); }
double clamp(double val, double max, double min) {
  return (std::max(std::min(val, max), min));
}
int constrain(int value, int min, int max) {
  if (value < min) {
    return min;
  }
  if (value > max) {
    return max;
  }
  return value;
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
    pros::delay(indexer_rise_time);
    indexer_pneum.set_value(false);
    pros::delay(indexer_fall_time);
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
void autonomous_timer() {}
void disabled_data_export() {
  while (true) {
    master.print(1, 0, "Driver: %s", driver);
    delay(50);
  }
}
void driver_data_export() {
  while (true) {
    master.print(0, 0, "Up Speed: %i", current_tongue_up_speed);
    pros::delay(50);
    master.print(1, 0, "Fly Speed: %f",
                 abs(round(flywheel.get_actual_velocity() / 10) * 60));
    pros::delay(50);
    master.print(2, 0, "Fly Temp: %i", get_flywheel_temp());
    pros::delay(250);
  }
}
void autonomous_data_export() {
  while (true) {
    master.print(0, 0, "Time:: %i", driver);
    pros::delay(50);
    master.print(1, 0, "Fly Speed: %f",
                 abs(round(flywheel.get_actual_velocity() / 10) * 60));
    pros::delay(50);
    master.print(2, 0, "Fly Temp: %i", get_flywheel_temp());
    pros::delay(250);
  }
}

void Endgame_Fire(void *) {
  double startTime, skillsTime = 60, matchTime = 105, deployTime, driveTime;
  bool wasDisabled = true;
  bool depoly_endgame = false;
  if (wasDisabled) {
    startTime = pros::millis();
  }
  if (ez::as::auton_selector.current_auton_page == 0) {
    driveTime = matchTime;
  }
  if (ez::as::auton_selector.current_auton_page == 1) {
    driveTime = skillsTime;
  }
  deployTime = driveTime * 1000 - 10000;
  while (true) {
    if ((pros::millis() - startTime >= deployTime)) {
      // controller master.print(2,0,"valueTest"); unlocks the endgame
      depoly_endgame = true;
      pros::delay(20);
    }
    if (depoly_endgame == true) {
      pros::delay(20);
    }
  }
}
