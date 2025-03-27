#ifndef SERVOOS_H
#define SERVOOS_H

#include "Arduino.h"

enum PortaServo {
  PORTA_1_SERVO = 2,
  PORTA_2_SERVO = 26,
  PORTA_3_SERVO = 27,
};

class Servo {
    public:
      Servo(PortaServo entrada);
      void setPosition(int positionInDegrees);
      int getPosition();
    private:
      static const int ANGLE_MAX = 270;
      static const int ANGLE_MIN = 0;
      static const int MIN_PULSE = 500;
      static const int MAX_PULSE = 2500; 
      static const int FREQUENCY = 50;
      int channel;
      int signalPin;
};
#endif
