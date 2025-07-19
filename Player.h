#ifndef PLAYER_H
#define PLAYER_H
#include "Map.h"

// Class Player.
// =============
class Player {
private:
    Map& F;
    char** Maze;
    bool Register;
public:
    Player(Map& a) ;
    ~Player();
    void MovePlayer(int x, int y);
    bool GetRegister() ;
    void SetRegister(bool tf);
};

#endif