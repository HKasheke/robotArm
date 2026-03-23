Arm::Arm() {
  Serial.begin(9600);
  //Attach motors to pins to be able to use later
  motors[BASE].getServoObj()->attach(motors[BASE].getOutputPinNum());
  motors[SHOULDER].getServoObj()->attach(motors[SHOULDER].getOutputPinNum());
  motors[ELBOW].getServoObj()->attach(motors[ELBOW].getOutputPinNum());
  motors[WRIST].getServoObj()->attach(motors[WRIST].getOutputPinNum());
  //motors[PINCER].getServoObj()->attach(motors[PINCER].getOutputPinNum());
 

  //Write default angle to motors on startup
  motors[BASE].getServoObj()->write(motors[BASE].getDefaultAngle());
  motors[SHOULDER].getServoObj()->write(motors[SHOULDER].getDefaultAngle());
  motors[ELBOW].getServoObj()->write(motors[ELBOW].getDefaultAngle());
  motors[WRIST].getServoObj()->write(motors[WRIST].getDefaultAngle());
  //motors[PINCER].getServoObj()->write(motors[PINCER].getDefaultAngle());
}

void Arm::begin() {
  int baseCntrStickVal = analogRead(motors[BASE].getInputPinNum());
  int shoulderCntrStickVal = analogRead(motors[SHOULDER].getInputPinNum());
  int elbowCntrStickVal = analogRead(motors[ELBOW].getInputPinNum());
  int wristCntrStickVal = analogRead(motors[WRIST].getInputPinNum());
  //int pinserCntrStickVal = analogRead(motors[PINCER].getInputPinNum());

  Serial.print("Base stick: ");
  Serial.print(baseCntrStickVal);
  Serial.print("  shoulder stick: ");
  Serial.print(shoulderCntrStickVal);
  while (1) {

    short int baseAngleStick;
    short int shoulderAngleStick;
    short int elbowAngleStick;
    short int wristAngleStick;
    //short int pincerAngleStick;
    short int delta = 0;

    baseAngleStick = analogRead(motors[BASE].getInputPinNum());
    shoulderAngleStick = analogRead(motors[SHOULDER].getInputPinNum());
    elbowAngleStick = analogRead(motors[ELBOW].getInputPinNum());
    wristAngleStick = analogRead(motors[WRIST].getInputPinNum());
    //pincerAngleStick = analogRead(motors[PINCER].getInputPinNum());

    this->stickRead(&motors[BASE], baseAngleStick, baseCntrStickVal);
    this->stickRead(&motors[SHOULDER], shoulderAngleStick, shoulderCntrStickVal);
    this->stickRead(&motors[ELBOW], elbowAngleStick, elbowCntrStickVal);
    this->stickRead(&motors[WRIST], wristAngleStick, wristCntrStickVal);
    //this->stickRead(&motors[PINCER], pincerAngleStick, pinserCntrStickVal);

    /*Serial.print("Delta: ");
    Serial.println(delta);
    Serial.print("Angle: ");
    Serial.println(baseMotor.getAngle());*/

    delay(30);
  }
}

void Arm::stickRead(ServoMtr* motor, int analogStickValue, int midPoint) {
  int delta = 0;
  int deadzoneHighEnd = midPoint + 4;
  int deadzoneLowEnd = midPoint - 4;
  if (analogStickValue > deadzoneHighEnd) {
    delta = map(analogStickValue, deadzoneHighEnd, 1023, 0, 5);
    motor->incAngle(delta);
  } else if (analogStickValue < deadzoneLowEnd) {
    delta = map(analogStickValue, deadzoneLowEnd, 0, 0, 5);
    motor->decAngle(delta);
  } /**/
  motor->getServoObj()->write(motor->getAngle());
}
