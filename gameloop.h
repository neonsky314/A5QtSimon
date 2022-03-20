#ifndef GAMELOOP_H
#define GAMELOOP_H
#include <string>
#include "interface.h"

using namespace std;
class GameLoop
{
public:
    GameLoop();
    void run(Interface helper);
    void proc_com_turn(Interface helper);
};

#endif // GAMELOOP_H
