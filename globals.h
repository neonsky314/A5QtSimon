#ifndef GLOBALS_H
#define GLOBALS_H
#include "gameloop.h"
#include "mytimer.h"
#include <vector>
class Globals
{
public:
    static int difficulty; // number of rows available
    static int level; // score
    static int health; //remaining attemps at a correct pattern
    static int high_score; // highest recorded score (not persistent)
    static int countdown; // countdown in ms for the pattern timer
    static int player_input_count; // number of buttons the player has pressed
    static GameLoop *simon; // game logic processor
    static bool player_turn;
    static vector<int> pattern; // current simon pattern
    static MyTimer clock;
    Globals();
};

#endif // GLOBALS_H
