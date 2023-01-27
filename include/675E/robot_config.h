#pragma once
#include "api.h"
#include "pros/rotation.hpp"
// V5 Motors
extern pros::Motor intake;
extern pros::Motor flywheel;
// V5 Optical
extern pros::Optical roller_optical;
// V5 Roller
extern pros::Rotation flywheel_rotation;
// 3-Wire Legacy
extern pros::ADILineSensor disk_sensor_bottom;
extern pros::ADILineSensor disk_sensor_top;
extern pros::ADILineSensor hopper_sensor_bottom;
extern pros::ADIDigitalIn alliance_selector_button;
// Double Acting
extern pros::ADIDigitalOut expansion_pneum;
// Single Acting
extern pros::ADIDigitalOut indexer_pneum;
extern pros::ADIDigitalOut tongue_pneum;
extern pros::ADIDigitalOut intak_pneum;
// Vision
extern pros::Vision vision_sensor;