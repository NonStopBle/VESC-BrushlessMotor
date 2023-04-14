#include "VESC-BrushlessMotor.h"

union Int32ToByte
{
  uint32_t _asInt = 0;
  uint8_t _asByte[4];
};

union Int16ToByte
{
  uint16_t _asInt = 0;
  uint8_t _asByte[2];
};

Int32ToByte getMotorSpeed_CV;
Int16ToByte getMotorCurrent_CV , getMotorDutyCycle_CV;
Int32ToByte setMotorSpeed_CV , setMotorCurrent_CV , setMotorCurrentHandBrake_CV
, setMotorCurrentREL_CV , setMotorCurrentBrakeREL_CV , setMotorCurrentBrake_CV
, setMotorDutyCycle_CV , setMotorPosition_CV;



CAN_message_t canBusMsgGlobal;

VESCBrushlessMotor :: VESCBrushlessMotor (uint16_t _VESCid) : VESCid(_VESCid) {}

void VESCBrushlessMotor :: initCanBus(uint32_t _baudrate , uint16_t _setMaxMb ) {
  Serial.println("CAN-BUS : INITIALIZING");
  
  delay(2000);

  _CanBus.begin();
  _CanBus.setBaudRate(_baudrate);
  _CanBus.setMaxMB(_setMaxMb);
  _CanBus.enableFIFO();
  _CanBus.enableFIFOInterrupt();

  _CanBus.onReceive([this](const CAN_message_t &msg) { this->canMessage(msg); });


  Serial.println("CAN-BUS : INITIALIZED");
  Serial.println("CAN-BUS : BAUDRATE = " + String(_baudrate));
  Serial.println("CAN-BUS : MAIL-BOX = " + String(_setMaxMb));

}

void VESCBrushlessMotor::canMessage(const CAN_message_t& msg) {
    canBusMsgGlobal = msg;
}

void VESCBrushlessMotor::PollCanBus(){
  _CanBus.events();
}

void VESCBrushlessMotor :: setMotorSpeed(int32_t value) {
  static unsigned long timeoutMicros = 0;

  CAN_message_t cmd;

  cmd.id  = VESCBrushlessMotor::VESCid | (CAN_PACKET_SET_RPM << 8);
  cmd.flags.extended = 1;

  if (micros() - timeoutMicros >= 250) {
    setMotorSpeed_CV._asInt = (value * 7);
    cmd.buf[0] = setMotorSpeed_CV._asByte[3];
    cmd.buf[1] = setMotorSpeed_CV._asByte[2];
    cmd.buf[2] = setMotorSpeed_CV._asByte[1];
    cmd.buf[3] = setMotorSpeed_CV._asByte[0];
    _CanBus.write(cmd);
    timeoutMicros = micros();
  }
}

void VESCBrushlessMotor :: setMotorCurrent(int32_t value) {
  static unsigned long timeoutMicros = 0;

  CAN_message_t cmd;

  cmd.id = VESCBrushlessMotor::VESCid | (CAN_PACKET_SET_CURRENT << 8);
  cmd.flags.extended = 1;

  if (micros() - timeoutMicros >= 250) {
    setMotorCurrent_CV._asInt = (value * 1000);

    cmd.buf[0] = setMotorCurrent_CV._asByte[3];
    cmd.buf[1] = setMotorCurrent_CV._asByte[2];
    cmd.buf[2] = setMotorCurrent_CV._asByte[1];
    cmd.buf[3] = setMotorCurrent_CV._asByte[0];

    _CanBus.write(cmd);

    timeoutMicros = micros();
  }
}

void VESCBrushlessMotor :: setMotorCurrentHandBrake(int32_t value) {

  static unsigned long timeoutMicros = 0;

  CAN_message_t cmd;

  cmd.id = VESCBrushlessMotor::VESCid | (CAN_PACKET_SET_CURRENT_HANDBRAKE << 8);
  cmd.flags.extended = 1;

  if (micros() - timeoutMicros >= 250) {
    setMotorCurrentHandBrake_CV._asInt = (value * 1000);

    cmd.buf[0] = setMotorCurrentHandBrake_CV._asByte[3];
    cmd.buf[1] = setMotorCurrentHandBrake_CV._asByte[2];
    cmd.buf[2] = setMotorCurrentHandBrake_CV._asByte[1];
    cmd.buf[3] = setMotorCurrentHandBrake_CV._asByte[0];

    _CanBus.write(cmd);

    timeoutMicros = micros();
  }
}

void VESCBrushlessMotor :: setMotorCurrentBrakeREL(int32_t value) {
  static unsigned long timeoutMicros = 0;

  CAN_message_t cmd;

  cmd.id  = VESCBrushlessMotor::VESCid | (CAN_PACKET_SET_CURRENT_BRAKE_REL << 8);
  cmd.flags.extended = 1;

  if (micros() - timeoutMicros >= 250) {
    setMotorCurrentBrakeREL_CV._asInt = (value * 100000);
    cmd.buf[0] = setMotorCurrentBrakeREL_CV._asByte[3];
    cmd.buf[1] = setMotorCurrentBrakeREL_CV._asByte[2];
    cmd.buf[2] = setMotorCurrentBrakeREL_CV._asByte[1];
    cmd.buf[3] = setMotorCurrentBrakeREL_CV._asByte[0];
    _CanBus.write(cmd);
    timeoutMicros = micros();
  }
}

