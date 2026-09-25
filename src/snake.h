#ifndef SNAKE_H
#define SNAKE_H

typedef struct Node
{
    int x;
    int y;
    struct Node *next;
} Node;

Node *InitSnake(int x, int y, int length);

void FreeSnake(Node *snake);

#endif