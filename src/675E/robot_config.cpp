#include "main.h"
#include "pros/distance.hpp"
// V5 Motors
pros::Motor intake(2, pros::E_MOTOR_GEARSET_06, true,
                   pros::E_MOTOR_ENCODER_ROTATIONS);
pros::Motor flywheel(6, pros::E_MOTOR_GEARSET_06, true,
                     pros::E_MOTOR_ENCODER_ROTATIONS);
// V5 Sensors
pros::Distance hopper_distance(17);
pros::Optical roller_optical(16);
pros::Rotation flywheel_rotation(14);
pros::Vision vision_sensor(5, pros::E_VISION_ZERO_TOPLEFT);
// 3-Wire Legacy
// Single Acting
pros::ADIDigitalOut expansion_pneum('E');
pros::ADIDigitalOut indexer_pneum('F');
// Double Acting
pros::ADIDigitalOut tongue_pneum('G');