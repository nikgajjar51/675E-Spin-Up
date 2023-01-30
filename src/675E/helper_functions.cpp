/*
 * --------------
 * Helper Functions
 * --------------
 * This file holds all of the helper functions used in all parts of my code.
 * These functions are used in autonomous, before autonomous, during driver
 * control, and some functions run in the background as continous tasks.
 */

/* Includes
 * --------
 * Here, I 'include' any external files header files that we need.y Header
 * files make any function or variable global by finding a function or
 * varibable of the same type and name. In the end, this makes it easier so all
 * of my code does not need to be included in 1 file. In this case, I included
 * all of my files in 1 header file: main.h
 */
#include "EZ-Template/util.hpp"
#include "main.h"
#include "pros/llemu.hpp"
#include "pros/misc.h"
#include "robot_config.h"
std::string alliance_color;
bool alliance_color_toggle = false;
pros::c::optical_rgb_s_t roller_optical_RGB = roller_optical.get_rgb();
const int red_threshold = 25, blue_threshold = 25;
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
// Flywheel 2 Constants
double kP = 1;
double kI = 1;
double kD = 0.01;

double error, integral, derivative, previous_error;
void flywheel_pid_2(double target_speed, float kP = 1, float kI = 1,
                    float kD = 0.01, double error = 0, double integral = 0,
                    double derivative = 0, double previous_error = 0) {
  // Get the current velocity and rotation of the flywheel
  double current_velocity = flywheel_rotation.get_velocity();
  double current_rotation = flywheel_rotation.get_position();

  // Calculate the error between the current speed and the target speed
  error = target_speed - current_velocity;

  // Calculate the integral term using the accumulated error
  integral += error;

  // Calculate the derivative term using the change in error
  derivative = error - previous_error;
  previous_error = error;

  // Calculate the output voltage using the PID constants and error terms
  double output_voltage = kP * error + kI * integral + kD * derivative;

  // Constrain the output voltage to the range (-127, 127)
  output_voltage = constrain(output_voltage, -127, 127);

  // Set the flywheel motor's voltage using the calculated output voltage
  flywheel.move(output_voltage);
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
/* Controller Data Export
 * ----------------------
 * This function is used to print crucial data to the controller screen so that
 * the drive and/or coach can look down at a glance and see these important
 * values. This is especially useful for debugging.
 */
int get_temp() { return flywheel.get_temperature(); }
void controller_data_export() {
  while (true) {
    master.print(0, 0, "Up Speed: %i", current_tongue_up_speed);
    pros::delay(50);
    master.print(1, 0, "Fly Speed: %f",
                 abs(round(flywheel.get_actual_velocity() / 10) * 60));
    pros::delay(50);
    master.print(2, 0, "Fly Temp: %i", get_temp());
    pros::delay(250);
  }
}
void turn_roller_to(std::string desired_roller_color) {
  roller_optical.set_led_pwm(100);
  if (desired_roller_color == "Red") {
    while (roller_optical_RGB.red > red_threshold) {
      intake_power(-20);
    }
    intake_power(0);
  } else if (desired_roller_color == "Blue") {
    while (roller_optical_RGB.red > blue_threshold) {
      intake_power(-20);
    }
    intake_power(0);
  }
}