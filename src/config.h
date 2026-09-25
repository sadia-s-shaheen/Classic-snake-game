#ifndef CONFIG_H
#define CONFIG_H

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

#define CELL_SIZE 20

#define GRID_WIDTH (SCREEN_WIDTH / CELL_SIZE)
#define GRID_HEIGHT (SCREEN_HEIGHT / CELL_SIZE)

#define INITIAL_SNAKE_LENGTH 3

/* Speed settings */
#define INITIAL_SPEED 6.0f
#define MAX_SPEED 16.0f
#define SPEED_INCREASE 0.5f

#endif