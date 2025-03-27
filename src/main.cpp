
#include "servos_new_version/Servo.h"

EasyServo servo1(Servo::PORTA_1);

void setup() {

}

void loop() {
  servo1.setPosition(0);
  delay(1000);
  servo1.setPosition(90);
  delay(1000);
  servo1.setPosition(180);
  delay(1000);
  servo1.setPosition(270);
  delay(1000);
}