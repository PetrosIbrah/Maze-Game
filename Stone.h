#ifndef STONE_H
#define STONE_H
#include "Map.h"

// Class Stone
// ===========
class Stone {
    private:
        Map& F;
        char** Maze; 
        int RowP;
        int ColP;
        int W;
    public:
        Stone(Map& a);
        ~Stone();
        void RandP();
        void Check();
        int GetW();
        void SetW(int w);
};

#endif