#include "Arduino.h"
#include "FlexCAN_T4.h"

#define CAN_PACKET_SET_DUTY 0x00          // Duty Cycle Unit %/100  / Range (-1.0-1.0)
#define CAN_PACKET_SET_CURRENT 0x01       // Motor Current Unit A / Range (-MotorMax to MotorMax)
#define CAN_PACKET_SET_CURRENT_BRAKE 0x02 // Braking Current A Range (-MotorMax to MotorMax)
#define CAN_PACKET_SET_RPM 0x03           // Set RPM  Unit RPM Range (-Max_RPM to Max_RPM)
#define CAN_PACKET_SET_POS 0x04           // Set POS Unit Degrees Ranges (0 to 360)

#define CAN_PACKET_STATUS_BOARDCAST 0x09
#define CAN_PACKET_SET_CURRENT_REL 0x10
#define CAN_PACKET_SET_CURRENT_BRAKE_REL 0x11
#define CAN_PACKET_SET_CURRENT_HANDBRAKE 0x12
#define CAN_PACKET_SET_CURRENT_HANDBRAKE_REL 0x13

#ifndef CAN_NUMBER
#define CAN_NUMBER CAN1
#endif

#define VESC_MOTOR_MAX 4

class VESCBrushlessMotor
{
  public:
    VESCBrushlessMotor();
    
    
    VESCBrushlessMotor(uint16_t _VESCid);
    

    void initCanBus(uint32_t _baudrate = 1000000  , uint16_t _setMaxMb = 16 );

    void setMotorSpeed(int32_t value);
    void setMotorDuty(int32_t value);
    void setMotorPosition(int32_t value);

    void setMotorCurrentBrake(int32_t value);
    void setMotorCurrentBrakeREL(int32_t value);

    void setMotorCurrent(int32_t value);
    void setMotorCurrentREL(int32_t value);

    void setMotorCurrentHandBrake(int32_t value);
    void setMotorCurrentHandBrakeREL(int32_t value);

    int32_t getMotorSpeed();
    int16_t getMotorCurrent();
    int16_t getMotorDutyCycle();

    void canMessage(const CAN_message_t& msg);
    void PollCanBus();

  private:
    uint8_t VESCid = 0;
    
    FlexCAN_T4<CAN_NUMBER, RX_SIZE_256, TX_SIZE_16> _CanBus;
};

//noob library by rezier