#include "api.h"
using namespace pros;
extern std::string drive_lock_type, control_type, driver;
extern bool drive_lock_toggle, is_flywheel_running, is_tongue_up;
extern controller_digital_e_t flywheel_toggle_button;
extern controller_digital_e_t tongue_toggle_button;
extern controller_digital_e_t tongue_speed_button;
extern controller_digital_e_t indexer_button;
extern controller_digital_e_t intake_in_button;
extern controller_digital_e_t intake_out_button;
extern controller_digital_e_t drive_lock_button;
void driver_switcher();
void flywheel_pid_control();
void indexer_control();
void intake_control();
void endgame_control();
void drive_lock_control();