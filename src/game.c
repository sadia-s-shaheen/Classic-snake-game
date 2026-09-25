#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "raylib.h"
#include "game.h"
#include "snake.h"
#include "food.h"
#include "config.h"

static int GetSnakeLength(Node *snake)
{
    int length = 0;

    Node *current = snake;

    while (current != NULL)
    {
        length++;
        current = current->next;
    }

    return length;
}

static float GetSnakeSpeed(Node *snake)
{
    int length = GetSnakeLength(snake);

    float speed =
        INITIAL_SPEED +
        (length - INITIAL_SNAKE_LENGTH) * SPEED_INCREASE;

    if (speed > MAX_SPEED)
        speed = MAX_SPEED;

    return speed;
}

static int CheckWallCollision(Node *snake)
{
    if (snake == NULL)
        return 1;

    if (snake->x < 0 ||
        snake->x >= GRID_WIDTH ||
        snake->y < 0 ||
        snake->y >= GRID_HEIGHT)
    {
        return 1;
    }

    return 0;
}

static int CheckSelfCollision(Node *snake)
{
    if (snake == NULL)
        return 0;

    Node *head = snake;
    Node *current = head->next;

    while (current != NULL)
    {
        if (head->x == current->x &&
            head->y == current->y)
        {
            return 1;
        }

        current = current->next;
    }

    return 0;
}

static void DrawBoard(void)
{
    for (int x = 0; x <= SCREEN_WIDTH; x += CELL_SIZE)
    {
        DrawLine(
            x,
            0,
            x,
            SCREEN_HEIGHT,
            (Color){220, 220, 220, 255}
        );
    }

    for (int y = 0; y <= SCREEN_HEIGHT; y += CELL_SIZE)
    {
        DrawLine(
            0,
            y,
            SCREEN_WIDTH,
            y,
            (Color){220, 220, 220, 255}
        );
    }
}

static void DrawStartScreen(void)
{
    ClearBackground(RAYWHITE);

    const char *title = "CLASSIC SNAKE";
    const char *startText = "Press ENTER to start";
    const char *controls = "Arrow Keys - Move";
    const char *quitText = "ESC - Quit";

    int titleSize = 40;
    int startSize = 20;
    int controlsSize = 18;
    int quitSize = 18;

    int titleWidth = MeasureText(title, titleSize);
    int startWidth = MeasureText(startText, startSize);
    int controlsWidth = MeasureText(controls, controlsSize);
    int quitWidth = MeasureText(quitText, quitSize);

    DrawText(
        title,
        (SCREEN_WIDTH - titleWidth) / 2,
        180,
        titleSize,
        DARKGREEN
    );

    DrawText(
        startText,
        (SCREEN_WIDTH - startWidth) / 2,
        260,
        startSize,
        DARKGRAY
    );

    DrawText(
        controls,
        (SCREEN_WIDTH - controlsWidth) / 2,
        310,
        controlsSize,
        GRAY
    );

    DrawText(
        quitText,
        (SCREEN_WIDTH - quitWidth) / 2,
        345,
        quitSize,
        GRAY
    );
}

static void DrawGameOverScreen(int score)
{
    ClearBackground(RAYWHITE);

    const char *title = "GAME OVER";
    const char *restartText = "Press R to restart";
    const char *quitText = "Press ESC to quit";

    int titleSize = 40;
    int restartSize = 20;
    int quitSize = 18;

    char scoreText[50];
    sprintf(scoreText, "Score: %d", score);

    int scoreSize = 25;

    int titleWidth = MeasureText(title, titleSize);
    int scoreWidth = MeasureText(scoreText, scoreSize);
    int restartWidth = MeasureText(restartText, restartSize);
    int quitWidth = MeasureText(quitText, quitSize);

    DrawText(
        title,
        (SCREEN_WIDTH - titleWidth) / 2,
        180,
        titleSize,
        RED
    );

    DrawText(
        scoreText,
        (SCREEN_WIDTH - scoreWidth) / 2,
        250,
        scoreSize,
        DARKGRAY
    );

    DrawText(
        restartText,
        (SCREEN_WIDTH - restartWidth) / 2,
        310,
        restartSize,
        DARKGREEN
    );

    DrawText(
        quitText,
        (SCREEN_WIDTH - quitWidth) / 2,
        350,
        quitSize,
        GRAY
    );
}

