#ifndef GAME_H
#define GAME_H

typedef enum
{
    START_SCREEN,
    PLAYING,
    GAME_OVER
} GameState;

void RunGame(void);

#endif