#ifndef FOOD_H
#define FOOD_H

#include "snake.h"

typedef struct
{
    int x;
    int y;
} Food;

void SpawnFood(Food *food, Node *snake);

void DrawFood(Food food);

#endif