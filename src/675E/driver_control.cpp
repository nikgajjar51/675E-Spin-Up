/*
 * --------------
 * Driver Control
 * --------------
 * This file holds all of the code used during the 1:45 minute driver control
 * period. Specifically, this file has all of the functions on buttons mapped;
 * not nessecarily any background functions or helper functions like PID's and
 * functions to convert motor voltage to percent.
 */

/* Includes
 * --------
 * Here, I 'include' any external files header files that we need.y Header
 * files make any function or variable global by finding a function or
 * varibable of the same type and name. In the end, this makes it easier so all
 * of my code does not need to be included in 1 file. In this case, I included
 * all of my files in 1 header file: main.h
 */
#include "main.h"
using namespace pros;
/* Variables
 * --------
 * Here, I defined some variables I use later one. I have booleans for toggles
 * for toggling things like drive lock and total manual control of the robot. I
 * alos have some for verifying if code is running, and it is meant to be used
 * with sensor data and interfaced with other files.
 */

std::string drive_lock_type, control_type, driver = "Rohan";
bool drive_lock_toggle = false, is_flywheel_running = false,
     is_tongue_up = false;
controller_digital_e_t flywheel_toggle_button = E_CONTROLLER_DIGITAL_R2;
controller_digital_e_t tongue_toggle_button = E_CONTROLLER_DIGITAL_DOWN;
controller_digital_e_t tongue_speed_button = E_CONTROLLER_DIGITAL_LEFT;
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
/* Flywheel PID Control
 * --------------------
 * This function uses a PID that I have made in helper_functions.cpp. I have an
 * if-else statement on the R2 buttonfor toggling the flyhweel on and off.
 * Within these statement, there is another statement using the Left D-pad
 * button that changes the flywheel speed and activates tongue on the robot up
 * or down. We use a higher speed with the tongue up to compensate for the
 * energy loss when the spinning disk hits the tounge, and a lower speed, but
 * still quite fast, for normal control.
 */
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
    if (current_tongue_up_speed == tongue_up_speed) {
      current_tongue_up_speed = tongue_up_speed * tongue_up_multiplier;
    } else if (current_tongue_up_speed != tongue_up_speed) {
      current_tongue_up_speed = tongue_up_speed;
    }
  }
}
/* Indexer Control
 * ---------------
 * This fucntion is used in conjunction with the flyhweel PID. It indexes disks
 * while the R1 button is pressed down continously for simplicity. We have
 * constants in constants.cpp to control the speed at which the indexer rises
 * and falls.
 */
void indexer_control() {
  while (true) {
    if (master.get_digital(indexer_button)) {
      index_count(1);
    }
    delay(ez::util::DELAY_TIME);
  }
}
/* Intake Control
 * --------------
 * This function is used to manage the intake. Using an if-else statement, when
 * the L1 button is pressed, we intake at 100% speed to get disks as quickly as
 * possible. When the L2 Button is pressed, the intake runs at 1/3 speed, and in
 * the reverse direction. This is used for both outtaking or to clear jams, as
 * well as to spin rollers at a slower speed for more consistency and torque.
 */
void intake_control() {
  while (true) {
    if (master.get_digital(intake_in_button)) {
      intake_power(100);
    } else if (master.get_digital(intake_out_button)) {
      intake_power(-33);
    } else {
      intake.move_velocity(0);
    }
    delay(20);
  }
}
/* Endgame Expansion Control
 * -------------------------
 * This fucntion is used to activate our endgame. Before, I used a combination
 * of buttons (specifically the D-Pad up and left buttons and the X and A
 * buttons) which are postioned so that our fingers fall naturally on them. In
 * reality, this was not the best choice as it adds complexity and forethought.
 *
 * We now just use the down button on the D-Pad to activate it.
 * Sweet and Simple :)
 */
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
/* Drive Lock Control
 * ------------------
 * This function is used to activate a drive lock on our robot. In reality, this
 * drive lock is not physical but rather utilizes the motor Brake Modes to
 * either hold position or coast upon stop. Holding the motors on our
 * drivetrain, esepcially with our gear ratio and the 6 motors we use on it,
 * make for an effective drive lock.
 */
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