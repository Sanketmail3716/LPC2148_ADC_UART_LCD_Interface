# LPC2148_ADC_UART_LCD_Interface

This project demonstrates how to read analog data using the ADC module of the LPC2148 ARM7 microcontroller, transmit it via UART, and display the values on a 16x2 LCD using 4-bit mode. The project includes two implementations:
- Reading ADC values directly and displaying on LCD
- Receiving ADC values via UART and displaying on LCD

---

## 🛠️ Features

- ADC initialization and reading
- UART communication (sending and receiving ADC data)
- 16x2 LCD interfacing in 4-bit mode
- PLL configuration for system clock
- Delay functions for timing control

---

## 📁 File Structure

  LPC2148_ADC_UART_LCD_Interface/
│
├── main_uart_display.c # Displays ADC values received via UART
├── main_direct_adc.c # Reads ADC directly and displays on LCD
├── UART.c / UART.h # UART initialization and Rx functions
├── Lcd_4bit.c / Lcd_4bit.h # 16x2 LCD interfacing in 4-bit mode
├── ADC.c / ADC.h # ADC initialization and read function
├── PLL.c / PLL.h # PLL configuration for 60MHz system clock
├── Makefile # (Optional) For building the project
└── README.md # Project documentation


---

## 🔌 Hardware Requirements

- LPC2148 Development Board
- 16x2 LCD Display
- Potentiometer or analog sensor
- USB to Serial Converter (for UART testing)
- Power Supply (5V regulated)

---

## 🧠 How It Works

### 1. Direct ADC Read (main_direct_adc.c)
- Initializes ADC channel 2 on Port 0.
- Reads analog input and converts it to digital.
- Displays the value on LCD every few milliseconds.

### 2. UART-based ADC Display (main_uart_display.c)
- Receives ADC values via UART from another device or controller.
- Parses the value string and displays it on LCD if it starts with ':'.

---

## 🔧 Configuration Details

- **PLL Frequency**: 60 MHz
- **LCD Pins**: 4-bit data mode (D4-D7, RS, EN)
- **UART Baud Rate**: 9600 bps
- **ADC Channel Used**: Channel 2 (P0.28)

---

## 🖥️ Output Example

On LCD:
ADC value1:
1023


---

## 🧪 Testing Tips

- Use a serial terminal (e.g., Tera Term) to send ADC strings like `:01023` for testing UART.
- Vary potentiometer or analog sensor to see ADC change live on LCD.

---

## 🤝 Contributions

Feel free to fork this repo and improve code, add more ADC channels, or integrate with sensors like LM35, LDR, etc.

---

## 📜 License

This project is open-source and available under the MIT License.
