#include "constants.h"
#include "main.h"
int get_flywheel_temp() { return flywheel.get_temperature(); }
int get_intake_temp() { return intake.get_temperature(); }
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
void flywheel_async_pid_control(int target_speed) {
  flywheel_integral = 0;
  for (int i = 0; i < flywheel_smooth_size; i++) {
    flywheel_speeds[i] = 0;
  }
  std::cout << endl << endl << "new power:" << endl << endl;
  flywheel_pid(target_speed);
}
void data_export() {
  while (true) {
    master.print(0, 0, "Alliance: %s", alliance);
    pros::delay(50);
    master.print(1, 0, "Fly Speed: %f",
                 abs(flywheel.get_actual_velocity() / 10) * 60);
    pros::delay(50);
    master.print(2, 0, "Fly: %i | Int: %i", get_flywheel_temp(),
                 get_intake_temp());
    pros::delay(250);
  }
}
void turn_roller_to(std::string color) {
  int up_threshold, down_threshold;
  roller_optical.set_led_pwm(100);
  if (color == "Red") {
    up_threshold = 230, down_threshold = 150;
  } else if (color == "Blue") {
    up_threshold = 20, down_threshold = 0;
  }
  while (roller_optical.get_hue() < up_threshold ||
         roller_optical.get_hue() > down_threshold) {
    //intake_power(1);
    intake.move(10);
    pros::delay(ez::util::DELAY_TIME);
  }
  intake_power(0);
  roller_optical.set_led_pwm(0);
}