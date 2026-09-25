#include <stdlib.h>
#include "raylib.h"
#include "food.h"
#include "config.h"

void SpawnFood(Food *food, Node *snake)
{
    if (food == NULL)
        return;

    do
    {
        food->x = rand() % GRID_WIDTH;
        food->y = rand() % GRID_HEIGHT;

    } while (SnakeContains(snake, food->x, food->y));
}

void DrawFood(Food food)
{
    DrawRectangle(
        food.x * CELL_SIZE,
        food.y * CELL_SIZE,
        CELL_SIZE,
        CELL_SIZE,
        RED
    );

    DrawRectangleLines(
        food.x * CELL_SIZE,
        food.y * CELL_SIZE,
        CELL_SIZE,
        CELL_SIZE,
        MAROON
    );
}