@echo off
gcc main.c snake.c food.c -o snake.exe -IC:/raylib/raylib/src -LC:/raylib/raylib/src -lraylib -lopengl32 -lgdi32 -lwinmm
if errorlevel 1 exit /b 1
snake.exe
