#include "main.h"
#include "pros/adi.h"
#include "api.h"
using namespace pros;
ADIDigitalOut indexer('A',HIGH);
ADIDigitalOut expansion('B',HIGH);
Motor flywheel(11, E_MOTOR_GEAR_BLUE, false, E_MOTOR_ENCODER_ROTATIONS);
Motor intake(5, E_MOTOR_GEAR_GREEN, true, E_MOTOR_ENCODER_ROTATIONS);