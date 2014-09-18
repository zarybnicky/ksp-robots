#include <Servo.h> 

Servo mLeft, mRight;

int speed = 90, on = 0, turning = 0, direction = 0;

void setup() 
{
  pinMode(7, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  mLeft.attach(12);
  mRight.attach(13);
  Serial.begin(9600); 
  //while (!Serial) {}
} 

void printDebug(){
  Serial.print(digitalRead(11));
  Serial.print(" ");
  Serial.print(digitalRead(9));
  Serial.print(" ");
  Serial.print(digitalRead(10));
  Serial.println();
}

void loop() {
  /*
  if (digitalRead(7)) {
    on = !on;
    delay(1000);
  }
  if(!on) {
    return;
  }
  */

  evade(digitalRead(11), digitalRead(9), digitalRead(10));
}

void evade(int left, int center, int right) {
  if (center) {
    if (turning > 0) {
      turning = turning / 2;
    } else {
      direction = 0;
    }
  } else {
    turning++; 
  }
  
  int backspeed = speed - speed * 2 * (turning / 100.0);
  backspeed = -speed / 2;
  
  if (turning == 0) {
    go(speed, speed);
    return;
  }

  if (turning > 100) {
    //TODO
    go(0, 0);
    return;
  }
  
  if (direction == 1 || right) {
    go(speed, backspeed);
    direction = 1;
  } else {
    go(backspeed, speed);
    direction = -1;
  }
}

void go(int lSpeed, int rSpeed) {
  mLeft.write(90 - lSpeed);
  mRight.write(90 + rSpeed);
}

