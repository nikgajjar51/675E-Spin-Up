#include "main.h"
// V5 Motors
pros::Motor intake(2, pros::E_MOTOR_GEARSET_06, true,
                   pros::E_MOTOR_ENCODER_ROTATIONS);
pros::Motor flywheel(6, pros::E_MOTOR_GEARSET_06, true,
                     pros::E_MOTOR_ENCODER_ROTATIONS);
pros::Optical roller_optical(3);
// 3-Wire Legacy
pros::ADIDigitalIn auton_selector_button('H');
// Single Acting
pros::ADIDigitalOut expansion_pneum('E');
pros::ADIDigitalOut indexer_pneum('F');
// Double Acting
pros::ADIDigitalOut tongue_pneum('G');