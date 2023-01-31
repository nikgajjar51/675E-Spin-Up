#include "api.h"
// V5 Motors
extern pros::Motor intake;
extern pros::Motor flywheel;
// V5 Optical
extern pros::Optical roller_optical;
// V5 Rotation
extern pros::Rotation flywheel_rotation;
// 3-Wire Legacy
extern pros::ADILineSensor disk_sensor_bottom;
extern pros::ADILineSensor disk_sensor_top;
extern pros::ADILineSensor hopper_sensor_bottom;
extern pros::ADIDigitalIn auton_selector_button;
extern pros::ADIDigitalIn alliance_selector_button;
// Single Acting
extern pros::ADIDigitalOut expansion_pneum;
extern pros::ADIDigitalOut indexer_pneum;
extern pros::ADIDigitalOut tongue_pneum;
// Vision
extern pros::Vision vision_sensor;