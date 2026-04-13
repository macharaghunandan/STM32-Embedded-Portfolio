# STM32 Embedded Systems Portfolio
A collection of hardware-software integration projects focused on ARM Cortex-M4 architecture and HAL-level bare-metal programming.

---

## 1. Dynamic PWM Frequency & Duty Cycle Controller
**Platform:** STM32F401CC | **Simulation:** Proteus

### Functional Logic
This project utilizes high-speed ADC polling to manipulate hardware timer registers in real-time, providing independent control over waveform characteristics:
* **Frequency Control:** ADC input mapped to the Auto-Reload Register (ARR) to shift the timer period.
* **Duty Cycle Control:** ADC input mapped to the Capture/Compare Register (CCR) to modify the pulse width.

**🔗 [Click here to view the Code and Proteus Simulation files](./Dynamic-PWM)**


## 2. Interrupt-Driven UART Keyword Detection
**Platform:** STM32F401CC | **Simulation:** Proteus

### Functional Logic
This project demonstrates non-blocking serial communication using hardware interrupts. The main execution loop remains empty while the system listens for incoming UART traffic in the background.
* **Event-Driven Architecture:** Utilizes the `HAL_UART_RxCpltCallback` interrupt to process incoming bytes sequentially without halting the CPU.
* **Real-Time String Parsing:** Evaluates a shifting buffer array to detect specific keyword triggers (e.g., "hi") and dynamically transmits a programmed string response.

**🔗 [Click here to view the Code and Proteus Simulation files](./UART-Interrupt-Parsing)**



## 3. I2C Sensor Interfacing & Bit-Shifting
**Platform:** STM32F401CC | **Protocol:** I2C, UART

### Functional Logic
This project bypasses standard sensor libraries to manually execute I2C communication with an SHT21 environmental sensor. 
* **Master/Slave Protocol:** Manages 7-bit device addressing and transmits specific hex commands to trigger hardware-level measurements.
* **Data Processing:** Utilizes C bit-shifting and masking to reconstruct split data bytes (MSB/LSB) into readable 16-bit integers before applying physical conversion formulas.

**🔗 [Click here to view the Code and Architecture files](./I2C-SHT21-Sensor)**
