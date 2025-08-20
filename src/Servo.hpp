#ifndef SERVOOS_H
#define SERVOOS_H

#include "master.h"

namespace Config_Servo {
    enum Port {
        PORTA_1 = GPIO_NUM_2,
        PORTA_2 = GPIO_NUM_26,
        PORTA_3 = GPIO_NUM_27,
    };
}

class EasyServo {
    public:
        explicit EasyServo(Config_Servo::Port entrada, int minAngleDegrees, int maxAngleDegrees, int minWidht_us, int maxWidht_us, int frequency);
        explicit EasyServo(Config_Servo::Port entrada, int minAngleDegrees, int maxAngleDegrees);
        explicit EasyServo(Config_Servo::Port entrada);
        ~EasyServo();
        void setPosition(int angleInDegrees);
        int getPosition();
        void disableServo();
    private:
        const gpio_num_t PIN;
        const unsigned int FREQUENCY;
        const unsigned int MIN_PULSE;
        const unsigned int MAX_PULSE;
        const int MIN_ANGLE;
        const int MAX_ANGLE;

        uint16_t currentAngle;

        const static int DEFAULT_MIN_ANGLE = 0;
        const static int DEFAULT_MAX_ANGLE = 270;
        const static int DEFAULT_MIN_PULSE = 500;
        const static int DEFAULT_MAX_PULSE = 2500; 
        const static int DEFAULT_FREQUENCY = 50; 
};

#endif
