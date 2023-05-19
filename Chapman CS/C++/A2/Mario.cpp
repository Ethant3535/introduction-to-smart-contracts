#include "Mario.h"

Worldbuild w;
char name;
int marioInitialLevel;
int marioInitialRow;;
int marioInitialColumn;
int xCurrent=marioInitialLevel;
int yCurrent=marioInitialRow;
int zCurrent=marioInitialColumn;
int powerLevel;
//int lives;
int wallet;
bool bossBeaten=false;
int bossesBeaten;
Mario::Mario(){

}
Mario::Mario(char name,int marioInitialLevel,int marioInitialRow,int marioInitialColumn, int xCurrent, int yCurrent, int zCurrent, int powerLevel, int lives, int wallet,int enemylevelcounter){
    char heroName=name;
    int initialLevel=marioInitialLevel;
    int initialRow = marioInitialRow;
    int initialColumn = marioInitialColumn;
    int marioX=initialLevel;
    int marioY=marioInitialRow;
    int marioZ=marioInitialColumn;
    int PL=powerLevel;
    int Lives=lives;
    int Wallet=wallet;
    int enemykilledperlvlcounter=enemylevelcounter;
    }
Mario::~Mario(){
}

void Mario::moveMario(int xStart, int yStart, int zStart, int xCurrent, int yCurrent, int zCurrent,char*** arr){
    Mario hero=Mario('H',xStart,yStart,zStart, xCurrent,yCurrent,zCurrent,0,w.lives, wallet,0);
    arr[xStart][yStart][zStart]=hero.name;
    cout<<xStart<<yStart<<zStart<<endl;
    int randomNum=rand() % 4;
    if(randomNum==0){
        if(marioActionTaker(hero, xCurrent,yCurrent+1,zCurrent,arr)){
            hero.yCurrent+=1;
            arr[xCurrent][yCurrent][zCurrent]=hero.name;
            cout<<"movement to"<<xCurrent<<yCurrent<<zCurrent<<endl;
        }
    }
    if(randomNum==1){
        if(marioActionTaker(hero, xCurrent,yCurrent-1,zCurrent,arr)){
            hero.yCurrent-=1;
            arr[xCurrent][yCurrent][zCurrent]=hero.name;
            cout<<"movement to"<<xCurrent<<yCurrent<<zCurrent<<endl;
        }
    }
    if (randomNum==2){
        if(marioActionTaker(hero, xCurrent,yCurrent,zCurrent+1,arr)){
            hero.zCurrent+=1;
            arr[xCurrent][yCurrent][zCurrent]=hero.name;
            cout<<"movement to"<<xCurrent<<yCurrent<<zCurrent<<endl;
        }
    }
    if (randomNum==3){
        if(marioActionTaker(hero, xCurrent,yCurrent,zCurrent-1,arr)){
            hero.zCurrent-=1;
            arr[xCurrent][yCurrent][zCurrent]=hero.name;
            cout<<"movement to"<<xCurrent<<yCurrent<<zCurrent<<endl;
        }
    }

    cout<<xCurrent<<yCurrent<<zCurrent<<endl;
}

bool Mario::marioActionTaker(Mario mario, int x, int y, int z, char*** arr){
    bool actionTaken=false;
    while (!actionTaken){
        if (arr[x][y][z]=='x'){
            actionTaken=true;
        }
        else if (arr[x][y][z]=='c'){
            mario.wallet+=1;
            actionTaken=true;
        }
        else if (arr[x][y][z]=='m'){
            mario.powerLevel+=1;
            actionTaken=true;

        }
        else if (arr[x][y][z]=='g'){
            int goombaodds=rand() % 10;
            if (goombaodds>=7){
                mario.enemylevelcounter+=1;
                actionTaken=true;
            }
            else {
                mario.powerLevel-=1;
                if (mario.powerLevel<0){
                    mario.lives-=1;
                    mario.powerLevel=0;
                }
            }
        }
        else if(arr[x][y][z]=='k'){
            int koopaodds=rand() % 20;
            if (koopaodds>=12){
                mario.enemylevelcounter+=1;
                actionTaken=true;
            }
            else {
                mario.powerLevel-=1;
                if (mario.powerLevel<0){
                    mario.lives-=1;
                    mario.powerLevel=0;
                }
            }
        }
        else if (arr[x][y][z]=='b'){
            while (!bossBeaten){
                int bossOdds=rand() % 2;
                if (bossOdds==1){
                    bossBeaten+=1;
                    mario.xCurrent+=1;
                    mario.yCurrent=rand() % w.gridSize;
                    mario.yCurrent=rand() % w.gridSize;
                    arr[xCurrent][yCurrent][zCurrent]=mario.name;
                    actionTaken=true;
                    bossBeaten=true;
                }
                else if(bossOdds==0){
                    mario.powerLevel-=2;
                    if (powerLevel<2){
                        mario.lives-=1;
                    }
                }
            }
        }
        else if(arr[x][y][z]=='w'){
            mario.xCurrent+=1;
            mario.yCurrent=rand() % w.gridSize;
            mario.yCurrent=rand() % w.gridSize;
            arr[xCurrent][yCurrent][zCurrent]=mario.name;
            actionTaken=true;
        }
        else {
            actionTaken=true;
        }

    }


    
    return actionTaken;
}















