#include "main.h"
using namespace pros;
std::string drive_lock_type, control_type, driver = "Rohan";
bool drive_lock_toggle = false, is_flywheel_running = false,
     is_tongue_up = false;
controller_digital_e_t flywheel_toggle_button = E_CONTROLLER_DIGITAL_R2;
controller_digital_e_t tongue_toggle_button = E_CONTROLLER_DIGITAL_LEFT;
controller_digital_e_t tongue_speed_button = E_CONTROLLER_DIGITAL_UP;
controller_digital_e_t indexer_button = E_CONTROLLER_DIGITAL_R1;
controller_digital_e_t intake_in_button = E_CONTROLLER_DIGITAL_L1;
controller_digital_e_t intake_out_button = E_CONTROLLER_DIGITAL_L2;
controller_digital_e_t drive_lock_button = E_CONTROLLER_DIGITAL_RIGHT;
void driver_switcher() {
  while (true) {
    if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_A)) {
      if (driver == "Benny") {
        driver = "Rohan";
      } else {
        driver = "Benny";
      }
    }
    master.print(2, 0, "Driver: %s", driver);
    delay(50);
  }
}
void flywheel_pid_control() {
  if (master.get_digital_new_press(flywheel_toggle_button)) {
    is_flywheel_running = !is_flywheel_running;
    flywheel_integral = 0;
    for (int i = 0; i < flywheel_smooth_size; i++) {
      flywheel_speeds[i] = 0;
    }
    std::cout << endl << endl << "new power:" << endl << endl;
  }
  if (master.get_digital_new_press(tongue_toggle_button)) {
    is_tongue_up = !is_tongue_up;
  }
  if (is_flywheel_running) {
    if (is_tongue_up) {
      flywheel_pid(7000);
      tongue_pneum.set_value(false);
    } else {
      flywheel_pid(current_tongue_up_speed);
      tongue_pneum.set_value(true);
    }
  } else {
    flywheel_power(0);
  }
  if (master.get_digital_new_press(tongue_speed_button)) {
    if (current_tongue_up_speed == tongue_high_speed) {
      current_tongue_up_speed = tongue_low_speed;

    } else if (current_tongue_up_speed != tongue_high_speed) {
      current_tongue_up_speed = tongue_high_speed;
    }
  }
}
void indexer_control() {
  while (true) {
    if (master.get_digital(indexer_button) && is_flywheel_running &&
        abs(round(flywheel.get_actual_velocity() / 10) * 60) > 2200) {
      index_count(1);
    }
    delay(ez::util::DELAY_TIME);
  }
}
void intake_control() {
  while (true) {
    if (master.get_digital(intake_in_button)) {
      // intake_power(100);
      intake.move_velocity(600);
    } else if (master.get_digital(intake_out_button)) {
      //intake_power(-33);
      intake.move_velocity(-200);

    } else {
      intake.move_velocity(0);
    }
    delay(20);
  }
}
void endgame_control() {
  while (true) {
    if (master.get_digital(E_CONTROLLER_DIGITAL_LEFT) &&
        master.get_digital(E_CONTROLLER_DIGITAL_UP) &&
        master.get_digital(E_CONTROLLER_DIGITAL_X) &&
        master.get_digital(E_CONTROLLER_DIGITAL_A)) {
      expansion_pneum.set_value(true);
    }
    delay(20);
  }
}
void drive_lock_control() {
  if (master.get_digital_new_press(drive_lock_button)) {
    if (drive_lock_toggle) {
      drive_lock_toggle = !drive_lock_toggle;
      drive_lock_type = "Hold ";
      chassis.set_drive_brake(E_MOTOR_BRAKE_HOLD);
      chassis.set_active_brake(0.0);
      master.rumble("-");
    } else {
      drive_lock_toggle = !drive_lock_toggle;
      drive_lock_type = "Coast";
      chassis.set_drive_brake(E_MOTOR_BRAKE_COAST);
      chassis.reset_drive_sensor();
      chassis.set_active_brake(0.1);
      master.rumble("..");
    }
  }
}