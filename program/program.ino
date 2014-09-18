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
    go(speed, speed);
    direction = 0;
    return; 
  }
  
  if (left || direction == 1) {
    go(speed, -speed / 2);
    direction = 1;
  }
  if (right || direction == -1) {
    go(-speed / 2, speed);
    direction = -1;
  }
}

void go(int lSpeed, int rSpeed) {
  mLeft.write(90 - lSpeed);
  mRight.write(90 + rSpeed);
}

