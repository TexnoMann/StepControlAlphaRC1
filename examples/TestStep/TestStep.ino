#include <StepControl.h>
 //(1-EnablePin, 2-StepPin, 3-DirPin)
  StepControl stepper(38,54,55);
void setup() {
  stepper.setSpeed(3000); скорость в град/сек
}

void loop() {
stepper.moveTo(4000);//вращать 4000 градусов вперед
delay(1000)
stepper.moveTo(-4000);//вращать 4000 градусов назад
delay(1000);
}
