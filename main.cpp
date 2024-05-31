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
    std::cout << "Snake Constructor Called" << std::endl;
    body.pushEnd(Vector2{6, 10});
    body.pushEnd(Vector2{7, 10});
    body.pushEnd(Vector2{8, 10});
  }

  ~Snake() {
    std::cout << "Snake Destructor Called" << std::endl;
  }

  void Reset() {
    for (int i=0; i < body.size(); i++) {body.popEnd();};
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
      DrawRectangle(int(link.x) * cellSize, int(link.y) * cellSize, cellSize, cellSize, BLACK);
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

  void updatePosition() {
    position = GenerateRandomValue(cellCount);
  }

  void Draw(int cellSize) {
    DrawRectangle(position.x * cellSize, position.y * cellSize, cellSize, cellSize, RED);
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

  void KeyPressUpdate() {
    std::cout << ":" << GetCharPressed() << ":" << std::endl;
    if(IsKeyDown(KEY_K)) {
      std::cout << "J Down" << std::endl;
      snake.direction = Vector2{0, -1};
    } else if (IsKeyDown(KEY_J)) {
      std::cout << "K Up" << std::endl;
      snake.direction = Vector2{0, 1};
    } else if (IsKeyDown(KEY_H)) {
      std::cout << "H Left" << std::endl;
      snake.direction = Vector2{-1, 0};
    } else if (IsKeyDown(KEY_L)) {
      std::cout << "L Right" << std::endl;
      snake.direction = Vector2{1, 0};
    }
  }

  void UpdateOnFood() {
    int size = snake.body.size();
    if (Vector2Equals(snake.body.at(0), food.position)) {
      snake.body.pushFront(food.position);
      food.updatePosition();
    }
    return;
  }

  void Restart() {
    snake.Reset();
    food.GenerateRandomValue(cellCount);
    lastInterval = 0;
    return;
  }

  void CheckColision() {
    // Check if the head is outside of the scope
    int x_pos = snake.body.at(0).x;
    int y_pos = snake.body.at(0).y;
    if (x_pos >= cellCount || x_pos < 0 || y_pos >= cellCount || y_pos < 0) {
      std::cout << "Time to Restart" << std::endl;
      Restart();
    }
    // Check if the head is touching the body
  }

  void Update() {
    KeyPressUpdate();
    //Check on colision with self and Restart if needed
    if (DetectFrameUpdate(0.1)) {
      CheckColision();
      UpdateOnFood();
      snake.Update();
    }
  }

  void Draw() {
    BeginDrawing();
    food.Draw(cellSize);
    snake.Draw(cellSize);
    ClearBackground(LIGHTGRAY);
    EndDrawing();
  }
  
  void Run () {
    InitWindow(screenWidth, screenHeight, "Snake Game");
    SetTargetFPS(60);

    while (WindowShouldClose() == false) {
      Update();
      Draw();
    }
    return;
  }

};

int main() {
  Game game;
  game.Run();
  return 0;
}
