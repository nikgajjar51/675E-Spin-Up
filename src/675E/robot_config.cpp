#include "main.h"
// V5 Motors
pros::Motor intake(2, pros::E_MOTOR_GEARSET_06, true,
                   pros::E_MOTOR_ENCODER_ROTATIONS);
pros::Motor flywheel(6, pros::E_MOTOR_GEARSET_06, true,
                     pros::E_MOTOR_ENCODER_ROTATIONS);
// V5 Optical
pros::Optical roller_optical(16);
// V5 Rotation
pros::Rotation flywheel_rotation(14);
// 3-Wire Legacy
pros::ADILineSensor disk_sensor_bottom('A');
pros::ADILineSensor disk_sensor_top('B');
pros::ADILineSensor hopper_sensor_bottom('C');
pros::ADIDigitalIn auton_selector_button ('C');
pros::ADIDigitalIn alliance_selector_button('D');
// Single Acting
pros::ADIDigitalOut expansion_pneum('E');
pros::ADIDigitalOut indexer_pneum('F');
pros::ADIDigitalOut tongue_pneum('G');
// Vision
pros::Vision vision_sensor(5, pros::E_VISION_ZERO_TOPLEFT);