#ifndef ENGINE_H
#define ENGINE_H

#include "Player.h"
#include "Enemy.h"
#include "Map.h"
#include "Stone.h"

// Class Engine Containing ncurses and Window initializations
// But Also uses other classes to display and Move Characters
// (Created So Main.cpp wont have to execute these actions)
// ==========================================================
class Engine {
    public:
        Engine();
        ~Engine();
        void Window();
        void Menu(string& MapName);
}; 

#endif