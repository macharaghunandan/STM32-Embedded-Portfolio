# 6x5 Digital Matrix Keypad (Work In Progress / Debugging)

This project explores the functional logic of multiplexing a custom 30-key (6x5) matrix keypad using standard digital GPIO pins on an STM32F103C8. 

**Status:** Currently in the simulation debugging phase. The core C-logic is drafted, but the Proteus virtual environment is exhibiting floating pin/noise issues.

## System Architecture
<img width="950" height="792" alt="Digital_Mtrix_keyboard_schematic" src="https://github.com/user-attachments/assets/b1c2c12c-bbca-4acd-9697-2107c894483c" />


## Functional Intent
The goal of the system is to read 30 distinct keys using only 11 GPIO pins (5 Columns as Outputs, 6 Rows as Inputs) via a high-speed scanning algorithm.
* **Column Drive:** Iterate through the 5 column pins, driving one HIGH at a time.
* **Row Polling:** Poll all 6 row pins to detect the HIGH signal intersection.
* **Matrix Mapping:** Map the resulting `[row][col]` coordinate to a 2D character array.

## Current Troubleshooting & Known Issues
During Proteus simulation, the virtual microcontroller struggles with the floating row inputs, leading to false triggers. 

**Debugging steps taken:**
1. **Code Isolation:** I temporarily simplified the `Scan()` function (visible in the commented-out sections of `my_keypad.c`) to bypass the nested `for` loops. By hardcoding a check for a single pin (`GPIOA, GPIO_PIN_0`), I attempted to isolate whether the issue was in the scanning algorithm or the hardware simulation.
2. **Hardware Anchoring:** Identified that the initial `GPIO_NOPULL` configuration on the row inputs was causing them to act as antennas in the simulation. 
3. **Timing Constraints:** Experimented with `HAL_Delay()` values to allow the virtual voltage to stabilize before polling the rows, though Proteus timing models remain unstable for this specific matrix configuration.

**Next Steps:** Transitioning from Proteus simulation to physical hardware testing to implement physical pull-down resistors and hardware debouncing.
