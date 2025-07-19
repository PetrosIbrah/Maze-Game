#include "Enemy.h"

// Constructor
Enemy :: Enemy(Map& a) : F(a) {
    Maze = F.GetMaze();
    RowNum = F.GetRowNum();
    ColNum = F.GetColNum();
    CurrentStep = 0;
} 
// Destructor
Enemy :: ~Enemy(){};

// Class Function for Finding the best path
void Enemy :: FindBestPath(Point Stone) {
    // Clear Path to restart a search in case the stone is not located at its initial position
    Path.clear();

    vector<vector<bool>> Visited((RowNum*ColNum), vector<bool>((ColNum*RowNum), false));
    vector<vector<Point>> Parent((RowNum*ColNum), vector<Point>((ColNum*RowNum), Point(-1, -1)));
    queue<Point> q;

    // Starting point
    Point Start(F.GetRowM(), F.GetColM());
    q.push(Start);
    // Check Visited 
    Visited[Start.Col][Start.Row] = true;

    // Possible directions And Best movement
    int dy[] = {-1, 1, 0, 0};
    int dx[] = {0, 0, -1, 1};
    // Using BFS algorithm to find the best Path
    while (!q.empty()) {
        Point Curr = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int NewCol = Curr.Col + dx[i];
            int NewRow = Curr.Row + dy[i];
            if (Validation(NewRow, NewCol) && !Visited[NewCol][NewRow] && Maze[NewCol][NewRow] != '*' && Maze[NewCol][NewRow] != 'L' ) {
                q.push(Point(NewRow, NewCol));
                Visited[NewCol][NewRow] = true;
                Parent[NewCol][NewRow] = Curr;
            }
        }
    }
    Point Current = Stone;

    // Create the Path
    while (Current.Col != -1 && Current.Row != -1) {
        Path.push_back(Current);
        Current = Parent[Current.Col][Current.Row];
    }
    // Clearing to properly restart the search when funtion is called again
    reverse(Path.begin(), Path.end());
    Visited.clear();
    Parent.clear();
    queue<Point>().swap(q);
};

// Move The Enemy When class funtion is called
void Enemy::MoveEnemy() {
    int dy[] = {-1, 1, 0, 0};
    int dx[] = {0, 0, -1, 1};
    Point Stone(F.GetRowP(), F.GetColP());
    FindBestPath(Stone);
    // Display and move Enemy accordingly to FindBestPath 
    if (Path.size() > 1) {
        Point Current = Path[1];
        Maze[F.GetColM()][F.GetRowM()] = '.';
        F.SetRowM(Current.Row);
        F.SetColM(Current.Col);
        Maze[F.GetColM()][F.GetRowM()] = 'M';
        Path.clear();
    } else {
        // In the rare case there is no valid movement, mainly because the Player counts as a blockable entity.
        do {
            int randomDirection = rand() % 4;  
            int NewCol = F.GetColM() + dx[randomDirection];
            int NewRow = F.GetRowM() + dy[randomDirection];
            if (Validation(NewRow, NewCol) && Maze[NewCol][NewRow] != '*' && Maze[NewCol][NewRow] != 'L') {
                Maze[F.GetColM()][F.GetRowM()] = '.';
                F.SetRowM(NewRow);
                F.SetColM(NewCol);
                Maze[F.GetColM()][F.GetRowM()] = 'M';
                break;
            }
        } while(1);
        
    }      
};

// A small Funtion to check if Row and Col are out of limits
bool Enemy :: Validation(int Row, int Col) {
    return (Col > 0 && Col < ColNum && Row > 0 && Row < RowNum);
}