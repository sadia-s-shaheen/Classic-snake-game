#include <stdlib.h>
#include "snake.h"

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
            current = head;
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