# Single-Pin Analog Keyboard (Resistor Ladder)

This project demonstrates an analog approach to user input, utilizing a resistor ladder network to decode multiple tactile switch presses through a minimal number of ADC pins on an STM32 microcontroller.

## System Architecture
<img width="560" height="840" alt="Keyboard1_Schematic" src="https://github.com/user-attachments/assets/83d87b58-479a-4ea0-a022-b4948f63cf3c" />

## Functional Logic & ADC Decoding

Standard matrix keyboards require multiple GPIO pins (Rows x Columns). This system bypasses that limitation by utilizing a voltage divider network. Each button press routes the current through a different resistance path, producing a unique, predictable voltage level at the microcontroller's ADC pin.

### 1. Dual-Channel ADC Polling
The main execution loop utilizes `HAL_ADC_PollForConversion` to continuously monitor two separate analog channels (`hadc1` and `hadc2`), allowing for a larger array of keys without expanding the GPIO footprint.

### 2. Voltage Threshold Windowing
Because analog voltages can fluctuate slightly due to component tolerances and noise, the raw 12-bit ADC values are passed through a custom threshold algorithm:

```c
uint16_t step1 = (volt1 + 150) / 315;
