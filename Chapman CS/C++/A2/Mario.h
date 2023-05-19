#ifndef MARIO_H
#define MARIO_H


#include "Worldbuild.h"


class Mario{
    //Worldbuild w;
public:
    char name;
    int xStart;
    int yStart;
    int zStart;
    int xCurrent;
    int yCurrent;
    int zCurrent;
    int powerLevel;
    int lives;
    int wallet;
    int enemylevelcounter;
    bool bossBeaten;
    int bossesBeaten;
    Mario();
    Mario(char name, int xStart, int yStart, int zStart, int xCurrent, int yCurrent, int zCurrent, int powerLevel, int lives, int wallet,int enemylevelcounter);
    ~Mario();
    void moveMario(int xStart, int yStart, int zStart, int xCurrent, int yCurrent, int zCurrent,char*** arr);
    bool marioActionTaker(Mario mario, int x, int y, int z, char*** arr);

};
#endif