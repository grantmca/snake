#include <iostream>
#include "deque.cpp"
#include "raylib.h"
#include <raylib.h>
#include <raymath.h>

class Snake {

public:
  Deque<Vector2> body;

  Vector2 direction = Vector2{1, 0};

  Snake() {
    body.pushEnd(Vector2{6, 10});
    body.pushEnd(Vector2{7, 10});
    body.pushEnd(Vector2{8, 10});
  }

  void Update() {
    body.pushFront(Vector2Add(body.at(0), direction));
    body.popEnd();
  }

  void Draw(int cellSize) {
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
  int cellCount = 50;

  Food() {
    cellCount = 50;
    position = GenerateRandomValue(cellCount);
  }

  Food(int count) {
    cellCount = count;
    position = GenerateRandomValue(cellCount);
  }


  void Update() {

  }

  void Draw(int cellSize) {
    DrawRectangle(position.x * cellSize, position.y * cellSize, cellSize, cellSize, BLACK);
  }

  Vector2 GenerateRandomValue(int cellCount) {
    float x = GetRandomValue(0, cellCount - 1);
    float y = GetRandomValue(0, cellCount - 1);
    return Vector2{x, y};
  }
};

class Game {
public:
  Snake snake;
  Food food; 
  int cellSize = 20;
  int cellCount = 50;
  int screenWidth = cellSize * cellCount;
  int screenHeight = cellSize * cellCount;
  double lastInterval = 0;

  Game() {
    Snake snake = Snake();
    Food food = Food(50); 
    int cellSize = 20;
    int cellCount = 50;
    int screenWidth = cellSize * cellCount;
    int screenHeight = cellSize * cellCount;
    double lastInterval = 0;
  }

  bool DetectFrameUpdate(double interval) {
    double time = GetTime();
    double time_since_last_frame = time - lastInterval;
    if (time_since_last_frame > interval) {
      lastInterval = time;
      return true;
    }
    return false;
  }
  
  void Run () {
    InitWindow(screenWidth, screenHeight, "Snake Game");
    SetTargetFPS(60);

    while (WindowShouldClose() == false) {
      BeginDrawing();

      if (DetectFrameUpdate(0.1)) {
        snake.Update();
      }

      ClearBackground(LIGHTGRAY);
      food.Draw(cellSize);
      snake.Draw(cellSize);

      EndDrawing();
    }
    return;
  }

};

int main() {
  Game game;
  game.Run();
  return 0;
}
