#include <stdlib.h>

#include "raylib.h"
#include "snake.h"
#include "config.h"

Node *InitSnake(int x, int y, int length)
{
    Node *head = NULL;
    Node *current = NULL;

    for (int i = 0; i < length; i++)
    {
        Node *newNode = malloc(sizeof(Node));

        if (newNode == NULL)
        {
            FreeSnake(head);
            return NULL;
        }

        newNode->x = x - i;
        newNode->y = y;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            current = newNode;
        }
        else
        {
            current->next = newNode;
            current = newNode;
        }
    }

    return head;
}

void FreeSnake(Node *snake)
{
    Node *current = snake;

    while (current != NULL)
    {
        Node *next = current->next;
        free(current);
        current = next;
    }
}

void DrawSnake(Node *snake)
{
    Node *current = snake;
    int segment = 0;

    while (current != NULL)
    {
        Color color;

        if (segment == 0)
            color = DARKGREEN;
        else
            color = GREEN;

        DrawRectangle(
            current->x * CELL_SIZE,
            current->y * CELL_SIZE,
            CELL_SIZE,
            CELL_SIZE,
            color
        );

        DrawRectangleLines(
            current->x * CELL_SIZE,
            current->y * CELL_SIZE,
            CELL_SIZE,
            CELL_SIZE,
            BLACK
        );

        current = current->next;
        segment++;
    }
}

void MoveSnake(Node **snake, Direction direction, int grow)
{
    if (snake == NULL || *snake == NULL)
        return;

    Node *head = *snake;

    int newX = head->x;
    int newY = head->y;

    switch (direction)
    {
        case UP:
            newY--;
            break;

        case DOWN:
            newY++;
            break;

        case LEFT:
            newX--;
            break;

        case RIGHT:
            newX++;
            break;
    }

    Node *newHead = malloc(sizeof(Node));

    if (newHead == NULL)
        return;

    newHead->x = newX;
    newHead->y = newY;
    newHead->next = *snake;

    *snake = newHead;

    if (!grow)
    {
        Node *current = *snake;

        while (current->next != NULL &&
               current->next->next != NULL)
        {
            current = current->next;
        }

        Node *tail = current->next;

        if (tail != NULL)
        {
            current->next = NULL;
            free(tail);
        }
    }
}

int SnakeContains(Node *snake, int x, int y)
{
    Node *current = snake;

    while (current != NULL)
    {
        if (current->x == x && current->y == y)
            return 1;

        current = current->next;
    }

    return 0;
}