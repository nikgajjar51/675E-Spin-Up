#include "main.h"
void flywheel_control() {
  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1) == 1 && master.get_digital(pros::E_CONTROLLER_DIGITAL_R2) == 1) {
    indexer_pneum.set_value(true);
  } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1) == 1) {
    indexer_pneum.set_value(false);
    flywheel_high();
  } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2) == 1) {
    indexer_pneum.set_value(false);
    flywheel_low();
  } else {
    indexer_pneum.set_value(false);
    flywheel_stop();
  }
}
void intake_control() {
  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1) == 1) {
    intake_in();
  } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2) == 1) {
    intake_out();
  } else {
    intake_stop();
  }
}
void expansion_control() {
  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT) == 1 && master.get_digital(pros::E_CONTROLLER_DIGITAL_A) == 1 && master.get_digital(pros::E_CONTROLLER_DIGITAL_UP) == 1 && master.get_digital(pros::E_CONTROLLER_DIGITAL_X) == 1) {
    expansion_pneum.set_value(true);
  } else {
    expansion_pneum.set_value(false);
  }
}