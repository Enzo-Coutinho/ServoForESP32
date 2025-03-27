#ifndef servo_low_level_h
#define servo_low_level_h

#include "esp32-hal-log.h"
#include "Arduino.h"

class ServoLL
{
  public:
    void attach(int pin, int minPulse, int maxPulse, int channel);
    void attach(int pin);
  private:
    static const int ANGLE_MAX = 270;
    static const int ANGLE_MIN = 0;
    static const int MIN_PULSE = 500;
    static const int MAX_PULSE = 2500; 
    static const int FREQUENCY = 50; 
    static const int RESOLUTION_BITS = 10;
    int usToTicks(int usec);
	int ticksToUs(int ticks);
};


#endif