#ifndef ARM_H
#define ARM_H

#include "ServoMtr.h"

class Arm {
private:
  const unsigned short int PINCER_MOTOR_PIN = 5;
  const unsigned short int WRIST_MOTOR_PIN = 6;
  const unsigned short int ELBOW_MOTOR_PIN = 9;
  const unsigned short int SHOULDER_MOTOR_PIN = 10;
  const unsigned short int BASE_MOTOR_PIN = 11;

  //const unsigned int PINCER_INPUT = A4;
  const unsigned int WRIST_INPUT = A3;
  const int ELBOW_INPUT = A2;
  const int SHOULDER_INPUT = A1;
  const int BASE_INPUT = A0;

  const unsigned short int DEFAULT_ANGLE = 90;

  enum MotorIndecies{
    BASE,
    SHOULDER,
    ELBOW,
    WRIST,
    PINCER
  };

  /*Servo pincerServo;*/
  Servo wristServo;
  Servo elbowServo;
  Servo shoulderServo;
  Servo baseServo;

  ServoMtr motors[4] = {ServoMtr(BASE_INPUT, BASE_MOTOR_PIN, &baseServo), ServoMtr(SHOULDER_INPUT, SHOULDER_MOTOR_PIN, &shoulderServo), ServoMtr(ELBOW_INPUT, ELBOW_MOTOR_PIN, &elbowServo), ServoMtr(WRIST_INPUT, WRIST_MOTOR_PIN, &wristServo)};
  void stickRead(ServoMtr* motor, int analogStickValue, int midPoint);

public:
  Arm();
  void begin();
};

#endif
