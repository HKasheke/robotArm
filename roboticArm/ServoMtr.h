#ifndef SERVOMTH_H
#define SERVOMTH_H
#include <Servo.h>

class ServoMtr {
private:
  const short int DEFAULT_ANGLE = 135;

  const short int MIN_ANGLE = 90;
  const short int MAX_ANGLE = 180;
  short int angle = DEFAULT_ANGLE;
  int inputPinNum;
  int outputPinNum;

  Servo* servoObj;

public:
  ServoMtr(const unsigned short int inputPin, const unsigned short int outputPin, Servo* servo);
  void incAngle(int delta);
  void decAngle(int delta);
  void setAngle(const int angle);
  const int getAngle();
  void setInputPinNum(const int pinNum);
  const int getInputPinNum();
  void setOutputPinNum(const int pinNum);
  const int getOutputPinNum();
  int getDefaultAngle();
  Servo* getServoObj();
};

#endif
