#include <Servo.h> 
Servo mLeft, mRight;
int speed = 90;
void setup() {
  mLeft.attach(12);
  mRight.attach(13);
}
void loop() {
  if (digitalRead(9)) {
    go(speed, speed);
  } else if (digitalRead(11)) {
    go(speed, -speed / 2);
  } else if (digitalRead(10)) {
    go(-speed / 2, speed);
  }
}
void go(int lSpeed, int rSpeed) {
  mLeft.write(90 - lSpeed);
  mRight.write(90 + rSpeed);
}

