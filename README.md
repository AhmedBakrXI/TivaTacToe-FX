# TivaTacToe - An Embedded Tic-Tac-Toe Game with JavaFX

<p align="center">
  <img src="https://cdn-icons-png.flaticon.com/512/566/566294.png" alt="TicTacToe Logo" width="200">
  <img src="https://i.ibb.co/FqLJn9q/TM4C123G.jpg" alt="Tiva C" width="200" >
</p>
<a href="https://youtu.be/O3L76q5jkJM"><h3>Click to watch on YouTube</h3></a>


**TivaTacToe** is an innovative project that combines the power of the Tiva C microcontroller with the modern user interface capabilities of JavaFX to bring you a classic game in a whole new way. This project showcases the convergence of embedded systems and interactive software development.

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Requirements](#requirements)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Project Structure](#project-structure)
- [Languages Used](#languages-used)
- [Contributing](#contributing)
- [License](#license)

## Overview

*TivaTacToe* is a unique project that combines an embedded system, specifically the Tiva C microcontroller, with a graphical user interface (GUI) built using JavaFX. The main goal of this project is to create an interactive version of the classic Tic-Tac-Toe game where players can make moves using a physical microcontroller, adding an exciting twist to the traditional game.

## Features

- **Interactive Tic-Tac-Toe Gameplay:** Play the classic game of Tic-Tac-Toe with a friend or against yourself using the Tiva C microcontroller to make moves.

- **Real-Time Communication:** The Tiva C microcontroller communicates with the JavaFX interface via serial communication, enabling real-time interaction.

- **Intuitive User Interface:** The JavaFX GUI provides an intuitive and visually appealing game interface with customizable tokens and status updates.

- **Dynamic Game Logic:** The project includes a dynamic game logic system that determines the winner and handles player turns.

## Requirements

To run *TivaTacToe*, you'll need the following components:

- **Hardware:**
  - Tiva C microcontroller.
  - USB-to-Serial communication interface.
  - Computer running Java (for the JavaFX interface).

- **Software:**
  - Tiva C microcontroller development environment (e.g., Code Composer Studio) for C programming.
  - Java Development Kit (JDK) for JavaFX development.
  - Java IDE (e.g., IntelliJ IDEA or Eclipse) for editing and running the Java code.
  - Serial communication library for Java (e.g., jSerialComm).

## Getting Started

Follow these steps to get started with *TivaTacToe*:

1. **Set Up Tiva C Microcontroller:** Configure and set up the Tiva C microcontroller and development environment for C programming.

2. **Install Dependencies:** Ensure you have the required software dependencies mentioned in the "Requirements" section installed on your computer.

3. **Open the JavaFX Project:** Open the JavaFX project in your preferred Java IDE (e.g., IntelliJ IDEA).

4. **Connect the Microcontroller:** Connect the Tiva C microcontroller to your computer using the USB-to-Serial interface.

5. **Build and Run:** Build and run the JavaFX application. The game interface should appear on your screen.

## Usage

Once the project is set up and running, you can use the Tiva C microcontroller to control the Tic-Tac-Toe game on the JavaFX interface. Follow these steps to play:

1. Use the Tiva C microcontroller to send 'A' or 'B' signals to make moves on the game board.

2. The JavaFX interface will display the game status, including whose turn it is and the winner if one is determined.

3. Enjoy playing Tic-Tac-Toe in this interactive and unique way!

## Project Structure

The project structure includes several files and directories:

- `TicTacToe.java`: The main JavaFX application class that handles the game interface and logic.

- `application.h` and `application.c`: These files contain code for the Tiva C microcontroller, including GPIO, LED control, and UART communication with the Java application.

- Other supporting files and resources for the JavaFX interface and microcontroller code.

## Languages Used

<p align="center">
  <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/1/18/C_Programming_Language.svg/1200px-C_Programming_Language.svg.png" alt="C Logo" width="50">
  <img src="https://images.vexels.com/media/users/3/166401/isolated/lists/b82aa7ac3f736dd78570dd3fa3fa9e24-java-programming-language-icon.png" alt="Java Logo" width="50">
</p>

## Contributing

Contributions to *TivaTacToe* are welcome! If you have ideas for improvements, bug fixes, or new features, please open an issue or submit a pull request. Let's collaborate to make this project even better.

## License

This project is licensed under the MIT License - see the LICENSE file for details.
