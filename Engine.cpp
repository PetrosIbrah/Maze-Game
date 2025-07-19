#include "Engine.h"

// Constructor
Engine :: Engine(){
    Window();
};
// Destructor
Engine :: ~Engine(){};

// Window initializations and main accessibility
void Engine :: Window() {
    system ("chcp 1253"); // Διαγραφή αν τρέχει σε Linux.
    system("cls"); // Διαγραφή αν τρέχει σε Linux.

    // Window initialization
    WINDOW* win;
    string MapName;

    // Call menu funtion.
    Menu(MapName);
    Map F(MapName);

    // Ncurses initialization
    initscr();
    raw();

    // Window creation and color declarations
    start_color();
    win = newwin(F.GetRowNum() + 2, F.GetColNum(), 0, 0);
    if (has_colors()) {
        use_default_colors();
        start_color();
        init_pair(1, COLOR_BLUE, COLOR_BLACK);
        init_pair(2, COLOR_YELLOW, -1);
        init_pair(3, COLOR_RED, -1);
        init_pair(4, COLOR_GREEN, -1);
    }
    refresh();
    cbreak();
    noecho();
    curs_set(0);

    // Key initialization
    keypad(win, TRUE);

    // Spawn Characters L, M and @ in random positions
    srand(time(NULL));
    F.RandCharacters();

    int key;
    int cnt=0;
    
    // Initialize Player, Enemy and Stone
    Player P(F);
    Enemy E(F);
    Stone S(F);
    // Display the Map on the Window
    F.DisplayMap(win);

    // Main Loop Breakable When Pressing ESC or Someone captures The Magical stone
    do {
        do {
            if(key != ERR){
                key = wgetch(win);
                switch (key) {
                    case KEY_UP:
                        P.MovePlayer(0, -1);
                        break;
                    case KEY_DOWN:
                        P.MovePlayer(0, 1);
                        break;
                    case KEY_LEFT:
                        P.MovePlayer(-1, 0);
                        break;
                    case KEY_RIGHT:
                        P.MovePlayer(1, 0);
                        break;
                    case ' ':
                        P.MovePlayer(0,0);
                        break;
                    case 27:
                        S.SetW(-1);
                        P.SetRegister(1);
                        break;
                }
                if (P.GetRegister()== 1){
                    break;
                }
            }
        } while (1);

        if (S.GetW() == -1){
            break;
        }
        cnt ++;
        E.MoveEnemy();
        S.Check();
        if (S.GetW()==1 || S.GetW() == 2){
            break;
        }
        
        clear();
        wclear(win);
        F.DisplayMap(win);
        refresh();
        wrefresh(win);
        
        // Teleport The magic stone randomly between 5 and 10 moves of the game.
        srand(time(NULL));
        if (key != ERR && (key == KEY_UP || key == KEY_DOWN || key == KEY_LEFT || key == KEY_RIGHT || key == ' ')) {
            if ((cnt % (5 + rand() % 11)) == 0) {
                S.RandP();
                cnt = 0;
            }
        }
    }while (1);
    endwin();
    // Displays the situation of the ended game (Win, lose or quit)
    if (S.GetW() == 1){
        cout << "ΝΊΚΗΣΑΤΕ!" << endl;
    } else if (S.GetW() == -1){
        cout << "Τερματισμός Παινχιδιού." << endl;
    } else {
        cout << "Χάσατε..." << endl;
    }
};

// Starting menu function
// Allowing the User choose one of the existing Maps or inputs another Map
void Engine :: Menu(string& MapName) {
    cout << "\033[2J\033[1;1H";
    cout << "Διαλέξτε ένα άπο τα παρακάτω." << endl;
    cout << "=============================" << endl;
    cout << "1. Χάρτης 1" << endl;
    cout << "2. Χάρτης 2" << endl;
    cout << "3. Βάτλε δικό σας Χάρτη" << endl;  
    cout << "=======================" << endl;
    int ch;
    do {
        cout << "Η επιλογή σας είναι: ";
        cin >> ch;
    } while (ch > 3);
    
    if (ch == 1) {
        cout << "=======================" << endl;
        MapName = "Maze.txt";
    } else if (ch == 2) {
        cout << "=======================" << endl;
        MapName = "Maze2.txt";
    } else {
        cout << "Το όνομα του αρχείου σας είναι: ";
        cin >> MapName;
        cout << "===============================" << endl;
    }
};