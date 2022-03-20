#include "globals.h"
#include "gameloop.h"

int Globals::difficulty = 1;
int Globals::level = 1;
int Globals::countdown = 1000;
bool Globals::player_turn = false;
int Globals::health = 3;
int Globals::high_score = 0;
int Globals::player_input_count = 0;
vector<int> Globals::pattern;
GameLoop* Globals::simon = new GameLoop(); //call with new to ensure there is at least 1 number for the pattern generator
MyTimer Globals::clock;

Globals::Globals()
{
}
