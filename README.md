crystal-c-levitation
====================

Crystal C levitation machine code.

Code is based on Arduino library and assumed to be uploaded to Arduino
Duemilanove. As Arduino IDE is weak, Eclipse is used instead. Compiled version
of Arduino Core library is included. The same goes for header files in the Core
alongside `pins_arduino.h`.

## Getting started

1. First, be sure that you have the tools listed below installed. Other versions
than what is listed probabably work, too.

    1. Eclipse Juno Service Release 2 (with C/C++ development tools)
    2. AVR Eclipse Plugin 2.4.0
    3. avr-gcc 4.7.2
    4. avrdude 5.11.1
    5. GNU make 3.82

2. Fire up Eclipse and configure AVR Eclipse plugin (in *Window* → 
   *Preferences* → *AVR*).

    1. Point to correct paths of listed tools in *Paths*.
    2. Set `avrdude.conf` in *AVRDude*. I got mine from Arduino SDK 1.0.5.
    3. In *AVRDude*, create a programmer configuration with:
    
        1. **Configuration name**: Arduino
        2. **Description**: Arduino
        3. **Programmer Hardware**: Arduino
        4. **Override default baudrate**: 57600
        5. **Override default port**: where ever you Arduino shows up at 
       
3. Import this repository to Eclipse as a project.

4. From project's context menu, go to *Properties* → *AVR* → *AVRDude* and
   select the new programmer configuration. *Note: Using wrong config can
   overwrite Arduino bootloader, so be careful!*

4. Build project: *Build project* in project's context menu.

5. Upload to Arduino: *AVR* → *Upload project to Target Device*.

That should upload code to Arduino. 

## Debugging

Debugging tools are rudementary but they exist.

1. To enable or disable debugging, modify file `CrystalCLevitation.h` to define
or not define `__DEBUG` flag.
2. In debug mode, serial communication is enabled. To issue message to debug
channel, use something like this:

    ```C++
    #ifdef __DEBUG
        Serial.println("This is a debug message");
    #endif
    ``` 

3. To read message, use `cat < /dev/ttyUSB0` or similar method. Arduino IDE's
serial monitor works, too.

## More info

See this [excellent article][setup] on integrating Eclipse and Arduino stuff.

[setup]: http://horrorcoding.altervista.org/arduino-development-with-eclipse-a-step-by-step-tutorial-to-the-basic-setup/

This repository is for software components. Repository wiki contains
details of hardware and other parts of the project.