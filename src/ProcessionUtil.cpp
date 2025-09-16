#include "ProcessionUtil.h"
#include <Arduino.h>


String ProcessionUtil::processProcessionMessage(String message) {
  message.trim();

  if (message.length() == 0) {
    return String();
  }

  int start = 0;
  int end = message.length();

  // remove "data." from the start
  if (message.startsWith("data.")) {
    start += 5;
  }

  return message.substring(start, end);
}
