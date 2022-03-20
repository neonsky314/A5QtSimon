#include "gameloop.h"
#include "globals.h"
#include <vector>
#include <string>
#include <stdio.h>
#include <QDebug>

int random_generator();

GameLoop::GameLoop()
{
    //create first step in sequence
    Globals::pattern.push_back(random_generator());
}

void GameLoop::run(Interface helper)
{
    helper.turn_processing();
}

//Procces Computer turn functions ex: continue sequence
//Processes Game over
void GameLoop::proc_com_turn(Interface helper)
{
    //add random_number to pattern
    Globals::pattern.push_back(random_generator());

    //begin player turn
    Globals::player_turn = true;
    helper.turn_processing();
}

//generates random numbers for the simon pattern
//usess globals::difficulty*2 because there are 4 difficulty levels starting at 1
int random_generator()
{
    return rand() % (Globals::difficulty*2);
}
