#include "raylib.h"
#include "snake.h"

int main(void)
{
    InitWindow(800, 600, "Classic Snake Game");
    SetTargetFPS(60);

    Node *snake = InitSnake(400, 300, 3);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        EndDrawing();
    }

    FreeSnake(snake);
    CloseWindow();

    return 0;
}