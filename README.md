# STM32 Embedded Systems Portfolio
A collection of hardware-software integration projects focused on ARM Cortex-M4 architecture and HAL-level bare-metal programming.

---

## 1. Cascaded Shift Register Countdown Timer
**Platform:** STM32 | **Hardware:** 74HC595, 7-Segment Displays

### Functional Logic
This project drives multi-digit displays using minimal GPIO pins by bit-banging data into daisy-chained shift registers.
* **Serial-to-Parallel Conversion:** Implemented custom bit-banging logic in C to shift 16-bit data packets via Data, Clock, and Latch pins.
* **Non-Blocking Architecture:** Utilizes `HAL_GetTick()` to execute a 1-second countdown timer without halting the CPU, allowing concurrent UART polling for real-time user input.

**🔗 [Click here to view the Code and Architecture files](./Shift-Register-7Segment)**


## 2. I2C Sensor Interfacing & Bit-Shifting
**Platform:** STM32F401CC | **Protocol:** I2C, UART

### Functional Logic
This project bypasses standard sensor libraries to manually execute I2C communication with an SHT21 environmental sensor. 
* **Master/Slave Protocol:** Manages 7-bit device addressing and transmits specific hex commands to trigger hardware-level measurements.
* **Data Processing:** Utilizes C bit-shifting and masking to reconstruct split data bytes (MSB/LSB) into readable 16-bit integers before applying physical conversion formulas.

**🔗 [Click here to view the Code and Architecture files](./I2C-SHT21-Sensor)**


## 3. Dynamic PWM Frequency & Duty Cycle Controller
**Platform:** STM32F401CC | **Simulation:** Proteus

### Functional Logic
This project utilizes high-speed ADC polling to manipulate hardware timer registers in real-time, providing independent control over waveform characteristics:
* **Frequency Control:** ADC input mapped to the Auto-Reload Register (ARR) to shift the timer period.
* **Duty Cycle Control:** ADC input mapped to the Capture/Compare Register (CCR) to modify the pulse width.

**🔗 [Click here to view the Code and Proteus Simulation files](./Dynamic-PWM)**


## 4. Single-Pin Analog Keyboard (Resistor Ladder)
**Platform:** STM32 | **Protocol:** ADC, UART

### Functional Logic
This project replaces a standard digital GPIO matrix keyboard with an analog resistor ladder network to severely reduce pin consumption.
* **Analog Voltage Decoding:** Each keypress generates a unique voltage drop read by the STM32's ADC.
* **Threshold Windowing:** Implemented a custom mathematical grouping algorithm in C to eliminate analog noise and map fluctuating 12-bit raw values into reliable, discrete ASCII keystrokes.
* **Serial Output:** Decoded characters are transmitted via UART for real-time host interaction.

**🔗 [Click here to view the Code and Architecture files](./Analog-Resistor-Keyboard)**


## 5. Interrupt-Driven UART Keyword Detection
**Platform:** STM32F401CC | **Simulation:** Proteus

### Functional Logic
This project demonstrates non-blocking serial communication using hardware interrupts. The main execution loop remains empty while the system listens for incoming UART traffic in the background.
* **Event-Driven Architecture:** Utilizes the `HAL_UART_RxCpltCallback` interrupt to process incoming bytes sequentially without halting the CPU.
* **Real-Time String Parsing:** Evaluates a shifting buffer array to detect specific keyword triggers (e.g., "hi") and dynamically transmits a programmed string response.

**🔗 [Click here to view the Code and Proteus Simulation files](./UART-Interrupt-Parsing)**


## 6. Digital Matrix Keyboard (WIP)
**Platform:** STM32 | **Status:** Simulation Troubleshooting
* **Description:** A work-in-progress build documenting the debugging process of a 6x5 matrix scanning algorithm. Highlights code isolation techniques and Proteus simulation constraints regarding floating GPIO inputs.

**🔗 [Click here to view the Troubleshooting Log & Code](./Digital-Matrix-Keyboard-WIP)**
