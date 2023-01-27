#ifndef _PROS_MAIN_H_
#define _PROS_MAIN_H_
#include "pros/rtos.hpp"
#define PROS_USE_SIMPLE_NAMES
#define PROS_USE_LITERALS
#include "675E/constants.h"
#include "675E/driver_control.h"
#include "675E/helper_functions.h"
#include "675E/match_autonomous.h"
#include "675E/programming_skills.h"
#include "675E/robot_config.h"
#include "EZ-Template/api.hpp"
#include "api.h"
using namespace pros;
using namespace pros::literals;
#ifdef __cplusplus
extern "C" {
#endif
void autonomous(void);
void initialize(void);
void disabled(void);
void competition_initialize(void);
void opcontrol(void);
#ifdef __cplusplus
}
#endif
#ifdef __cplusplus
#endif
#endif // _PROS_MAIN_H_

#include "EZ-Template/drive/drive.hpp"
extern Drive chassis;
extern pros::Task indexer_task();
extern pros::Task intake_task();
extern pros::Task endgame_task();
extern pros::Task controller_data_export_task();