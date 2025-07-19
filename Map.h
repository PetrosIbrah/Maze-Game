#ifndef MAP_H
#define MAP_H

#include <ncurses.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// Class Map
// =========
class Map {
protected:
private:
    char** Maze;
    int RowNum, ColNum;
    int RowL, ColL;
    int RowM, ColM;
    int RowP, ColP;

public:   
    Map();
    Map(const string& FileName) ;
    void DisplayMap(WINDOW* ); 
    void RandCharacters();
    ~Map();

    // Getters And Setters 
    // Setters
    void SetMaze(char** m);
    void SetRowNum(int b);
    void SetColNum(int c);
    void SetRowL(int rl);
    void SetColL(int cl);
    void SetRowM(int rm);
    void SetColM(int cm);
    void SetRowP(int rp);
    void SetColP(int cp);
    // Getters 
    char** GetMaze();
    int GetRowNum();
    int GetColNum();
    int GetRowL();
    int GetColL();
    int GetRowM();
    int GetColM();
    int GetRowP();
    int GetColP();
};

#endif