# pico-as5600
pico-as5600 is a library for the Pico C/C++ SDK to interface with the AS5600 12-Bit Programmable Contactless Potentiometer over I2C. This is a fork of [dwm_pico_as5600](https://github.com/dancesWithMachines/dwm_pico_as5600/tree/main). All functions are originally made by dancesWithMachines. This fork was meant to give me more control over the init function. This library is an INTERFACE CMake library.

**Contents:**
1. [Using library](#using-library)
    1. [General usage](#general-usage)
    2. [Building and using example](#building-and-using-example)
    3. [Embeding into project](#embeding-into-project)
2. [as5600 test rig](#as5600-test-rig)
3. [as5600 sensor manual](#as5600-sensor-manual)
4. [Licenses](#licenses)

## Using library
### General usage
Using library is self explanatory. There is no documentation, but all the functions have descriptions for ease of use.
Any modern IDE should be capable of displaying them. For full list of functions study header file.
![Code](https://raw.githubusercontent.com/dancesWithMachines/dancesWithMachines.github.io/main/assets/COMMON/as5600_desc.gif)

The code also comes with example file showing how to set up as5600 and use some of the functions.
### Building and using example

#### Prebuilt example
You can find prebuilt example in "Releases" section under this repo if you just want to test the sensor.

#### Build and compile
To build example:
1. Edit `PICO_SDK_PATH` in `CMakeLists.txt`.
2. Create `build` directory and access it.
3. From inside the directory run `cmake ..` to configure and then `make` to compile.

If compilation was successful `as5600_example.uf2` binary file should be present in `build` directory.
Pi Pico can now be connected in flash mode and said file copied into it.

#### Connect as5600
To test the example as5600 should be connected to default I2C pins. Those are GP4 for SDA and GP5 for SCL.
![Pico pinout](https://www.raspberrypi.com/documentation/microcontrollers/images/pico-pinout.svg)

Image source: https://www.raspberrypi.com/documentation/microcontrollers/images/pico-pinout.svg

#### Test rig
To test as5600 a [test rig](#test-rig) can be used. Testing by holding magnet directly in hand is discouraged.

#### Connect via serial
Example prints messages via USB or UART. To receive messages a serial monitor like Minicom might be needed, but Arduino IDE's or VS Code's build ins should also do. Monitor should respect carriage return (in VS Code this is called terminal mode) for messages to display properly.

### Embeding into project
To embed library into a project, one can simply copy "lib/pico_as5600" directory from the repository.

`CMakeLists.txt` of target project needs to be modified to make use of the library.
In order for the library to be regocnized, to the project `CMakeLists.txt` add the following line:
`add_subdirectory(lib/pico_as5600)`
In the same `CMakeLists.txt`, add `pico_as5600` to `target_link_libraries`. This is the same as with any of the Pico SDK hardware libraries.
Add `#include "as5600.h"` to project main source file to expose library functions.

For reference, check this repository's `CMakeLists.txt` file.

## as5600 test rig
To test as5600 sensor, test rig can be downloaded and printed.
All necessary files can be found here: https://www.thingiverse.com/thing:6514317
</br>
<img src="https://cdn.thingiverse.com/assets/cd/a7/b5/5d/99/large_display_bc6184bf-d4ba-4be4-8b54-91f652e296c1.jpg" alt="as5600 test rig" width="500">

## as5600 sensor manual
To learn more about as5600 itself check product document: https://ams.com/documents/20143/36005/AS5600_DS000365_5-00.pdf
## Licenses
This source code is released under BSD-3 license.

Check LICENSE file for full license agreement.

Check COPYING for 3rd party licenses.