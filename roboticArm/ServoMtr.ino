#include "ServoMtr.h"

ServoMtr::ServoMtr(const int inputPin, const int outputPin, Servo* servo)
  : inputPinNum(inputPin),
    outputPinNum(outputPin),
    servoObj(servo) {
}

void ServoMtr::incAngle(int delta) {
  this->angle += delta;

  if (this->angle > MAX_ANGLE)
    this->angle = MAX_ANGLE;
}

void ServoMtr::decAngle(int delta) {
  this->angle -= delta;

  if (this->angle < MIN_ANGLE)
    this->angle = MIN_ANGLE;
}

void ServoMtr::setAngle(const int angle) {
  this->angle = angle;
}

const int ServoMtr::getAngle() {
  return this->angle;
}

void ServoMtr::setInputPinNum(const int pinNum) {
  this->inputPinNum = pinNum;
}

const int ServoMtr::getInputPinNum() {
  return this->inputPinNum;
}

void ServoMtr::setOutputPinNum(const int pinNum) {
  this->outputPinNum = pinNum;
}

const int ServoMtr::getOutputPinNum() {
  return this->outputPinNum;
}

int ServoMtr::getDefaultAngle() {
  return this->DEFAULT_ANGLE;
}

Servo* ServoMtr::getServoObj() {
  return this->servoObj;
}