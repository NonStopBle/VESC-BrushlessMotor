# VESC-BrushlessMotor

The VESC-BrushlessMotor library allows communication with the VESC Brushless Controller using an Arduino board. This library provides a simple and easy-to-use interface to control the VESC controller.

## Installation

1. Download the latest release from the [releases page](https://github.com/NonStopBle/VESC-BrushlessMotor/releases) as a `.zip` file.
2. In the Arduino IDE, go to `Sketch > Include Library > Add .ZIP Library`.
3. Select the downloaded `.zip` file and click "Open".

## Example

```cpp
#include <VESC-BrushlessMotor.h>

// Define the VESC motor object with the VESC ID
VESCBrushlessMotor Motor_A(110);

void setup() {
  // Initialize the canbus for the motor
  Motor_A.initCanBus();
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
```


# Functions
## Here's a list of the available functions in this library:

- `VESCBrushlessMotor(uint16_t vescID)` - Constructor function that initializes a new VESCBrushlessMotor object with the specified VESC ID.
- `initCanBus()` - Initializes the CAN bus communication.
- `PollCanBus()` - Polls the CAN bus for incoming data.
- `setMotorSpeed(int_32t speed)` - Sets the motor speed in RPM (revolutions per minute).
- `setMotorCurrent(int_16t current)` - Sets the motor current in A (amperes).
- `setMotorCurrentREL(int_16t current)` - Sets the motor current in relative units, ranging from -1 to 1.
- `setMotorCurrentBrake(int_16t current)` - Sets the motor current in A (amperes) for the brake.
- `setMotorCurrentBrakeREL(int_16t current)` - Sets the motor current in relative units, ranging from -1 to 1, for the brake.
- `setMotorCurrentHandBrake(int_16t current)` - Sets the motor current in A (amperes) for the handbrake.
- `setMotorDuty(int_16t duty)` - Sets the motor duty cycle in % (percentage).
- `getMotorSpeed()` - Returns the current motor speed in RPM (revolutions per minute).
- `getMotorCurrent()` - Returns the current motor current in A (amperes).
- `getMotorDutyCycle()` - Returns the current motor duty cycle in % (percentage).


# Starting and Stopping the VESC-BrushlessMotor
## To start the VESC-BrushlessMotor, you'll need to connect it to a power
