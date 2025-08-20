#include "Servo.hpp"
#include "servo_low_level/servo-low-level.hpp"

EasyServo::EasyServo(Config_Servo::Port entrada, int minAngleDegrees, int maxAngleDegrees, int minWidht_us, int maxWidht_us, int frequency) : PIN((gpio_num_t)entrada), 
                                                                                                                                            MIN_ANGLE(minAngleDegrees), 
                                                                                                                                            MAX_ANGLE(maxAngleDegrees),
                                                                                                                                            MIN_PULSE(minWidht_us),
                                                                                                                                            MAX_PULSE(maxWidht_us),
                                                                                                                                            FREQUENCY(frequency)
{
    configure_servo((gpio_num_t)entrada, FREQUENCY);
}

EasyServo::EasyServo(Config_Servo::Port entrada, int minAngleDegrees, int maxAngleDegrees) : 
EasyServo(entrada, minAngleDegrees, maxAngleDegrees, DEFAULT_MIN_PULSE, DEFAULT_MAX_PULSE, DEFAULT_FREQUENCY)
{

}

EasyServo::EasyServo(Config_Servo::Port entrada) : EasyServo(entrada, DEFAULT_MIN_ANGLE, DEFAULT_MAX_ANGLE)
{
}

EasyServo::~EasyServo()
{
    disableServo();
    // need to detach pin
}

void EasyServo::setPosition(int angleInDegrees)
{
    if(!DS_ENABLE) return;
    
    currentAngle = angleInDegrees;
    write_angle_in_degrees(PIN, angleInDegrees, MIN_ANGLE, MAX_ANGLE, MIN_PULSE, MAX_PULSE, FREQUENCY);
}

int EasyServo::getPosition()
{
    return currentAngle;
}

void EasyServo::disableServo()
{
    disable_servo(PIN);
}
