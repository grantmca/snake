#include <iostream>
#include "deque.cpp"
#include "raylib.h"
#include <raylib.h>

int cellSize = 20;

int cellCount = 20;

int screenWidth = cellSize * cellCount;

int screenHeight = cellSize * cellCount;

class Snake {

public:
  Deque<Vector2> body;

  Vector2 direction = Vector2{1, 0};

  Snake() {
    body.pushEnd(Vector2{6, 10});
    body.pushEnd(Vector2{7, 10});
    body.pushEnd(Vector2{8, 10});
  }



  void Draw() {
    for (int i = 0; i < body.size(); i++) {
      Vector2 link = body.at(i);
      float x = link.x;
      float y = link.y;
      DrawRectangle(x * cellSize, y * cellSize, cellSize, cellSize, BLACK);
    }
  }
};

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

  Snake snake = Snake();


  while (WindowShouldClose() == false) {
    BeginDrawing();


    ClearBackground(LIGHTGRAY);
    food.Draw();
    snake.Draw();

    EndDrawing();
  }

  return 0;
}
