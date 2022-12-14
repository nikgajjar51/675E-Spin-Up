#include "main.h"
#include "pros/rtos.hpp"
bool alliance_selector_toggle = 0, alliance_color, is_intake_running = 0,
     is_flywheel_running = 0;
int intake_counter = 0;
std::string alliance_color_string;
pros::c::optical_rgb_s_t rgb_value = roller_optical.get_rgb();
void initialize_675E() {
  disk_sensor_bottom.calibrate();
  disk_sensor_top.calibrate();
  hopper_sensor_bottom.calibrate();
  roller_optical.disable_gesture();
}
// Alliance Selector - Push a button to set the alliance color for rollers in
//                     autonomous.
void alliance_selector_function() {
  if (alliance_selector_button.get_value() == 1) {
    if (alliance_selector_toggle) {
      alliance_selector_toggle = !alliance_selector_toggle;
      alliance_color_string = "Blue";
      alliance_color = 0;
      pros::c::controller_clear_line(pros::E_CONTROLLER_MASTER, 1);
      pros::c::controller_print(pros::E_CONTROLLER_MASTER, 1, 1, "Blue");
    } else {
      alliance_selector_toggle = !alliance_selector_toggle;
      alliance_color_string = "Red";
      alliance_color = 1;
      pros::c::controller_clear_line(pros::E_CONTROLLER_MASTER, 1);
      pros::c::controller_print(pros::E_CONTROLLER_MASTER, 1, 1, "Red");
    }
  }
}
// Intake In - Fast speed for intaking and rollers.
void intake_in_fast() {
  is_intake_running = 1;
  intake.move_velocity(600);
}
// Intake In (Slow Speed) - More torque for more precise roller control
void intake_in_slow() {
  is_intake_running = 1;
  intake.move_velocity(420);
}
// Intake Out (Fast Speed) -  For unjamming the intake and rollers in the other
//                            direction
void intake_out_fast() {
  is_intake_running = 1;
  intake.move_velocity(-600);
}
// Intake Out (Slow Speed) - More torque for more precise roller control
void intake_out_slow() {
  is_intake_running = 1;
  intake.move_velocity(-150);
}
// Intake Stop - Stop the intake (using velocity because?)
void intake_stop() {
  is_intake_running = 0;
  intake.move_velocity(0);
}
// Intake (Get Velocity) - Constructor to get the velocity of the intake
int intake_get_velocity() { return intake.get_actual_velocity(); };
// Flywheel (Low Speed) - Lower speed for closer shots
void flywheel_low() {
  is_flywheel_running = 1;
  flywheel.move_velocity(400);
}
// Flywheel (High Speed)
void flywheel_high() {
  is_flywheel_running = 1;
  flywheel.move_velocity(540);
}
// Flywheel (Maximum Speed)
void flywheel_ultra_high() {
  is_flywheel_running = 1;
  flywheel.move_velocity(600);
}
// Flywheel (Stop)
void flywheel_stop() {
  is_flywheel_running = 0;
  flywheel.move_velocity(0);
}
// Single Shoot Function
int single_shoot_function() {
  int single_shoot_timer = 0;
  indexer_pneum.set_value(false);
  pros::delay(single_shoot_timer + 500);
  indexer_pneum.set_value(true);
  pros::delay(single_shoot_timer + 1000);
  return single_shoot_timer;
}
// Double Shoot Function
int double_shoot_function() {
  int double_shoot_timer = 0;
  indexer_pneum.set_value(false);
  pros::delay(double_shoot_timer + 500);
  indexer_pneum.set_value(true);
  pros::delay(double_shoot_timer + 1000);
  indexer_pneum.set_value(false);
  pros::delay(double_shoot_timer + 500);
  indexer_pneum.set_value(true);
  pros::delay(double_shoot_timer + 1000);
  return double_shoot_timer;
}
// Triple Shoot Function
int triple_shoot_function() {
  int triple_shoot_timer = 0;
  indexer_pneum.set_value(false);
  pros::delay(triple_shoot_timer + 500);
  indexer_pneum.set_value(true);
  pros::delay(triple_shoot_timer + 1000);
  indexer_pneum.set_value(false);
  pros::delay(triple_shoot_timer + 500);
  indexer_pneum.set_value(true);
  pros::delay(triple_shoot_timer + 1000);
  indexer_pneum.set_value(false);
  pros::delay(triple_shoot_timer + 500);
  indexer_pneum.set_value(true);
  pros::delay(triple_shoot_timer + 1000);
  return triple_shoot_timer;
}

// Triple Bang Bang Function
void triple_bang_bang_function() {
  int triple_shoot_timer = 0;
  flywheel_high();
  pros::delay(800);
  indexer_pneum.set_value(true);
  pros::delay(triple_shoot_timer + 100);
  indexer_pneum.set_value(false);
  pros::delay(triple_shoot_timer + 100);
  indexer_pneum.set_value(true);
  pros::delay(triple_shoot_timer + 100);
  indexer_pneum.set_value(false);
  pros::delay(triple_shoot_timer + 100);
  indexer_pneum.set_value(true);
  pros::delay(triple_shoot_timer + 100);
  indexer_pneum.set_value(false);
  pros::delay(triple_shoot_timer + 100);
  flywheel_stop();
}
void triple_bang_function() {
  int triple_shoot_timer = 0;
  flywheel_low();
  pros::delay(1000);
  indexer_pneum.set_value(true);
  pros::delay(triple_shoot_timer + 500);
  indexer_pneum.set_value(false);
  pros::delay(triple_shoot_timer + 1000);
  indexer_pneum.set_value(true);
  pros::delay(triple_shoot_timer + 500);
  indexer_pneum.set_value(false);
  pros::delay(triple_shoot_timer + 1000);
  indexer_pneum.set_value(true);
  pros::delay(triple_shoot_timer + 500);
  indexer_pneum.set_value(false);
  pros::delay(triple_shoot_timer + 1000);
  flywheel_stop();
}
// Spin to Red Function - Spin the roller to the red side using optical
int spin_to_red_function() {
  // Set the threshold for detecting red
  int red_threshold = 200;
  // While the sensor detects less then desired amount of red in the roller
  while (rgb_value.red <= red_threshold) {
    // Spin the intake
    intake_in_fast();
  }
  intake_stop();
  // Return the red value for debugging purposes
  return rgb_value.red;
}
// Spin to Blue Function - Spin the roller to the blue side using optical
int spin_to_blue_function() {
  // Set the threshold for detecting blue
  int blue_threshold = 200;
  // While the sensor detects less then desired amount of blue in the roller
  while (rgb_value.blue <= blue_threshold) {
    // Spin the intake
    intake_in_fast();
  }
  intake_stop();
  // Return the blue value for debugging purposes
  return rgb_value.blue;
}

// Tasks!!!!!!!!!!!!!!!

// Single Shoot
void single_shoot() { pros::Task single_shoot_task(single_shoot_function); }
// Double Shoot
void double_shoot() { pros::Task single_shoot_task(double_shoot_function); }
// Triple Shoot
void triple_shoot() { pros::Task triple_shoot_task(triple_shoot_function); }
// Spin to Red
//     void spin_to_red() { pros::Task spin_to_red_task(spin_to_red_function); }
// Spin to Blue
//     void spin_to_blue() { pros::Task
//     spin_to_blue_task(spin_to_blue_function); }