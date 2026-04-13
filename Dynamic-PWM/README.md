# Dynamic PWM Control using STM32 & HAL

This project demonstrates register-level hardware control using an STM32F401CC microcontroller. The system uses high-speed ADC polling to read dual analog inputs and dynamically manipulate a hardware timer's frequency and duty cycle.

## Circuit Architecture
<img width="779" height="803" alt="schematic_PWM_vary" src="https://github.com/user-attachments/assets/b13ceeb8-d1e2-451f-81a0-bddddf699e6d" />


## Core Functional Logic

The system bypasses standard delay-based toggling in favor of direct timer register manipulation via the STM32 Hardware Abstraction Layer (HAL).

### 1. High-Speed ADC Polling
The `while(1)` loop continuously polls two separate potentiometer inputs via `hadc1`. 
* **`pot2`:** Defines the baseline frequency.
* **`pot1`:** Defines the active duty cycle.

### 2. Register Mapping
The raw 12-bit ADC values (0 - 4095) are mapped to match the timer's operational limits:
* The frequency input (`pot2`) is mapped from `100` to `2000` to establish the **Auto-Reload Register (ARR)** limit.
* The duty cycle input (`pot1`) is mapped from `0` to the *current dynamically calculated ARR value* to establish the **Capture/Compare Register (CCR)**.

* change with change in the pot values

<img width="777" height="374" alt="oscilloscope_part2_PWM_vary" src="https://github.com/user-attachments/assets/1b53f451-0f29-4d5b-8e0e-c9d03752fef5" />
<img width="918" height="420" alt="oscilloscope_PWM_vary" src="https://github.com/user-attachments/assets/1f4e3f85-e090-427d-abfc-cf8a7d7f31c5" />



### 3. Hardware Timer Update
The calculated values are instantly pushed to the timer registers to alter the PWM waveform on the fly without interrupting CPU flow:

```c
// Update the timer frequency limit
__HAL_TIM_SET_AUTORELOAD(&htim2, map_arr);

// Update the pulse width threshold
__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, map_ccr);

```

### 4. Serial Telemetry (huart1)
The system initializes USART1 at a 9600 baud rate. It formats the raw ADC data into a string buffer via sprintf and transmits it over UART for real-time serial monitoring.

Core Files Included:

main.c:  Contains the peripheral initializations, the custom mapping logic, and the main execution loop.

FINAL_PWM_VARU_USING_POTENTIOMETER.pdsprj:  The circuit simulation validating the microcontroller logic.
