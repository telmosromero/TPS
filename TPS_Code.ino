/*
  ReadAnalogVoltage

  Reads an analog input on pin 0, converts it to voltage, and prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/ReadAnalogVoltage
*/

// the setup routine runs once when you press reset:

#include <LiquidCrystal.h>
//this library allows Arduino to work on LCD

 LiquidCrystal lcd(1, 2, 4, 5, 6, 7);
// defines LCD and its pin.
int ledPin = 13;
// led is connected to pin 8

float voltageLimit = 2;
//THIS IS THE VOLTAGE LIMIT; SET TO LIMIT

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
   lcd.begin(16, 2);
  pinMode(ledPin, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);
  // print out the value you read:

 // char voltage_str[10];
 // dtostrf(voltage, 5, 2, voltage_str); // convert voltage to string with 2 decimal places
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(voltage); // print the voltage string
  lcd.print(" V");
 
 if (voltage > voltageLimit) {
   digitalWrite(ledPin, HIGH);
   //will turn on led
   digitalWrite(ledPin, LOW);
   //turns led off
 }
  delay(3000);
 
}


