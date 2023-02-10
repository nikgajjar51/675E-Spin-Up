#include "main.h"
pros::Task disabled_data_export_task(disabled_data_export,
                                     TASK_PRIORITY_DEFAULT,
                                     TASK_STACK_DEPTH_DEFAULT, "Disabled Data");
pros::Task data_export_task(data_export, TASK_PRIORITY_DEFAULT,
                                   TASK_STACK_DEPTH_DEFAULT, "Match Data");
pros::Task indexer_task(indexer_control, TASK_PRIORITY_DEFAULT,
                        TASK_STACK_DEPTH_DEFAULT, "Indexer OpControl");
pros::Task intake_task(intake_control, TASK_PRIORITY_DEFAULT,
                       TASK_STACK_DEPTH_DEFAULT, "Intake OpControl");
pros::Task endgame_task(endgame_control, TASK_PRIORITY_DEFAULT,
                        TASK_STACK_DEPTH_DEFAULT, "Endgame OpControl");
pros::Task tongue_task(tongue_control, TASK_PRIORITY_DEFAULT,
                        TASK_STACK_DEPTH_DEFAULT, "Endgame OpControl");