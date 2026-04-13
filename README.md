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
