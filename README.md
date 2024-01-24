# Snake Game in C++ using the SFML Library

Welcome to the Snake Game project! This is a classic Snake game developed in C++ using the SFML library.

## Overview

- Compact and well-designed Snake game implementation.
- Developed in C++ with the SFML library for graphical rendering.
- Provides two installation options: using Docker for ease of deployment or compiling locally with the Makefile.
- Compatible with Linux distributions that use a X11 server.

## Installation

### Option 1: Using Docker (Recommended)

1. Clone the repository:

    ```bash
    git clone https://github.com/Focault/Snake.git
    cd Snake
    ```

2. Make the installation script executable:

    ```bash
    chmod +x install.sh
    ```

3. Run the installation script:

    ```bash
    ./install.sh
    ```

    This script installs the necessary dependencies, builds the Docker image using Docker Compose, and also makes the `run.sh` script executable.

4. Run the game:

    ```bash
    ./run.sh
    ```

### Option 2: Compiling Locally

1. Clone the repository:

    ```bash
    git clone https://github.com/Focault/Snake.git
    cd Snake
    ```

2. Install the SFML library (if not already installed):

    ```bash
    sudo apt-get update
    sudo apt-get install -y libsfml-dev
    ```

3. Compile the game using the Makefile:

    ```bash
    cd src
    make
    ```

4. Run the compiled executable:

    ```bash
    ./Snake
    ```

## Controls

- Use arrow keys to control the snake's direction.

Feel free to contribute, report issues, or suggest improvements. Happy gaming!
