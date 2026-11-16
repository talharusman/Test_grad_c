# Snake Game

A small Snake game written in C with [Raylib](https://www.raylib.com/).

## Project structure

- `main.c`: window setup, game loop, drawing, collisions, scoring, and restart logic
- `snake.c` / `snake.h`: snake state, movement, and keyboard input
- `food.c` / `food.h`: random food generation
- `build.bat`: Windows compile-and-run command

## Requirements on Windows

Install MinGW GCC and Raylib built for MinGW. This project expects Raylib at
`C:/raylib/raylib` and GCC at `C:/MinGW/bin/gcc.exe`.

If Raylib is installed elsewhere, update the paths in `build.bat`.

## Build and run

From the repository folder in Command Prompt or PowerShell:

```bat
build.bat
```

Or run the compiler manually:

```bat
gcc main.c snake.c food.c -o snake.exe -IC:/raylib/raylib/src -LC:/raylib/raylib/src -lraylib -lopengl32 -lgdi32 -lwinmm
snake.exe
```

## Controls

- Arrow keys or `W`, `A`, `S`, `D`: move
- `R`: restart after game over
- Close the window: quit

## Game flow

`main.c` initializes Raylib and the snake, reads keyboard input, advances the
snake at a fixed interval, checks wall and self collisions, grows the snake
when it eats food, draws the board, and closes the window cleanly.
