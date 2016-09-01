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
#include <string>
#include <vector>
#include "Player.h"
#include "Dealer.h"
using std::cout;
using std::vector;
using std::cin;
using std::endl;

//function prototypes
void Help();
string CLI_Args(int argc, char * argv[]);
void Game_setup(Dealer *dealer, vector<Player> *Players, int *numofgames);
void Display_Board(Dealer *dealer);
void Display_Board_end(Dealer *dealer, vector<Player> *Players);
void Playerturn(Player *currentplayer, Dealer *dealer, string *hitstay);
void Game_play(Dealer *dealer, vector<Player> &Players);
void dealerturn(Dealer *dealer,string *hitstay);
void Winners(Dealer *dealer, vector<Player> *Players);
void Reset_Board(vector<Player> *Players, Dealer *dealer);


#endif /* main_h */
