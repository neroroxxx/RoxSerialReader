/*
  https://www.RoxXxtar.com/bmc
  Licensed under the MIT license. See LICENSE file in the project root for full license information.

  Library to read one or more 74HC4067 or 74HC4051 analog-in multiplexers

  Rox74HC4067, this is a 16 pin analog-in multiplexer
  Rox74HC4051, this is a 8 pin analog-in multiplexer

  This library will read each pin of the mux and store it in RAM

  It was designed and tested for PJRC Teensy boards only.

  Use at your own risk.
*/

#ifndef RoxSerialReader_h
#define RoxSerialReader_h

#include <Arduino.h>

template <uint16_t buffSize>
class RoxSerialReader {
  public:
    RoxSerialReader(){
      memset(buff, 0, buffSize);
    }
    bool read(){
      char receivedChar;
      memset(buff, 0, buffSize);
      while(Serial.available() > 0 && !ready){
        receivedChar = Serial.read();
        // once a "new line" ch
        if((uint8_t)receivedChar != 10) {
          buff[counter] = receivedChar;
          counter++;
          if(counter >= buffSize){
            counter = buffSize-1;
          }
        } else {
          // set the last character as a EOL
          buff[counter] = 0;
          counter = 0;
          ready = true;
        }
      }
      if(ready){
        ready = false;
        return true;
      }
      return false;
    }
    bool match(const char * str){
      return (strcmp(buff, str)==0);
    }
    char * getBuffer(){
      return buff;
    }
private:
    char buff[buffSize];
    uint16_t counter = 0;
    bool ready = false;
};
#endif
