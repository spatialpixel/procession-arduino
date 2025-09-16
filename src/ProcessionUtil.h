#ifndef PROCESSION_UTIL_H
#define PROCESSION_UTIL_H

#include <Arduino.h>


namespace ProcessionUtil {
  /**
   * @brief Given an incoming message from Procession, process it for ease of use.
   */
  String processProcessionMessage(String message);

  /**
   * @brief A utility for helping add a debounce behavior to hardware events.
   */
  class Debouncer {
  public:
    int debounceTime;

    unsigned long lastDebounceTime;
    unsigned long currentTime;
    unsigned long diff;

    Debouncer()
      : debounceTime(75), lastDebounceTime(0), currentTime(0), diff(0) {
    }
    Debouncer(int time)
      : debounceTime(time), lastDebounceTime(0), currentTime(0), diff(0) {
    }

    void reset () {
      lastDebounceTime = millis();
    }

    bool ready () {
      diff = millis() - lastDebounceTime;
      return diff >= debounceTime;
    }
  };
}

#endif // PROCESSION_UTIL_H
