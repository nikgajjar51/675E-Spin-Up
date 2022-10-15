#include "main.h"
#include "pros/misc.h"

// flywheel speeds + intake/flywheel port placeholders
int high_speed = 12, low_speed = 9, flywheel_port, intake_port;
// constructor for indexer pneum
pros::ADIDigitalOut indexer('A');
// constructor for expansion pneum
pros::ADIDigitalOut expansion('B');
pros::Motor flywheel = pros::Motor(flywheel_port, pros::E_MOTOR_GEARSET_36,
                                   false, pros::E_MOTOR_ENCODER_ROTATIONS);
pros::Motor intake = pros::Motor(intake_port, pros::E_MOTOR_GEARSET_36, false,
                                 pros::E_MOTOR_ENCODER_ROTATIONS);
void flywheel_control() {
  if (pros::E_CONTROLLER_DIGITAL_R1 == 1) {
    flywheel.move_voltage(high_speed);
  } else if (pros::E_CONTROLLER_DIGITAL_R2 == 1) {
    flywheel.move_voltage(low_speed);
  } else if (pros::E_CONTROLLER_DIGITAL_R1 == 1 &&
             pros::E_CONTROLLER_DIGITAL_R2 == 1) {
    indexer.set_value(true);
  } else {
    flywheel.move_voltage(0);
    indexer.set_value(false);
  }
}
void intake_control() {
  if (pros::E_CONTROLLER_DIGITAL_L1 == 1) {
    intake.move_voltage(10);
  } else if (pros::E_CONTROLLER_DIGITAL_L2 == 1) {
    intake.move_voltage(-10);
  } else {
    intake.move_voltage(0);
  }
}
void expansion_control() {
  if (pros::E_CONTROLLER_DIGITAL_A == 1 && pros::E_CONTROLLER_DIGITAL_B == 1 &&
      pros::E_CONTROLLER_DIGITAL_LEFT == 1 &&
      pros::E_CONTROLLER_DIGITAL_DOWN == 1) {
    expansion.set_value(true);
  }
}