void VESCBrushlessMotor :: setMotorCurrentREL (int32_t value) {
  static unsigned long timeoutMicros = 0;

  CAN_message_t cmd;

  cmd.id  = VESCBrushlessMotor::VESCid | (CAN_PACKET_SET_CURRENT_REL << 8);
  cmd.flags.extended = 1;

  if (micros() - timeoutMicros >= 250) {
    setMotorCurrentREL_CV._asInt = (value * 100000);
    cmd.buf[0] = setMotorCurrentREL_CV._asByte[3];
    cmd.buf[1] = setMotorCurrentREL_CV._asByte[2];
    cmd.buf[2] = setMotorCurrentREL_CV._asByte[1];
    cmd.buf[3] = setMotorCurrentREL_CV._asByte[0];
    _CanBus.write(cmd);
    timeoutMicros = micros();
  }
}

void VESCBrushlessMotor :: setMotorCurrentBrake(int32_t value) {
  static unsigned long timeoutMicros = 0;

  CAN_message_t cmd;

  cmd.id  = VESCBrushlessMotor::VESCid | (CAN_PACKET_SET_CURRENT_BRAKE << 8);
  cmd.flags.extended = 1;

  if (micros() - timeoutMicros >= 250) {
    setMotorCurrentBrake_CV._asInt = (value * 1000);

    cmd.buf[0] = setMotorCurrentBrake_CV._asByte[3];
    cmd.buf[1] = setMotorCurrentBrake_CV._asByte[2];
    cmd.buf[2] = setMotorCurrentBrake_CV._asByte[1];
    cmd.buf[3] = setMotorCurrentBrake_CV._asByte[0];

    _CanBus.write(cmd);

    timeoutMicros = micros();
  }
}

void VESCBrushlessMotor :: setMotorDuty(int32_t value) {
  static unsigned long timeoutMicros = 0;

  CAN_message_t cmd;

  cmd.id  = VESCBrushlessMotor::VESCid | (CAN_PACKET_SET_DUTY << 8);
  cmd.flags.extended = 1;

  if (micros() - timeoutMicros >= 250) {
    setMotorDutyCycle_CV._asInt = (value * 1000);

    cmd.buf[0] = setMotorDutyCycle_CV._asByte[3];
    cmd.buf[1] = setMotorDutyCycle_CV._asByte[2];
    cmd.buf[2] = setMotorDutyCycle_CV._asByte[1];
    cmd.buf[3] = setMotorDutyCycle_CV._asByte[0];

    _CanBus.write(cmd);

    timeoutMicros = micros();
  }
}


void VESCBrushlessMotor :: setMotorPosition(int32_t value) {
  static unsigned long timeoutMicros = 0;

  CAN_message_t cmd;

  cmd.id  = VESCBrushlessMotor::VESCid | (CAN_PACKET_SET_POS << 8);
  cmd.flags.extended = 1;

  if (micros() - timeoutMicros >= 250) {
    setMotorPosition_CV._asInt = (value * 1000);

    cmd.buf[0] = setMotorPosition_CV._asByte[3];
    cmd.buf[1] = setMotorPosition_CV._asByte[2];
    cmd.buf[2] = setMotorPosition_CV._asByte[1];
    cmd.buf[3] = setMotorPosition_CV._asByte[0];

    _CanBus.write(cmd);

    timeoutMicros = micros();
  }

 
}
 
int32_t VESCBrushlessMotor :: getMotorSpeed(){
   if(canBusMsgGlobal.id == (VESCBrushlessMotor::VESCid | CAN_PACKET_STATUS_BOARDCAST << 8)){
      getMotorSpeed_CV._asByte[0] = canBusMsgGlobal.buf[3];
      getMotorSpeed_CV._asByte[1] = canBusMsgGlobal.buf[2];
      getMotorSpeed_CV._asByte[2] = canBusMsgGlobal.buf[1];
      getMotorSpeed_CV._asByte[3] = canBusMsgGlobal.buf[0];

      return (getMotorSpeed_CV._asInt / 7);
    }
    else{
      return (getMotorSpeed_CV._asInt / 7);  
    }
}

int16_t VESCBrushlessMotor :: getMotorCurrent(){
   if(canBusMsgGlobal.id == (VESCBrushlessMotor::VESCid | CAN_PACKET_STATUS_BOARDCAST << 8)){
      getMotorCurrent_CV._asByte[0] = canBusMsgGlobal.buf[5];
      getMotorCurrent_CV._asByte[1] = canBusMsgGlobal.buf[4];
      return(getMotorCurrent_CV._asInt / 10);
    }
    else{
      return(getMotorCurrent_CV._asInt / 10);
    }
}

int16_t VESCBrushlessMotor:: getMotorDutyCycle(){
  if(canBusMsgGlobal.id == (VESCBrushlessMotor::VESCid | CAN_PACKET_STATUS_BOARDCAST << 8)){
      getMotorDutyCycle_CV._asByte[0] = canBusMsgGlobal.buf[7];
      getMotorDutyCycle_CV._asByte[1] = canBusMsgGlobal.buf[6];
      return(getMotorDutyCycle_CV._asInt / 1000.0);
  }
  else{
      return(getMotorDutyCycle_CV._asInt / 1000.0);
  }
}