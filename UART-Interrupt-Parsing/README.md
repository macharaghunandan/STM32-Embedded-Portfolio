
# Interrupt-Driven UART Keyword Detection

This project demonstrates a non-blocking serial communication system using an STM32F401CC. It utilizes hardware interrupts to monitor incoming UART traffic in the background without tying up the main CPU execution loop.

## System Architecture
<img width="715" height="789" alt="Schematic_UART_Interrups" src="https://github.com/user-attachments/assets/63567988-9045-4580-adbb-25b6efb1a091" />


## Functional Logic & Interrupt Handling

Unlike traditional polling methods that halt the processor while waiting for serial data, this system is entirely event-driven. 

### 1. Non-Blocking Architecture
The main `while(1)` loop is deliberately left empty. The system is initialized with `HAL_UART_Receive_IT()`, which sets up the UART peripheral to listen for a single byte of data in the background and immediately frees the CPU.

### 2. The Rx Complete Callback
When a byte is received, the hardware triggers an interrupt, forcing the CPU to pause its current task and execute the `HAL_UART_RxCpltCallback` function. 
* The incoming byte is appended to a shifting `history` buffer.
* The system resets the interrupt listener to catch the next incoming byte.

### 3. Real-Time String Parsing
Inside the callback, the system evaluates the buffer against specific trigger conditions.
* If the last two bytes received sequentially match the characters `'h'` and `'i'`, the condition evaluates to true.
* The microcontroller immediately fires back a string response (`" Hello \n"`) via a blocking `HAL_UART_Transmit` before exiting the interrupt sequence.
* To prevent buffer overflow, the index counter resets after evaluating 9 bytes.

---
**Core Files Included:**
* `main.c`: Contains the interrupt initialization and the custom `HAL_UART_RxCpltCallback` logic.
* `uart_proteus.pdsprj`: The virtual terminal simulation setup used to validate the bidirectional communication.
