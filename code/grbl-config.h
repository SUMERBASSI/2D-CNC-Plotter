// Sample config.h for mini CNC plotter using DVD steppers

#ifndef config_h
#define config_h

// Define CPU_MAP_ATMEGA328P for Arduino Uno
#define CPU_MAP_ATMEGA328P

// Serial baudrate
#define BAUDRATE 115200

// Define Grbl Travel resolution in steps/mm (adjust based on your steppers)
#define DEFAULT_X_STEPS_PER_MM 250.0
#define DEFAULT_Y_STEPS_PER_MM 250.0
#define DEFAULT_Z_STEPS_PER_MM 250.0  // For servo, if used

// Max travel (adjust to your plotter size, e.g., DVD rail length ~40-50mm)
#define DEFAULT_X_MAX_TRAVEL 50.0
#define DEFAULT_Y_MAX_TRAVEL 50.0
#define DEFAULT_Z_MAX_TRAVEL 1.0  // Small for pen lift

// Homing (optional; enable if you add limit switches)
#define HOMING_ENABLE 0

// Other defaults...
#define DEFAULT_X_MAX_RATE 500.0 // mm/min
#define DEFAULT_Y_MAX_RATE 500.0
#define DEFAULT_Z_MAX_RATE 100.0

#define DEFAULT_X_ACCELERATION 500
#define DEFAULT_Y_ACCELERATION 500
#define DEFAULT_Z_ACCELERATION 100

// For servo pen lift (map Z to servo)
#define VARIABLE_SPINDLE  // Enable PWM for servo
#define SPINDLE_PWM_MIN_DUTY 5  // Adjust for servo angles
#define SPINDLE_PWM_MAX_DUTY 250

#endif
