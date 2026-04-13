# I2C Sensor Interfacing (SHT21)

This project demonstrates bare-metal I2C communication between an STM32F401CC and an SHT21 Temperature/Humidity sensor. It focuses on master-transmit and master-receive sequencing, data bit-shifting, and real-time UART telemetry.

## System Architecture
<img width="1166" height="788" alt="I2C_Temp_schematic" src="https://github.com/user-attachments/assets/61786671-8570-4023-97d8-94fd810a8141" />


## Functional Logic & I2C Sequencing

The system utilizes the STM32 HAL to execute standard I2C Master/Slave protocols without relying on pre-built, bloated sensor libraries.

### 1. Master Transmit (Addressing & Command)
The SHT21 has a default 7-bit I2C address of `0x40`. The system shifts this 1 bit to the left (`0x40 << 1`) to accommodate the read/write bit required by the HAL. 
The microcontroller acts as the Master, transmitting the `0xF3` hex command to trigger a "No Hold Master" temperature measurement.

### 2. Master Receive (Data Acquisition)
After allowing the sensor time to process the physical measurement, the STM32 requests 3 bytes of data back:
* `temp[0]`: The MSB (Most Significant Byte) of the temperature reading.
* `temp[1]`: The LSB (Least Significant Byte) of the temperature reading.
* `temp[2]`: The Checksum (CRC) byte.

### 3. Bit-Shifting & Conversion
The raw data is split across two bytes. The functional logic extracts and combines them into a single 16-bit integer by shifting the MSB left by 8 bits and masking the LSB's status bits:

```c
uint16_t raw = ((temp[0] << 8) | (temp[1] & 0xFC));
