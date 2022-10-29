#include "main.h"
using namespace pros;
void flywheel_control() {
  if (pros::E_CONTROLLER_DIGITAL_R2 == 1 &&
      pros::E_CONTROLLER_DIGITAL_R1 == 1) {
    indexer.set_value(true);
  }
  if (master.get_digital_new_press(E_CONTROLLER_DIGITAL_R1) == 1) {
    flywheel.move_velocity(590);
  } else if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R2) == 1) {
    flywheel.move_velocity(300);
  }
}
void intake_control() {
  if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1) == 1) {
    intake.move_velocity(10);
  } else if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2) == 1) {
    intake.move_velocity(-10);
  } else {
    intake.move_velocity(0);
  }
}