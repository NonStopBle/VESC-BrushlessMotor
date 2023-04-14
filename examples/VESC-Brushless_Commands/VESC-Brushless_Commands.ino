#include <VESC-BrushlessMotor.h>

// Define a VESCBrushlessMotor object with the VESC ID
// You can find the VESC ID in the VESC Tool
VESCBrushlessMotor Motor_A(110);

void setup() {
  // Initialize the CAN bus
  Motor_A.initCanBus();
}

void loop() {
  // Poll the CAN bus for incoming data
  Motor_A.PollCanBus();

  // Set the motor speed to 100 RPM
  Motor_A.setMotorSpeed(100);

  // Set the motor current to 2 A
  //Motor_A.setMotorCurrent(2);

  // Set the motor duty cycle to 10%
  //Motor_A.setMotorDuty(10);

  // Print the motor speed, current, and duty cycle to the Serial Monitor
  Serial.print("Speed : " + String(Motor_A.getMotorSpeed()) + String(" RPM"));
  Serial.print(" , ");
  Serial.print("Current : " + String(Motor_A.getMotorCurrent()) + String(" A"));
  Serial.print(" , ");
  Serial.println("Duty Cycle : " + String(Motor_A.getMotorDutyCycle()) + String(" %"));
}
