#include "Map.h"

// Getters And Setters 
// Setters
void Map :: SetMaze(char** m) {Maze = m;};
void Map :: SetRowNum(int b) {RowNum = b;};
void Map :: SetColNum(int c) {ColNum = c;};
void Map :: SetRowL(int rl){RowL = rl;};
void Map :: SetColL(int cl){ColL = cl;};
void Map :: SetRowM(int rm){RowM = rm;};
void Map :: SetColM(int cm){ColM = cm;};
void Map :: SetRowP(int rp){RowP = rp;};
void Map :: SetColP(int cp){ColP = cp;};
// Getters
char** Map :: GetMaze() {return Maze;};
int Map :: GetRowNum() {return RowNum;};
int Map :: GetColNum() {return ColNum;};
int Map :: GetRowL(){return RowL;};
int Map :: GetColL(){return ColL;};
int Map :: GetRowM(){return RowM;};
int Map :: GetColM(){return ColM;};
int Map :: GetRowP(){return RowP;};
int Map :: GetColP(){return ColP;};

// Constuctors
Map :: Map (){};
Map :: Map(const string& FileName) {
    ifstream file(FileName);
    int RowNum;
    int ColNum;

   if (!file) {
        cerr << "Αδυναμία εύρεσης αρχείου: " << FileName << endl;
       exit(1);
    }

    file.seekg(0, ios::end);
    int fileSize = file.tellg();
    file.seekg(0, ios::beg);
    string line;
    int lineCount = 0;
    int maxLineSize = 0;
    while (getline(file, line)) {
        if (lineCount == 0) {
            maxLineSize = line.size();
            Maze = new char*[maxLineSize];
            for (int i = 0; i < maxLineSize; i++) {
                Maze[i] = new char[line.size()];
            }
        }
        for (int i = 0; i < maxLineSize; i++) {
            Maze[lineCount][i] = line[i];
        }
        lineCount++;
    }
    file.close();
    SetColNum(maxLineSize);
    SetRowNum(lineCount);
};

// Destructor
Map::~Map() {
    for (int i = 0; i < ColNum; i++) {
        delete[] Maze[i];
    }
    delete[] Maze;
};

// Map Display
void Map :: DisplayMap(WINDOW* win) {
    for (int i = 0; i < RowNum ; i++) {
        for (int j = 0; j < ColNum; j++) {
            if (Maze[i][j] == '*'){
                wattron(win, COLOR_PAIR(1));
            }else if (Maze[i][j] == '@'){
                wattron(win, COLOR_PAIR(2));
            } else if (Maze[i][j] == 'M'){
                wattron(win, COLOR_PAIR(3));
            } else if (Maze[i][j] == 'L'){
                wattron(win, COLOR_PAIR(4));
            }
            if (Maze[i][j] == '.'){
                mvwprintw(win, i, j, " ");
            }else {
                mvwprintw(win, i, j, "%c", Maze[i][j]);
            };
            wattroff(win, COLOR_PAIR(1));
            wattroff(win, COLOR_PAIR(2));
            wattroff(win, COLOR_PAIR(3));
            wattroff(win, COLOR_PAIR(4));
            wattroff(win, A_BOLD);
        }
    }
};

// Random Spawner
void Map :: RandCharacters() {
    srand(time(NULL));
    do{
        RowM = rand() % GetRowNum();
        ColM = rand() % GetColNum();
    } while(Maze[ColM][RowM] != '.');
    Maze[ColM][RowM] = 'M';
    
    do {
        RowL = rand() % GetRowNum();
        ColL = rand() % GetColNum();
    } while(Maze[ColL][RowL] != '.');
    Maze[ColL][RowL] = 'L'; 
    
    do {
        RowP = rand() % GetRowNum();
        ColP = rand() % GetColNum();
    } while(Maze[ColP][RowP] != '.');
    Maze[ColP][RowP] = '@'; 
};