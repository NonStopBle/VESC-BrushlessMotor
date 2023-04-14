#include <VESC-BrushlessMotor.h>

// Define Canbus ports number
#define CAN_NUMBER CAN1

// Define the VESC motor object with the VESC ID
VESCBrushlessMotor Motor_A(110);

void setup() {
  // Initialize the canbus for the motor
  // By default baudrate has been set at 1000000 bps and 16 MailBox
  Motor_A.initCanBus(1000000 , 16);
}

void loop() {
  // Get motor data from the VESC
  Motor_A.PollCanBus();

  // Print motor data to the serial monitor
  Serial.print("Speed: ");
  Serial.print(Motor_A.getMotorSpeed());
  Serial.print(" RPM, Current: ");
  Serial.print(Motor_A.getMotorCurrent());
  Serial.print(" A, Duty Cycle: ");
  Serial.print(Motor_A.getMotorDutyCycle());
  Serial.println(" %");

  // Set motor parameters as needed
  
  // Set different motor parameters
  //Motor_A.setMotorSpeed(100);  // set motor a speed unit rpm (RPM) this library already convert from ERPM to RPM
  //Motor_A.setMotorCurrent(2); //set motor current unit ampere (A)
  //Motor_A.setMotorCurrentREL(2); //set motor current unit ampere (A)
  //Motor_A.setMotorCurrentBrakeREL(10);  // set motor current handbrake rel unit percentage (%)
  //Motor_A.setMotorCurrentBrake(5); // set motor current brake unit amepere (A)
  //Motor_A.setMotorCurrentHandBrake(10); // set motor current handbrake unit amepere (A)
  //Motor_A.setMotorDuty(10); // set motor by duty cycle unit percentage (%)
}
