#include "raylib.h"

int main(void)
{
    InitWindow(800, 600, "Classic Snake Game");

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Classic Snake Game", 250, 280, 30, DARKGREEN);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}