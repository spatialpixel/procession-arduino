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

String lastLedValue = "";

void setup() {
  Serial.begin(115200);
  while (!Serial);

  pinMode(2, OUTPUT); // LED pin
  pinMode(4, INPUT);  // Button pin
}

void loop() {
  procession.loop();

  int value = digitalRead(4);

  if (lastValue == 0 && value == 1) {
    procession.publish("arduino.button", "down");
    lastValue = value;
  } else if (lastValue == 1 && value == 0) {
    procession.publish("arduino.button", "up");
    lastValue = value;
  }


  String ledValue = procession.subscribe("led");

  if (ledValue != lastLedValue) {
    if (ledValue == "on") {
      digitalWrite(2, HIGH);
    } else if (ledValue == "off") {
      digitalWrite(2, LOW);
    }

    lastLedValue = ledValue;
  }

  delay(50);
}
