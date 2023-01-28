#include "main.h"
/*
Tuning a PID controller involves adjusting the values of the three constants:
the proportional (KP), integral (KI), and derivative (KD) terms, to achieve the
desired behavior of the system being controlled. There are several methods to
tune a PID controller, here are a few popular methods:

1. The Ziegler-Nichols method: This method uses a step test to estimate the
optimal values of Kp, Ti, and Td. It's a quick and easy method to get a rough
estimate of the optimal values, but it does not guarantee optimal performance.

2. The Tyreus-Luyben method: This method is an extension of the Ziegler-Nichols
method, which estimates the optimal values of Kp, Ti, and Td by considering the
process dynamics.

3. The Cohen-Coon method: This method is an alternative method to the
Ziegler-Nichols method, which estimates the optimal values of Kp, Ti, and Td by
considering the process dynamics.

4. The Iterative method: This method is a trial-and-error method where you start
with a set of initial values for Kp, Ki, and Kd, and then make small adjustments
to these values based on the performance of the controller. This method can be
time-consuming, but it can give the best results.

5. The Relay feedback method: This method uses a relay feedback to generate a
step response and then use the step response to tune the PID controller.

6. The Genetic Algorithm method: This method uses a genetic algorithm to
optimize the PID controller's parameters.

In most cases, the Iterative method is the preferred method as it allows you to
fine-tune the controller to the specific requirements of your system.

In the code I provided, I set the values of Kp, Ki, and Kd to be 0.3, 0.05, and
0.05 respectively. You can start with these values and then adjust them
accordingly based on the performance of the controller.

It's also important to note that the PID tuning process is an iterative process
that requires monitoring the performance of the controller and making
adjustments as needed.



Regenerate response

*/
int constrain(int value, int min, int max) {
  if (value < min) {
    return min;
  }
  if (value > max) {
    return max;
  }
  return value;
}
#define KP 1.0        // Proportional gain
#define KI 0.1        // Integral gain
#define KD 0.01       // Derivative gain
#define TOLERANCE 10  // Tolerance for error
#define MAX_SPEED 127 // Maximum motor speed

int current_speed = 0; // Current flywheel speed
int error = 0;        // Error between desired and current speed
int integral = 0;     // Integral of error
int derivative = 0;   // Derivative of error
int last_error = 0;    // Previous error
int output = 0;       // PID output to motor

void flywheel_pid_control_2(int target_speed) {
  while (true) {
    current_speed = flywheel.get_actual_velocity();
    error = target_speed - current_speed;
    if (abs(error) < TOLERANCE) {
      integral = 0;
    } else {
      integral += error;
    }
    derivative = error - last_error;
    output = KP * error + KI * integral + KD * derivative;
    output = constrain(output, -MAX_SPEED, MAX_SPEED);
    flywheel.move_voltage(output);
    last_error = error;
    pros::Task::delay(20);
  }
}
