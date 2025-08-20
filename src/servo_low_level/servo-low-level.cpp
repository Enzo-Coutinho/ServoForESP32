#include "servo-low-level.hpp"
#include "Arduino.h"


#define LEDC_MODE LEDC_LOW_SPEED_MODE

static const int DEFAULT_REFRESH_USEC = 20000;
static const int DEFAULT_TIMER_WIDTH_TICKS = 1024;
static const int DEFAULT_RESOLUTION = LEDC_TIMER_10_BIT;
static const int DISABLED_SERVO = 0;

uint32_t usToTicks(uint32_t usec, uint32_t frequency);
uint32_t ticksToUs(uint32_t ticks, uint32_t frequency);
uint32_t angleToUs(uint16_t angleInDegrees, uint16_t minAngleDegrees, uint16_t maxAngleDegrees, uint16_t minPulseWidht, uint16_t maxPulseWidht);

void writeMicroseconds(gpio_num_t pin, uint32_t microseconds, uint32_t frequency);    
void writeTicks(uint32_t ticks, gpio_num_t pin);   
        
uint32_t readMicroseconds(uint32_t current_ticks, uint32_t frequency);

void configure_servo(gpio_num_t pin, uint32_t frequency)
{
    if(!ledcAttach(pin, frequency, DEFAULT_RESOLUTION))
        log_e("Failed Servo Attached on pin(%d), freq(%d), resl(%d)", pin, frequency, DEFAULT_RESOLUTION);
}

void write_angle_in_degrees(gpio_num_t pin, uint16_t angleInDegrees, uint16_t minAngleDegrees, uint16_t maxAngleDegrees, uint16_t minPulseWidht, uint16_t maxPulseWidht, uint32_t frequency)
{
    writeMicroseconds(pin, angleToUs(angleInDegrees, minAngleDegrees, maxAngleDegrees, minPulseWidht, maxPulseWidht), frequency);
}

void writeMicroseconds(gpio_num_t pin, uint32_t microseconds, uint32_t frequency)
{
    writeTicks(usToTicks(microseconds, frequency), pin);  // convert to ticks
}

void writeTicks(uint32_t ticks, gpio_num_t pin)
{
    ledcWrite((uint8_t)pin, ticks);
}

uint32_t readMicroseconds(uint32_t current_ticks, uint32_t frequency)
{
    return ticksToUs(current_ticks, frequency);
}


uint32_t usToTicks(uint32_t usec, uint32_t frequency)
{
    return (int)((double)usec / ((double)DEFAULT_REFRESH_USEC / (double)DEFAULT_TIMER_WIDTH_TICKS)*(((double)frequency)/50.0));
}

uint32_t ticksToUs(uint32_t ticks, uint32_t frequency)
{
    return (int)((double)ticks * ((double)DEFAULT_REFRESH_USEC / (double)DEFAULT_TIMER_WIDTH_TICKS)/(((double)frequency)/50.0));
}

uint32_t angleToUs(uint16_t angleInDegrees, uint16_t minAngleDegrees, uint16_t maxAngleDegrees, uint16_t minPulseWidht, uint16_t maxPulseWidht)
{
    return map(angleInDegrees, minAngleDegrees, maxAngleDegrees, minPulseWidht, maxPulseWidht);
}

void disable_servo(gpio_num_t pin)
{
    ledcWrite((uint8_t)pin, DISABLED_SERVO);
}