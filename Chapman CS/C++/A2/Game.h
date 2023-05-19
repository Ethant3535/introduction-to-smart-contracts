#ifndef GAME_H
#define GAME_H
#include "Mario.h"
//#include "Worldbuild.h"

class Game{
public:
    Game();
    ~Game();
    bool checkIfHasLives();
    bool checkIfFinalBossBeaten();
    bool finalBossBeaten;
    void play(Mario mario, char*** arr);
};

#endif

