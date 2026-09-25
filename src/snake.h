#ifndef SNAKE_H
#define SNAKE_H

typedef struct Node
{
    int x;
    int y;
    struct Node *next;
} Node;

typedef enum
{
    UP,
    DOWN,
    LEFT,
    RIGHT
} Direction;

Node *InitSnake(int x, int y, int length);

void FreeSnake(Node *snake);

void DrawSnake(Node *snake);

void MoveSnake(Node **snake, Direction direction, int grow);

int SnakeContains(Node *snake, int x, int y);

#endif