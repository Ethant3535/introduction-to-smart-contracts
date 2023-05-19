#include "Worldbuild.h"


int levels=0;
int gridSize=0;
int lives=0;
int coinChance=0;
int nothingChance=0;
int goombaChance=0;
int mushroomChance=0;
int koopaChance=0;
Worldbuild::Worldbuild(){
    getValuesToSet("test.txt");
    world=makeWorld(levels,gridSize);
}

Worldbuild::~Worldbuild(){
    //delete[] world;
}

void Worldbuild::getValuesToSet(string inputFileName){
    ifstream reader;
    int count = 0;
    reader.open(inputFileName);
    while(count<8){
        getline(reader, lineContents);
        if (count==0){
            levels=stoi(lineContents);
            cout << "LEVELS: " << levels << endl;   
        }
        if (count==1){
            gridSize=stoi(lineContents);  
            cout << "GRIDSIZE: " << gridSize << endl;   
 
        }
        if (count==2){
            lives=stoi(lineContents);   
            cout << "NUMBER OF LIVES: " << lives << endl;   
        }
        if (count==3){
            coinChance=stoi(lineContents);  
            cout << "COIN CHANCE: " << coinChance << endl;   

        }
        if (count==4){
            nothingChance=stoi(lineContents); 
            cout << "NOTHING CHANCE: " << nothingChance << endl;   
   
        }
        if (count==5){
            goombaChance=stoi(lineContents);   
            cout << "GOOMBA CHANCE: " << goombaChance << endl;   
 
        }
        if (count==6){
            mushroomChance=stoi(lineContents);   
            cout << "MUSHROOM CHANCE: " << mushroomChance << endl;   
 
        }
        if (count==7){
            koopaChance=stoi(lineContents);    
            cout << "KOOPA CHANCE: " << koopaChance << endl;   
  
        }
        count++;    
    }
}

char*** Worldbuild::makeWorld(int levels,  int gridsize){
    char ***worldArr = new char**[levels];
    for(int i =0; i<levels; i++){
        worldArr[i] = new char*[gridSize];
   for(int j =0; j<gridSize; j++){
       worldArr[i][j] = new char[gridSize];
       for(int k = 0; k<gridSize;k++){
          worldArr[i][j][k] = 0;
       }
   }
}
    //
    for (int i=0;i<levels;++i){

        for (int j=0;j<gridSize;++j){
            for (int k=0;k<gridSize;++k){
                int randomNum=rand() % 100;
                //cout<< "RANDOM NUMBER IS: " << randomNum <<endl;
                if (randomNum<=coinChance){
                    worldArr[i][j][k]='c';
                    //cout << "COIN ADDED AT LEVEL " << i << " IN ARRAY SPOT" << j << ", " << k << endl;
                }
                else if (randomNum >= coinChance && randomNum < coinChance + nothingChance){
                    worldArr[i][j][k]='x';
                    //cout << "NOTHING ADDED AT LEVEL " << i << " IN ARRAY SPOT" << j << ", " << k << endl;

                }
                else if(randomNum >= coinChance+nothingChance &&  randomNum<goombaChance+coinChance+nothingChance){
                    worldArr[i][j][k]='g';
                    //cout << "GOOMBA ADDED AT LEVEL " << i << " IN ARRAY SPOT" << j << ", " << k << endl;

                }
                else if(randomNum>=coinChance+nothingChance+goombaChance && randomNum<goombaChance+coinChance+nothingChance+mushroomChance){
                    worldArr[i][j][k]='m';
                    //cout << "MUSHROOM ADDED AT LEVEL " << i << " IN ARRAY SPOT" << j << ", " << k << endl;
                }
                else{
                    worldArr[i][j][k]='k';
                    //cout << "KOOPA ADDED AT LEVEL " << i << " IN ARRAY SPOT" << j << ", " << k << endl;
                }
            }
        }
        int randPlacerPiperow = rand() % gridsize;
        int randPlacerPipecolumn = rand() % gridsize;
        if(i<levels-1){
            worldArr[i][randPlacerPiperow][randPlacerPipecolumn]='w';
        }
        int randPlacerBossrow = rand() % gridsize;
        int randPlacerBosscolumn = rand() % gridsize;
        worldArr[i][randPlacerBossrow][randPlacerBosscolumn]='b';
        //int marioInitialRow = rand() % gridsize;

    }

  
  
    


    return worldArr;
}



