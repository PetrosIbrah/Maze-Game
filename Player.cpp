#include "Player.h"

// Constructor
Player :: Player(Map& a) : F(a) {
    Maze = F.GetMaze();
};
// Destructor
Player :: ~Player(){};

// Getters and Setters
bool Player :: GetRegister(){return Register;};
void Player :: SetRegister(bool w){ Register = w;}

// Player Movement
void Player :: MovePlayer(int x, int y) {
    int NewX = F.GetRowL() + x;
    int NewY = F.GetColL() + y;
    if (NewX >= 0 && NewX < F.GetColNum() && NewY >= 0 && NewY < F.GetRowNum() &&  Maze[NewY][NewX] != '*' && Maze[NewY][NewX] != 'M' ) {
        Maze[F.GetColL()][F.GetRowL()] = '.';
        F.SetRowL(NewX);
        F.SetColL(NewY);
        Maze[F.GetColL()][F.GetRowL()] = 'L';
        Register = 1;
    } else if (Maze[NewY][NewX] == '*' || Maze[NewY][NewX] == 'M') {
        Register = 0;
    }
};