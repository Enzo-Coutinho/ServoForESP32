#ifndef SERVO_LOW_LEVEL_h
#define SERVO_LOW_LEVEL_h

#include "master.h"

void configure_servo(gpio_num_t pin, uint32_t frequency);
void write_angle_in_degrees(gpio_num_t pin, uint16_t angleInDegrees, uint16_t minAngleDegrees, uint16_t maxAngleDegrees, uint16_t minPulseWidht, uint16_t maxPulseWidht, uint32_t frequency); 

void disable_servo(gpio_num_t pin);

#endif