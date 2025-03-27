#include "servo-low-level.h"

void ServoLL::attach(int pin, int min, int max, int channel)
{
    this->pin = pin;

    log_d("Attempting to Attach servo on pin=%d min=%d max=%d", pin,min,max);

    // min/max checks 
    if (min < MIN_PULSE)          // ensure pulse width is valid
        min = MIN_PULSE;
    if (max > MAX_PULSE)
        max = MAX_PULSE;

    // Set up this channel
    // if you want anything other than default timer width, you must call setTimerWidth() before attach

    if(ledcAttachChannel(pin, FREQUENCY, RESOLUTION_BITS, channel))
        log_i("Successful Servo Attached on pin(%d), freq(%d), resl(%d) and channel(%d)", pin, FREQUENCY, RESOLUTION_BITS, channel);
    else
        log_e("Successful Servo don't Attached on pin(%d), freq(%d), resl(%d) and channel(%d)", pin, FREQUENCY, RESOLUTION_BITS, channel);
}

void ServoLL::attach(int pin, int channel)
{
    attach(pin, MIN_PULSE, MAX_PULSE, channel);
}

void ServoLL::writeAngleDegrees(int angleInDegrees)
{
    writeMicroseconds(angleToUs(angleInDegrees));
}

void ServoLL::writeMicroseconds(int microseconds)
{
    writeTicks(usToTicks(microseconds));  // convert to ticks
}

void ServoLL::writeTicks(int ticks)
{
    ledcWrite(pin, ticks);
}

int ServoLL::usToTicks(int usec)
{
    return (int)((double)usec / ((double)REFRESH_USEC / (double)this->TIMER_WIDTH_TICKS)*(((double)FREQUENCY)/50.0));
}

int ServoLL::ticksToUs(int ticks)
{
    return (int)((double)ticks * ((double)REFRESH_USEC / (double)this->TIMER_WIDTH_TICKS)/(((double)FREQUENCY)/50.0));
}

int ServoLL::angleToUs(int angleInDegrees)
{
    return map(angleInDegrees, ANGLE_MIN_DEGREES, ANGLE_MAX_DEGREES, MIN_PULSE, MAX_PULSE);
}