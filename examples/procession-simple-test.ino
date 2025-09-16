/**
* An example showing how to link Procession with an Arduino.
*
* This shows how Procession can send messages to and receive messages from an Arduino.
* It requires two basic hardware elements:
* 1. an LED on pin 2
* 2. a button or switch on pin 4
*/

#include <ProcessionArduino.h>

ProcessionArduino procession;

// Keep track of the last button value so we can check for changes.
int lastValue = 0;

void setup() {
  Serial.begin(115200);
  while (!Serial);

  pinMode(2, OUTPUT); // LED pin
  pinMode(4, INPUT);  // Button pin
}

void loop() {
  int value = digitalRead(4);

  if (lastValue == 0 && value == 1) {
    procession.send("arduino.button", "down");
    lastValue = value;
  } else if (lastValue == 1 && value == 0) {
    procession.send("arduino.button", "up");
    lastValue = value;
  }


  String processionMessage = procession.receive();

  if (processionMessage.length() > 0) {
    if (processionMessage == "arduino.led=bright") {
      digitalWrite(2, HIGH);
    } else if (processionMessage == "arduino.led=off") {
      digitalWrite(2, LOW);
    } else if (processionMessage == "arduino.led=blink") {
      digitalWrite(2, HIGH);
      delay(250);
      digitalWrite(2, LOW);
    }
  }

  delay(50);
}
