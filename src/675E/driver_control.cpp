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
/* Variables
 * --------
 * Here, I defined some variables I use later one. I have booleans for toggles
 * for toggling things like drive lock and total manual control of the robot. I
 * alos have some for verifying if code is running, and it is meant to be used
 * with sensor data and interfaced with other files.
 */
std::string drive_lock_type, control_type;
bool drive_lock_toggle = false, manual_control_toggle = false,
     is_flywheel_running = false, is_tongue_up = false;
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
  if (!manual_control_toggle) {
    if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R2)) {
      is_flywheel_running = !is_flywheel_running;
      flywheel_integral = 0;
      for (int i = 0; i < flywheel_smooth_size; i++) {
        flywheel_speeds[i] = 0;
      }
      std::cout << endl << endl << "new power:" << endl << endl;
    }
    if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_LEFT)) {
      is_tongue_up = !is_tongue_up;
    }
    if (is_flywheel_running) {
      if (is_tongue_up) {
        flywheel_pid(7000);
        tongue_pneum.set_value(false);
      } else {
        flywheel_pid(7400);
        tongue_pneum.set_value(true);
      }
    } else {
      flywheel_power(0);
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
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
      index_count(1);
    }
    pros::delay(ez::util::DELAY_TIME);
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
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
      intake_power(100);
    } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
      intake_power(-33);
    } else {
      intake.move_velocity(0);
    }
    pros::delay(20);
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
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_UP)) {
      expansion_pneum.set_value(true);
    }
    pros::delay(20);
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
  if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)) {
    if (drive_lock_toggle) {
      drive_lock_toggle = !drive_lock_toggle;
      drive_lock_type = "Hold ";
      chassis.set_drive_brake(pros::E_MOTOR_BRAKE_HOLD);
      chassis.set_active_brake(0.0);
      master.rumble("-");
    } else {
      drive_lock_toggle = !drive_lock_toggle;
      drive_lock_type = "Coast";
      chassis.set_drive_brake(pros::E_MOTOR_BRAKE_COAST);
      chassis.reset_drive_sensor();
      chassis.set_active_brake(0.1);
      master.rumble("..");
    }
  }
  
}
void flywheel_manual_control() {
  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1) &&
      master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
    indexer_pneum.set_value(true);
  } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
    flywheel.move_velocity(600);
    indexer_pneum.set_value(false);
  } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
    flywheel.move_velocity(500);
    indexer_pneum.set_value(false);
  } else {
    indexer_pneum.set_value(false);
    flywheel.move_velocity(0);
  }
}
void tongue_manual_control() {
  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
    expansion_pneum.set_value(true);
  } else {
    expansion_pneum.set_value(false);
  }
}
void intake_manual_control() {
  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
    intake.move_velocity(600);
  } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
    intake.move_velocity(-200);
  } else {
    intake.move_velocity(0);
  }
}
void expansion_manual_control() {
  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT) &&
      master.get_digital(pros::E_CONTROLLER_DIGITAL_UP) &&
      master.get_digital(pros::E_CONTROLLER_DIGITAL_X) &&
      master.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {
    expansion_pneum.set_value(true);
  } else {
    expansion_pneum.set_value(false);
  }
}
void manual_control() {
  while (true) {
    flywheel_manual_control();
    tongue_manual_control();
    intake_manual_control();
    expansion_manual_control();
  }
}
void op_control_toggle() {
  if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_LEFT) &&
      master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)) {
    if (manual_control_toggle) {
      manual_control_toggle = !manual_control_toggle;
      control_type = "Manual";
      master.rumble("--------");
      master.clear();
      master.set_text(1, 0, control_type);
    } else {
      manual_control_toggle = !manual_control_toggle;
      master.rumble("- - - ");
      master.clear();
    }
  }
}