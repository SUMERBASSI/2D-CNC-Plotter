# CNC 2D Plotting Machine

## Project Overview
This repository contains the documentation and resources for a CNC 2D Plotting Machine built as part of the ME-205 Design Lab-1 project at [Institute Name, e.g., Indian Institute of Technology or similar, based on the logo in the PDF]. The machine is a low-cost DIY plotter that uses repurposed components like old DVD writers to draw intricate designs on paper via computer-generated instructions.

### Problem Statement
We were assigned to design and build a 2D Computer Numeric Control (CNC) plotter using Arduino, mechanical components from old DVD writers, and related electronics. The goal was to create a machine capable of precise plotting based on digital designs.

### Working Principle
The core principle involves converting digital designs into precise control instructions for the machine's movement along two axes (X and Y). A computer-generated design is translated into G-code, which the CNC machine uses to move the tool (pen or marker) over a surface like paper, printing intricate designs.

A CNC Shield V3 and GRBL on Arduino interpret G-code commands sent from a computer to control stepper motors, positioning the plotter's tool precisely along X and Y axes.

### Bill of Materials (BOM)
Based on the components mentioned in the presentation:
- Arduino Uno (1x)
- CNC Shield V3 (1x)
- A4988 Stepper Motor Drivers (2x for X and Y axes)
- Stepper Motors (2x, salvaged from old DVD/CD writers)
- Servo Motor (1x, for pen lift)
- Old DVD/CD Writers (2x, for mechanical rails and motors)
- Pen/Marker and Holder (custom-made)
- Power Supply (e.g., 12V adapter for motors)
- Jumper Wires, Soldering Kit, Acrylic/Plastic for structure
- Miscellaneous: Screws, glue, wires

Estimated cost: Low (mostly recycled parts; new components ~$20-50).

### Assembly Instructions
1. **Salvage Components**: Disassemble two old DVD writers to extract stepper motors and sliding rails. These will form the X and Y axes.
2. **Build Mechanical Structure**: Mount the DVD rails perpendicularly to create X-Y movement. Secure with acrylic sheets or 3D-printed parts. Attach the pen holder to the Y-axis slider and connect it to the servo for up/down movement.
3. **Electronics Setup**:
   - Plug the CNC Shield V3 onto the Arduino Uno.
   - Insert A4988 drivers into the X and Y slots on the shield.
   - Connect stepper motors to the drivers.
   - Wire the servo to the shield's Z-axis or a digital pin (e.g., Pin 11).
   - Power the setup (Arduino via USB, motors via external 12V).
4. **Circuit Diagram**: See `/schematics/circuit-diagram.png` (create this using tools like Fritzing; standard wiring: Steppers to A4988, A4988 to shield, servo to Pin 11/GND/5V).

For detailed steps, refer to similar tutorials:
- [Instructables: Arduino Mini CNC Plotter from DVD Drives](https://www.instructables.com/Arduino-Mini-CNC-Plotter-Machine-from-dvd-drives/)
- [Arduino Project Hub: Mini CNC 2D Plotter](https://projecthub.arduino.cc/Mrinnovative/arduino-based-mini-cnc-2d-plotter-796c2f)

### Software Setup
1. **Install GRBL Firmware**:
   - Download GRBL from [GitHub](https://github.com/gnea/grbl).
   - Use Arduino IDE to flash it to the Arduino Uno (see `/code/grbl-config.h` for sample config).
2. **Design Software**: Use Inkscape (v0.92+) with the MI GRBL G-code extension to create designs and export G-code.
3. **Sender Software**: Use Universal Gcode Sender (UGS) v2.1.2 to send G-code to the Arduino.
4. **Configuration**:
   - In GRBL, set steps/mm based on your steppers (e.g., $100=250 for X, $101=250 for Y).
   - Connect via USB at 115200 baud.

### Usage
1. Create a design in Inkscape and export as G-code using the MI GRBL extension.
2. Open UGS, connect to Arduino, load the G-code file.
3. Home the machine (if set up), then run the job.
4. Sample G-code: See `/code/sample-gcode.gcode` for a simple square.

### Difficulties Faced
- **GRBL Compatibility**: Initial GRBL version was incompatible with Arduino Uno and CNC V3 shield; reverted to an earlier version.
- **Error While Starting Stream**: Incorrect G-code transmission due to missing configuration in GRBL; replaced with the correct config.
- **Inkscape G-Code Export Bug**: Unable to save G-code files correctly (units in pixels instead of mm); fixed by setting units to mm.
- **Directory Management for GRBL**: Uploading GRBL required careful installation directory management; incorrect paths led to complications.
- **Port Detection Issue**: UGS initially failed to detect the COM port; resolved by closing Arduino IDE (which was using the same port).

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments
Thanks to open-source tools like GRBL, Inkscape, and UGS. Inspired by various DIY tutorials online.
