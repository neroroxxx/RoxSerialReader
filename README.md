*Under MIT license.*

[RoxXxtar.com/bmc](https://www.roxxxtar.com/bmc)

# RoxSerialReader

This is a simple library for Teensy boards to read input from the serial monitor.

See the examples for code information.

```c++
#include <RoxSerialReader.h>
// template takes in an unsigned int, this is the size of the buffer
// that will hold the string thats coming in.
RoxSerialReader <25> reader;
void setup(){
  // no need to initialize Serial
}
// type hello or world into the Serial Monitor
void loop(){
  // read() method will read the Serial input
  if(reader.read()){
    // if read() returns true then a string was received.
    if(reader.match("hello")){
      // match() will return true if the string passed matches the one received
      // in this case you typed hello into the serial monitor
      Serial.println("*** matched hello ***");
    } else if(reader.match("world")){
      Serial.println("*** matched world ***");
    } else {
      Serial.print("received: ");
      Serial.println(reader.getBuffer());
    }
  }
}

```