void RunGame(void)
{
    srand((unsigned int)time(NULL));

    InitWindow(
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        "Classic Snake Game"
    );

    SetTargetFPS(60);

    GameState state = START_SCREEN;

    Node *snake = NULL;

    Food food = {0, 0};

    Direction direction = RIGHT;
    Direction nextDirection = RIGHT;

    int score = 0;

    float moveTimer = 0.0f;

    while (!WindowShouldClose())
    {
        float deltaTime = GetFrameTime();

        /* ---------------- START SCREEN ---------------- */

        if (state == START_SCREEN)
        {
            if (IsKeyPressed(KEY_ENTER))
            {
                snake = InitSnake(
                    GRID_WIDTH / 2,
                    GRID_HEIGHT / 2,
                    INITIAL_SNAKE_LENGTH
                );

                direction = RIGHT;
                nextDirection = RIGHT;

                score = 0;
                moveTimer = 0.0f;

                SpawnFood(&food, snake);

                state = PLAYING;
            }

            BeginDrawing();

            DrawStartScreen();

            EndDrawing();

            continue;
        }

        /* ---------------- PLAYING ---------------- */

        if (state == PLAYING)
        {
            if (IsKeyPressed(KEY_UP) && direction != DOWN)
                nextDirection = UP;

            if (IsKeyPressed(KEY_DOWN) && direction != UP)
                nextDirection = DOWN;

            if (IsKeyPressed(KEY_LEFT) && direction != RIGHT)
                nextDirection = LEFT;

            if (IsKeyPressed(KEY_RIGHT) && direction != LEFT)
                nextDirection = RIGHT;

            moveTimer += deltaTime;

            /*
             * Calculate speed from current snake length.
             *
             * Longer snake = higher speed.
             */

            float currentSpeed = GetSnakeSpeed(snake);

            if (moveTimer >= 1.0f / currentSpeed)
            {
                moveTimer = 0.0f;

                direction = nextDirection;

                int eatingFood =
                    snake != NULL &&
                    snake->x == food.x &&
                    snake->y == food.y;

                MoveSnake(
                    &snake,
                    direction,
                    eatingFood
                );

                if (eatingFood)
                {
                    score++;

                    SpawnFood(&food, snake);
                }

                if (CheckWallCollision(snake) ||
                    CheckSelfCollision(snake))
                {
                    state = GAME_OVER;
                }
            }

            BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawBoard();

            DrawFood(food);

            DrawSnake(snake);

            DrawText(
                TextFormat("Score: %d", score),
                10,
                10,
                20,
                DARKGRAY
            );

            DrawText(
                TextFormat(
                    "Speed: %.1f",
                    GetSnakeSpeed(snake)
                ),
                10,
                35,
                16,
                GRAY
            );

            EndDrawing();
        }

        /* ---------------- GAME OVER ---------------- */

        if (state == GAME_OVER)
        {
            if (IsKeyPressed(KEY_R))
            {
                FreeSnake(snake);

                snake = InitSnake(
                    GRID_WIDTH / 2,
                    GRID_HEIGHT / 2,
                    INITIAL_SNAKE_LENGTH
                );

                direction = RIGHT;
                nextDirection = RIGHT;

                score = 0;
                moveTimer = 0.0f;

                SpawnFood(&food, snake);

                state = PLAYING;
            }

            BeginDrawing();

            DrawGameOverScreen(score);

            EndDrawing();
        }
    }

    FreeSnake(snake);

    CloseWindow();
}