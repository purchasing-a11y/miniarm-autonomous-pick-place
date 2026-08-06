#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

int current1 = 26;
int current2 = 88;
int current3 = 86;
int current4 = 92;
int current5 = 89;

void moveToPose(
  int target1,
  int target2,
  int target3,
  int target4,
  int target5
) {
  int start1 = current1;
  int start2 = current2;
  int start3 = current3;
  int start4 = current4;
  int start5 = current5;

  const int steps = 100;

  float stepSize1 = (target1 - start1) / (float)steps;
  float stepSize2 = (target2 - start2) / (float)steps;
  float stepSize3 = (target3 - start3) / (float)steps;
  float stepSize4 = (target4 - start4) / (float)steps;
  float stepSize5 = (target5 - start5) / (float)steps;

  for (int i = 1; i <= steps; i++) {
    float position1 = start1 + stepSize1 * i;
    float position2 = start2 + stepSize2 * i;
    float position3 = start3 + stepSize3 * i;
    float position4 = start4 + stepSize4 * i;
    float position5 = start5 + stepSize5 * i;

    servo1.write(180 - (int)position1);
    servo2.write((int)position2);
    servo3.write((int)position3);
    servo4.write((int)position4);
    servo5.write((int)position5);

    delay(15);
  }

  current1 = target1;
  current2 = target2;
  current3 = target3;
  current4 = target4;
  current5 = target5;
}

void setup() {
  servo1.attach(7);
  servo2.attach(6);
  servo3.attach(5);
  servo4.attach(4);
  servo5.attach(3);

  servo1.write(180 - 26);
  servo2.write(88);
  servo3.write(86);
  servo4.write(92);
  servo5.write(89);

  delay(1000);

}

void loop() {
  moveToPose(26, 88, 86, 92, 89);
  delay(1000);

  moveToPose(33, 0, 106, 180, 84);
  delay(1000);

  moveToPose(87, 0, 106, 180, 84);
  delay(1000);

  moveToPose(78, 31, 60, 180, 26);
  delay(1000);

  moveToPose(51, 17, 79, 180, 24);
  delay(1000);
}