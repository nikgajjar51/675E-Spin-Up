#include "api.h"
extern std::string drive_lock_type, control_type;
extern bool drive_lock_toggle, manual_control_toggle, is_flywheel_running,
    is_tongue_up;
void driver_switcher();
void flywheel_pid_control();
void indexer_control();
void intake_control();
void endgame_control();
void drive_lock_control();