# UART Chat with Tiva C TM4C123GXL


## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Requirements](#requirements)
- [Setup](#setup)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Introduction
The UART Chat with Tiva C TM4C123 is a simple communication project that allows two Tiva C TM4C123 microcontrollers to exchange text messages over UART (Universal Asynchronous Receiver-Transmitter). This project demonstrates how to establish UART communication between a sender and a receiver microcontroller.

## Features
- Real-time chat between two Tiva C TM4C123 microcontrollers.
- Simple and minimalistic chat interface.
- UART communication using the built-in UART hardware of the Tiva C TM4C123.
- Customizable UART configurations.

## Requirements
- TWO Tiva C TM4C123 microcontroller boards (sender and receiver).
- USB to UART interface for connecting the microcontrollers to a computer.
- TivaWare™ Software (Texas Instruments Tiva C Series Peripheral Driver Library).
- Code Composer Studio (CCS) or another suitable development environment.

## Setup
1. Connect the sender and receiver Tiva C TM4C123 boards to your computer using the USB to UART interface.
2. Install Code Composer Studio (CCS) or another suitable development environment.
3. Clone this repository to your local machine:
4. Open the project in your development environment and configure the project settings according to your hardware setup.
5. Use putty to configure baud rate and COM ports

## Usage
### Sender Microcontroller
1. Build and flash the code to the sender Tiva C TM4C123 microcontroller.
2. Connect the sender Tiva C TM4C123 to the computer via the USB to UART interface.
3. Open a serial terminal (e.g., PuTTY or Tera Term) and connect to the sender microcontroller's COM port.
4. Send messages from the serial terminal, and they will be transmitted to the receiver microcontroller.

### Receiver Microcontroller
1. Build and flash the code to the receiver Tiva C TM4C123 microcontroller.
2. Connect the receiver Tiva C TM4C123 to the computer via the USB to UART interface.
3. Open a serial terminal and connect to the receiver microcontroller's COM port.
4. The receiver microcontroller will receive messages from the sender and display them on the serial terminal.

## IDEA of operation
There are two states that keep switching the sender and receiver state and an array of 200 chars for the max chars that we are
able to receive using UART
