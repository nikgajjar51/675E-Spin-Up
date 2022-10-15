#include "main.h"
#include "pros/misc.h"
int high_speed = 12, low_speed = 9;
#define Indexer_Digital_Out 'H'
pros::ADIDigitalOut indexer (Indexer_Digital_Out);
pros::Motor flywheel = pros::Motor(10, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_ROTATIONS);
void flywheel_control() {
  if (pros::E_CONTROLLER_DIGITAL_R1 == 1) {
    flywheel.move_voltage(high_speed);
  } else if (pros::E_CONTROLLER_DIGITAL_R2 == 1) {
    flywheel.move_voltage(low_speed);
  } else if (pros::E_CONTROLLER_DIGITAL_R1 == 1 && pros::E_CONTROLLER_DIGITAL_R2 == 1) {
    indexer.set_value(true);
  } else {
    flywheel.move_voltage(0);
    indexer.set_value(false);
  }
}