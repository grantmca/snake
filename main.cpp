#include <iostream>
#include "deque.h"
#include "raylib.h"
#include <raylib.h>

int cellSize = 20;

int cellCount = 20;

int screenWidth = cellSize * cellCount;

int screenHeight = cellSize * cellCount;

class Food {

public:
  Vector2 position;

  Food() {
    position = GenerateRandomValue();
  }
  void Draw() {
    DrawRectangle(position.x * cellSize, position.y * cellSize, cellSize, cellSize, BLACK);
  }

  Vector2 GenerateRandomValue() {
    float x = GetRandomValue(0, cellCount - 1);
    float y = GetRandomValue(0, cellCount - 1);
    return Vector2{x, y};
  }
};


int main() {

  InitWindow(screenWidth, screenHeight, "Snake Game");

  SetTargetFPS(60);

  Food food = Food();


  while (WindowShouldClose() == false) {


    BeginDrawing();


    ClearBackground(LIGHTGRAY);
    food.Draw();

    EndDrawing();
  }

  return 0;
}
