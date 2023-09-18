# Ethernet Chatroom


## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Introduction
The Ethernet Chatroom is a simple server and client chat application designed for communication over a local network using an Ethernet connection. This project allows users on the same network to send text messages to each other through a centralized chat server.

## Features
- Real-time chat between multiple clients.
- Centralized chat server for message routing.
- Simple and intuitive command-line interface.
- Supports private messaging between clients.
- Customizable server and client settings.

## Requirements
- Python 3.x
- Ethernet connection (hub or switch) for local network communication.
- Basic knowledge of using the command line.

## Installation
1. Clone the repository to your local machine:

    ```bash
    git clone https://github.com/yourusername/ethernet-chatroom.git
    cd ethernet-chatroom
    ```


## Usage
### Starting the Chat Server
1. Navigate to the project directory.
2. Open a terminal and activate your virtual environment (if used).

3. Start the chat server:

    ```bash
    python server.py
    ```

4. The server will start listening for incoming connections on the specified IP address and port.

### Running the Chat Client
1. Open a terminal window for each client.
2. Navigate to the project directory.
3. Activate your virtual environment (if used).

4. Start the chat client:

    ```bash
    python client.py
    ```

5. Follow the on-screen instructions to connect to the chat server and start chatting.

## Contributing
Contributions to this project are welcome! Please follow our [Contribution Guidelines](CONTRIBUTING.md) for more details.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.