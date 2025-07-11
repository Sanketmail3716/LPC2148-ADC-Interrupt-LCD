# LPC2148 ADC Interrupt with LCD Display

This project demonstrates how to interface the ADC (Analog-to-Digital Converter) of the LPC2148 ARM7 microcontroller using interrupts, and display the converted digital value on a 16x2 character LCD in 4-bit mode.

## 🔧 Features

- Reads analog input from ADC Channel 2 (AD0.2)
- Uses interrupt-based ADC conversion (non-blocking)
- Displays 10-bit ADC result (0–1023) on LCD
- Clock setup using PLL
- Modular code with LCD, PLL, and ADC initialization files

## 🧠 Components Used

- LPC2148 Development Board (ARM7)
- 16x2 LCD (4-bit interface)
- Potentiometer or analog sensor for input
- Keil uVision or any ARM7 IDE
- Flash Magic (for uploading code)

## 📁 File Structure
LPC2148-ADC-Interrupt-LCD/
├── main.c # Main logic with ISR
├── PLL.h # PLL configuration header
├── Lcd_4bit.h # 4-bit LCD control functions
├── ADC.h # ADC init and macros
└── README.md # Project documentation


## 📟 How It Works

1. `PLL_SET()` sets up the system clock.
2. `LCD_Init()` initializes the 16x2 LCD in 4-bit mode.
3. `ADC_init()` sets up the ADC for interrupt mode on AD0.2.
4. `initInterrupt()` configures the VIC to handle ADC interrupts.
5. When a conversion is complete, `ADCISR()` is triggered and reads the ADC value.
6. The value is displayed on the LCD using `display(read)` in the main loop.

## 🔌 Pin Connections

| LPC2148 Pin | Function        |
|-------------|-----------------|
| P0.28       | AD0.2 (Analog Input) |
| P0.0–P0.7   | LCD data/command lines (based on your `Lcd_4bit.h`) |
| VCC/GND     | Power for LCD and sensor |

## 🛠️ To Compile and Upload

1. Open the project in Keil uVision (or your IDE).
2. Compile the project.
3. Use Flash Magic or a programmer to upload the `.hex` file to LPC2148.



