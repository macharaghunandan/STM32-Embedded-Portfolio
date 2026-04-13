# Cascaded Shift Register Countdown Timer

This project demonstrates GPIO pin conservation and serial data transmission by interfacing an STM32F103C8 with cascaded 74HC595 shift registers to drive dual 7-segment displays. It features a non-blocking UART interface to set a countdown timer.

## System Architecture
<img width="1009" height="700" alt="Countdown_schematic" src="https://github.com/user-attachments/assets/c741bd65-6d85-4f90-9a83-72c9a1cf4234" />

## Core Functional Logic

The system utilizes custom bit-banging and non-blocking timing logic to seamlessly handle UART inputs while updating external display hardware.

### 1. Display Multiplexing via Shift Registers
To drive two 7-segment displays (14 LED segments total) using only 3 GPIO pins, the system uses two daisy-chained 74HC595 shift registers. 
* The `Display_Update` function takes a 2-digit integer and splits it into `tens` and `units`.
* These values are mapped to a hex-code array (`SEGMENT_MAP`) to determine the correct LED segments.
* The two 8-bit hex codes are bitwise-OR'd into a single 16-bit `packet` (`(SEGMENT_MAP[tens] << 8) | SEGMENT_MAP[units]`).

### 2. Manual Bit-Banging
Instead of using a hardware SPI peripheral, the serial transmission is handled via manual GPIO manipulation (bit-banging):
* The `LATCH` pin is pulled LOW.
* A `for` loop iterates 16 times, masking the `packet` to extract each individual bit.
* The bit is written to the `DATA` pin, and the `CLOCK` pin is toggled to push the bit into the register.
* Once all 16 bits are shifted, the `LATCH` pin is pulled HIGH, pushing the data to the output pins instantly.

### 3. Non-Blocking System Timing (`HAL_GetTick`)
The main execution loop utilizes `HAL_GetTick()` instead of standard blocking delays (`HAL_Delay`). 
* This creates an asynchronous 1-second interval to decrement the countdown timer.
* Because the CPU is never halted, the system can continuously poll the UART peripheral (`HAL_UART_Receive`) to accept new numeric inputs from the user in real-time, dynamically updating the countdown value on the fly.

---
**Core Files Included:**
* `main.c`: Contains the UART parsing and non-blocking `HAL_GetTick()` countdown logic.
* `display.c`: Contains the hex-mapping array and the manual bit-banging shift register sequence.
* `[Your Proteus File Name].pdsprj`: The cascaded shift register circuit simulation.
