#pragma once
#include "pros/adi.hpp"
#include "pros/motors.hpp"
extern int high_speed, low_speed, flywheel_port, intake_port;
extern pros::ADIDigitalOut indexer;
extern pros::ADIDigitalOut expansion;
extern pros::Motor flywheel;
extern pros::Motor intake;
void flywheel_control(void);
void intake_control(void);