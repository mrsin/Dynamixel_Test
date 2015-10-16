#include <DynamixelSerial1.h>

int Temperature,Voltage,Position; 

#define SERVO_ID 254

void setup(){
  Serial.begin(9600);              // Begin Serial Comunication
  Dynamixel.begin(500000, 2);  // Inicialize the servo at 1Mbps and Pin Control 2
  delay(1000);
}

void loop(){
  Temperature = Dynamixel.readTemperature(SERVO_ID); // Request and Print the Temperature
  Voltage = Dynamixel.readVoltage(SERVO_ID);         // Request and Print the Voltage
  Position = Dynamixel.readPosition(SERVO_ID);       // Request and Print the Position 
 
  Dynamixel.move(SERVO_ID,random(200,800));  // Move the Servo radomly from 200 to 800
 
  Serial.print(" *** Temperature: ");   // Print the variables in the Serial Monitor
  Serial.print(Temperature);
  Serial.print(" Celcius  Voltage: ");
  Serial.print(Voltage);
  Serial.print("  Volts   Position: ");
  Serial.print(Position);
  Serial.println(" of 1023 resolution");
  
  delay(1000);
}
