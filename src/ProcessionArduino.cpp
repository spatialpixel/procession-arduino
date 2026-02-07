#include "ProcessionUtil.h"
#include <ProcessionArduino.h>


ProcessionArduino::ProcessionArduino() : _receivedMessage(""), _receivedTopic(""), _receivedValue("") {

}

ProcessionArduino::~ProcessionArduino() {

}

/* -----------------------------------------------------------------
   send
   ----------------------------------------------------------------- */
void ProcessionArduino::publish(const String &topic,
                             const String &value) {
    if (!Serial) { return; }

    String payload = "{\"data." + topic + "\":\"" + value + "\"}";
    Serial.println(payload);
    Serial.flush();
}

void ProcessionArduino::loop() {
  if (!Serial || Serial.available() == 0) {
    _receivedTopic = "";
    _receivedValue = "";
    return;
  }

  String inputStr = Serial.readStringUntil('\n');

  _receivedMessage = ProcessionUtil::processProcessionMessage(inputStr);
  _receivedMessage.trim();

  bool parseSuccessful = ProcessionUtil::parseTopicValue(_receivedMessage, _receivedTopic, _receivedValue);
  if (!parseSuccessful) {
    _receivedTopic = "";
    _receivedValue = "";
  }
}

String ProcessionArduino::subscribe(const String& topic) {
  if (topic == _receivedTopic) {
    return _receivedValue;
  } else {
    return String();
  }
}
