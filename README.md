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

2. Fire up Eclipse and configure AVR Eclipse plugin.

    1. Point to correct paths of listed tools in *Window* → *Preferences* → 
       *AVR* → *Paths*.
    2. Set `avrdude.conf` in *Window* → *Preferences* → *AVR* → *AVRDude*. I got
       mine from Arduino SDK 1.0.5.
       
3. Import this repository to Eclipse as a project.

4. Build project: *Build project* in project's context menu.

5. Upload to Arduino: *AVR* → *Upload project to Target Device*.

TODO: *Do we have to set up AVR __Programmer Configuration__ for the project?* 

## More info

See this [excellent article][setup] on integrating Eclipse and Arduino stuff.

[setup]: http://horrorcoding.altervista.org/arduino-development-with-eclipse-a-step-by-step-tutorial-to-the-basic-setup/

This repository is for software components. [Repository wiki](wiki/) contains
details of hardware and other parts of the project.