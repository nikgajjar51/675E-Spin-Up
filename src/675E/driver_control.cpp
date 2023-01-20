#include "main.h"
std::string drive_lock_type, control_type;
bool drive_lock_toggle = false, manual_control_toggle = false,
     is_flywheel_running = false, is_tongue_up = false;

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
        // BENNY - tongue down
        flywheel_pid(6000);
        tongue_pneum.set_value(false);
      } else {
        // BENNY - tongue up
        flywheel_pid(7400);
        tongue_pneum.set_value(true);
      }
    } else {
      flywheel_power(0);
    }
  }
}
void indexer_control() {
  while (true) {
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
      index_count(1);
    }
    pros::delay(ez::util::DELAY_TIME);
  }
}
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
void endgame_control() {
  while (true) {
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
      expansion_pneum.set_value(true);
    }
    pros::delay(20);
  }
}
void drive_lock_control() {
  if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)) {
    if (drive_lock_toggle) {
      drive_lock_toggle = !drive_lock_toggle;
      drive_lock_type = "Hold";
      chassis.set_drive_brake(pros::E_MOTOR_BRAKE_HOLD);
      chassis.set_active_brake(0.0);
      master.rumble("-");
      master.clear();
      master.set_text(0, 0, drive_lock_type);
    } else {
      drive_lock_toggle = !drive_lock_toggle;
      drive_lock_type = "Coast";
      chassis.set_drive_brake(pros::E_MOTOR_BRAKE_COAST);
      chassis.reset_drive_sensor();
      chassis.set_active_brake(0.1);
      master.rumble(". . .");
      master.clear();
      master.set_text(0, 0, drive_lock_type);
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
      //manual_control_task().resume();
      //intake_task().suspend();
      //endgame_task().suspend();
      //indexer_task().suspend();
      control_type = "Manual";
      master.rumble("--------");
      master.clear();
      master.set_text(1, 0, control_type);
    } else {
      //manual_control_task().suspend();
      //intake_task().resume();
      //endgame_task().resume();
      //indexer_task().resume();
      manual_control_toggle = !manual_control_toggle;
      master.rumble("- - - ");
      master.clear();
    }
  }
}