# Calculator Project with Tiva C Microcontroller 🧮

![Calculator](calculator.jpg)

Welcome to the Calculator Project! This project demonstrates the creation of an interactive calculator using the Tiva C TM4C123GH6PM microcontroller. The calculator is interfaced with an LCD display and a keypad to provide a great functional calculator experience !

## Features 🌟

- Basic arithmetic operations: addition ➕, subtraction ➖, multiplication ✖️, division ➗.
- Operates based on interrupts ⚡️, providing efficient and responsive keypad input.
- Can handle negative numbers ➖ and floating-point numbers 🌌 for precise calculations.
- Supports expressions like `5 + -5` and accurately computes results (e.g., `0`).
- Handles large numbers 📈, enabling calculations with significant digits.
- Clear button to reset the calculator 🔄.
- Display results on an LCD screen 🖥️.
- User-friendly interface 😄.
- Modular approach 🧩: Each functional module is designed as a separate unit, promoting code organization and reusability.
- Configuration flexibility ⚙️: Tune the behavior of each module by modifying its configuration file, allowing easy customization.

## Hardware Components 🛠️

- Tiva C TM4C123GH6PM microcontroller
- LCD display (16x2)
- 4x4 Keypad matrix
- Wires and connectors
- potentiometer for LCD constrast
- Breadboard : A breadboard can be used to organize and manage the connections between components.

## Prerequisites 📋

- A working PC
- Any software IDE that has ARM Compilation tool chain and debugger e.g. -> IAR and Code Composer studio
- Most importantly a passion for embedded systems and having a will to make things work and enjoy them working :)
  

## Getting Started 🚀

1. Connect the LCD display and keypad matrix to the appropriate pins on the Tiva C microcontroller.
2. Install the TivaWare C Series software package if not already done.
3. Clone or download this repository to your computer.
4. Open the project in your preferred IDE (e.g., Code Composer Studio).
5. Build and flash the project onto your Tiva C microcontroller.

## Usage 🎮

1. Power on the Tiva C microcontroller.
2. Enter numbers and arithmetic operations using the keypad.
3. Press the "#" button to see the result displayed on the LCD.
4. Press the "*" button to clear the calculator and start over.

## Demo Video 📹

Check out the project in action! Watch the demo video [here](link_to_demo_video).

## Project Structure 📂
```
calculator-project/
├── APP/
│ ├── APP_program.c
│ ├── APP_Private.h
│ ├── APP_interface.h
│ └── APP_config.h
├── HAL/
│ ├── LCD/
│ │ ├── LCD_program.c
│ │ ├── LCD_Private.h
│ │ ├── LCD_interface.h
│ │ └── LCD_config.h
│ ├── KEYPAD/
│ │ ├── KEYPAD_program.c
│ │ ├── KEYPAD_Private.h
│ │ ├── KEYPAD_interface.h
│ │ └── KEYPAD_config.h
├── MCAL/
│ ├── EXTI/
│ │ ├── EXTI_program.c
│ │ ├── EXTI_Private.h
│ │ ├── EXTI_interface.h
│ │ └── EXTI_config.h
│ ├── GPIO/
│ │ ├── GPIO_program.c
│ │ ├── GPIO_Private.h
│ │ ├── GPIO_interface.h
│ │ └── GPIO_config.h
├── main.c
```
## Acknowledgments 🙏

Special thanks to the EME initiative at the EUI university for their support.

## Contributors 👥

- [Mohamed Gamal Roushdy](https://github.com/mohamedgamal7)

## License 📜

This project is licensed under the [MIT License](LICENSE).

## Contact 📧

For questions or suggestions, feel free to contact me at [mohamadgamal2021@email.com](mailto:mohamadgamal2021@email.com).
