#ifndef PROCESSION_ARDUINO_H
#define PROCESSION_ARDUINO_H

#include "ProcessionUtil.h"
#include <Arduino.h>


class ProcessionArduino {
public:
  explicit ProcessionArduino();
  ~ProcessionArduino();

  /**
   * @brief Method for sending a topic/value message to Procession.
   *
   * This "topic" can then be "subscribed" to in a Procession sketch.
   *
   * @param topic  String describing the topic being sent sending.
   * @param value  Value associated with the topic.
   */
  void publish(const String &topic, const String &value);

  /**
   * @brief Reads messages from Procession.
   */
  String receive();

  void loop();

  String subscribe(const String& topic);

private:
  String _receivedMessage;
  String _receivedTopic;
  String _receivedValue;
};

#endif // PROCESSION_ARDUINO_H
