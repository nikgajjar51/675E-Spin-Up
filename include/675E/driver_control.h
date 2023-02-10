#include "api.h"
extern std::string drive_lock_type, driver, alliance;
extern bool drive_lock_toggle, is_flywheel_running, is_tongue_up;
extern pros::controller_digital_e_t flywheel_toggle_button;
extern pros::controller_digital_e_t tongue_toggle_button;
extern pros::controller_digital_e_t tongue_speed_button;
extern pros::controller_digital_e_t indexer_button;
extern pros::controller_digital_e_t intake_in_button;
extern pros::controller_digital_e_t intake_out_button;
extern pros::controller_digital_e_t drive_lock_button;
void driver_selector();
void alliance_selector();
void flywheel_pid_control();
void tongue_control();
void indexer_control();
void intake_control();
void endgame_control();
void drive_lock_control();