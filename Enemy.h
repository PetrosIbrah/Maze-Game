#ifndef ENEMY_H
#define ENEMY_H

#include "Map.h"

// Simple Struct "Point" to help 'M' Find the best Path
// ====================================================
struct Point {
    int Row;
    int Col;
    Point() : Row(-1), Col(-1) {}
    Point(int r, int c) : Row(r), Col(c) {}
    bool operator==(const Point& x) const {
        return Row == x.Row && Col == x.Col;
    }

    bool operator!=(const Point& x) const {
        return !(*this == x);
    }
};

// Class Enemy
// ===========
class Enemy {
private:
    Map& F;
    int CurrentStep;
    char** Maze;
    vector<Point> Path;
    int currentStep;
    int RowNum;
    int ColNum;
    
public:
    Enemy(Map& a) ;
    ~Enemy();
    void FindBestPath(Point target);
    void MoveEnemy();
    bool Validation(int Row, int Col);
};

#endif