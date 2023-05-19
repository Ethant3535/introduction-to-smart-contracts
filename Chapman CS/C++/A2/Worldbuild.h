#ifndef WORLDBUILD_H
#define WORLDBUILD_H
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>      
#include <stdlib.h>
#include <ctime>
#include <cstdlib>
using namespace std;

class Worldbuild{
public:
    Worldbuild();
    ~Worldbuild();
    int levels;
    int gridSize;
    int lives;
    float coinChance;
    float nothingChance;
    float goombaChance;
    float koopaChance;
    float mushroomChance;
    int randPlacerPipe;
    int randPlacerBoss;
    int randPlacerHero;
    ifstream reader;
    void getValuesToSet(string inputFileName);
    char*** makeWorld(int levels,  int gridsize);
    char*** world;
    string lineContents;
};
#endif