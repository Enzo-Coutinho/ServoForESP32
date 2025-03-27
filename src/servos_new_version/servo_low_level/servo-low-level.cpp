#include "servo-low-level.h"

void ServoLL::attach(int pin, int min, int max, int channel)
{
    log_d("Attempting to Attach servo on pin=%d min=%d max=%d", pin,min,max);

    // min/max checks 
    if (min < MIN_PULSE)          // ensure pulse width is valid
        min = MIN_PULSE;
    if (max > MAX_PULSE)
        max = MAX_PULSE;

    // Set up this channel
    // if you want anything other than default timer width, you must call setTimerWidth() before attach

    if(ledcAttachChannel(pin, FREQUENCY, RESOLUTION_BITS, channel))
    {
        log_i("Successful Servo Attached");
    }   // GPIO pin assigned to channel
}