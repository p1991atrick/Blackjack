//
//  main.h
//  Blackjack
//
//  Created by Gordon Freeman on 9/1/16.
//  Copyright © 2016 Patrick Kelly. All rights reserved.
//

#ifndef main_h
#define main_h


#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include "Player.h"
#include "Dealer.h"
#include <cstring>

using std::cout;
using std::vector;
using std::cin;
using std::endl;
using std::fstream;
using std::ios;
using std::setw;
using std::right;
using std::left;


//function prototypes
void Help();
char * CLI_Args(int argc, char * argv[]);
void Game_setup(Dealer *dealer, vector<Player> *Players, int *numofgames);
void Display_Board(Dealer *dealer);
void Display_Board_end(Dealer *dealer, vector<Player> *Players);
void Playerturn(Player *currentplayer, Dealer *dealer);
void Game_play(Dealer *dealer, vector<Player> *Players);
void dealerturn(Dealer *dealer);
void Winners(Dealer *dealer, vector<Player> *Players);
void Write_to_file(fstream *outputfile, Dealer *dealer, vector<Player> * Players, int*);
void Reset_Board(vector<Player> *Players, Dealer *dealer);


#endif /* main_h */
