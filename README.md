# Snake Game Project README

## Overview

This Snake Game is a simple yet engaging project that recreates the classic arcade game using modern C++ and the Raylib library. The purpose of this project was to explore game development with Raylib while sharpening C++ programming skills and understanding of essential development tools, including CMake. It implements fundamental game development concepts such as game loops, collision detection, and user input handling.

## Features

- **Dynamic Game Loop**: Ensures smooth gameplay and frame updates.
- **Collision Detection**: Manages interactions between the snake and game boundaries or food.
- **Directional Control**: Players can control the snake using keyboard inputs.
- **Automatic Food Generation**: Food items appear randomly throughout the game area.

## Requirements

- [CMake](https://cmake.org/) (for building the application)
- [Raylib](https://www.raylib.com/) 3.0 or above (for game development)
- A C++ compiler supporting C++17 (GCC or Clang recommended)
- [Catch2](https://github.com/catchorg/Catch2) (optional, for testing)

## Installation

### Clone the Repository

First, clone the repository to your local machine:

```bash
git clone https://github.com/grantmca/snake.git
cd snake
```

### Build the Project

Using CMake, build the project:

```bash
mkdir build
cd build
cmake ..
make
```

### Run the Game

After building the project, you can run the game executable:

```bash
./snake_game
```

## Usage

Upon running the game, you will see a window displaying the snake game. You can control the snake using the following keys:

- **H**: Move left
- **J**: Move down
- **K**: Move up
- **L**: Move right
- **Space**: Unpause the game

The game starts in a paused state. Press Space to start or unpause the game.

## Contributing

Contributions to the Snake Game project are welcome. Please feel free to fork the repository, make changes, and submit a pull request.

## Credits

Developed by Grant McAllister as a personal project to enhance programming skills and understand game development.

## Links

- Project Repository: [https://github.com/grantmca/snake](https://github.com/grantmca/snake)
- Raylib Library: [https://www.raylib.com/](https://www.raylib.com/)
- Catch2 Library: [https://github.com/catchorg/Catch2](https://github.com/catchorg/Catch2)

## Acknowledgments

Thanks to the Raylib community for providing extensive documentation and examples that were crucial in the development of this project.
