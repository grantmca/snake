#include <iostream>
#include "deque.h"
#include "raylib.h"
#include <raylib.h>

int main() {

  int screenWidth = 800;
  int screenHeight = 800;

  InitWindow(screenWidth, screenHeight, "Snake Game");

  SetTargetFPS(60);

  // Main game loop
  while (WindowShouldClose() == false) // Detect window close button or ESC key
  {
    BeginDrawing();

    EndDrawing();
  }

  return 0;
}
