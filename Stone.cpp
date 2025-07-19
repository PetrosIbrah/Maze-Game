#include "Stone.h"

// Constructor
Stone :: Stone(Map& a) : F(a){
    Maze = F.GetMaze();
    ColP = F.GetColP();
    RowP = F.GetRowP();
};

// Destructor
Stone :: ~Stone(){};
// Setter and Getetr
int Stone :: GetW(){return W;};
void Stone :: SetW(int w){ W = w;}

// @ Random Teleporter
void Stone :: RandP(){
    srand(time(NULL));
    Maze[ColP][RowP] = '.';
    do {
        RowP = rand() % F.GetRowNum();
        ColP = rand() % F.GetColNum();
    } while(Maze[ColP][RowP] != '.');
    Maze[ColP][RowP] = '@'; 
    F.SetColP(ColP);
    F.SetRowP(RowP);
};

// Check if @ is captured
void Stone :: Check(){
    if (Maze[ColP][RowP] == 'L'){
        W = 1;
    } else if (Maze[ColP][RowP] == 'M'){
        W = 2;
    } 
};