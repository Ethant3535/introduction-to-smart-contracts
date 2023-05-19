#include "Game.h"

extern Worldbuild w;
Game::Game(){

}
Game::~Game(){

}

//char*** balls =w.world;
Mario mario;
int randy=rand() % w.gridSize;
int randz=rand() % w.gridSize;
//Mario* hero=new Mario('H',1,randy,randz,1,randy,randz,0,w.lives,0,0);
bool Game::checkIfFinalBossBeaten(){
    if (mario.bossesBeaten==w.levels-1){
        return true;
    }
    return false;

}

bool Game::checkIfHasLives(){
    if (mario.lives==0){
        return false;
    }
    return true;
}

void Game::play(Mario mario,char*** arr){
    while (!checkIfFinalBossBeaten() && checkIfHasLives()){
        mario.moveMario(mario.xStart,mario.yStart,mario.zStart,mario.xCurrent,mario.yCurrent,mario.zCurrent,arr);
    }
    if (checkIfFinalBossBeaten()){
        cout<<"win"<<endl;
    }
    else if (!checkIfHasLives()){
        cout<<"loss"<<endl;
        cout<<w.lives<<endl;
    }
}

int main()
{
    Mario m;
    Mario hero= Mario('H',1,randy,randz,1,randy,randz,0,w.lives,0,0);
    char*** arr =w.world;
    Mario mario=hero;
    Game game;
    game.play(hero,arr);
    return 0;
}


