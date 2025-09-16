#include "ProcessionUtil.h"
#include <ProcessionArduino.h>


ProcessionArduino::ProcessionArduino() {

}

ProcessionArduino::~ProcessionArduino() {

}

/* -----------------------------------------------------------------
   send
   ----------------------------------------------------------------- */
void ProcessionArduino::send(const String &topic,
                             const String &value) {
    if (!Serial) { return; }

    String payload = "{\"data." + topic + "\":\"" + value + "\"}";
    Serial.println(payload);
    Serial.flush();
}

String ProcessionArduino::receive() {
  if (!Serial || Serial.available() == 0) {
    return String();
  }

  String inputStr = Serial.readStringUntil('\n');
  return ProcessionUtil::processProcessionMessage(inputStr);
}
