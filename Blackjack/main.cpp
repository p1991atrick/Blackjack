//
//  main.cpp
//  Blackjack
//
//  Created by Gordon Freeman on 11/17/15.
//  Copyright © 2015 Patrick Kelly. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <string>
#include "Player.h"
#include "Dealer.h"
using std::cout;

//function prototypes
void CLI_Args(int argc, char * argv[]);
void Help();
void Game_setup();
void Game_play(int numofplayers, string PLAYERS[], Dealer dealer, Player Player1, Player Player2, Player Player3);
int main(int argc, char * argv[])
{
    //CLI_Args(argc, argv);
    //Dealer and vars
    Game_setup();
    return 0;
}


void CLI_Args(int argc, char * argv[])
{
    if (argc > 1)
    {
        for (int i = 1; i< argc; i++)
        {
            char * arg = argv[i];
            if(arg[0] != '-')
                Help();
            if (strcmp(arg, "-?")==0 || strcmp(arg, "-h")==0)
            {
                Help();
            }
            if (strcmp(arg, "--Output-file")==0)
            {
                exit(1);
            }
        }
    }
    else
    {
        Help();
    }
}

void Help()
{
    cout << std::setw(20) << std::right << "Help Menu\n";
    cout << std::setw(15) << std::left << "-?" << "| " << "Shows this help menu\n";
    cout << std::setw(17) << std::right << "|\n";
    cout << std::setw(15) << std::left << "--Output-file" << "| " << "name of file for saving game\n\n";
    exit(5);
}

void Game_setup()
{
    Dealer dealer;
    int numofplayers;
    string PLAYERS[4];
    do{
    cout << "How many Players? (1-3)\n";
    std::cin >> numofplayers;
    }while (numofplayers < 1 || numofplayers > 3);
    
    //build players
    for(int i = 0; i< numofplayers; i++)
    {
        cout << "Enter name of player " << i+1 << ": ";
        std::cin >> PLAYERS[i];
    }
   // Deck::shuffle();
    Player Player1;
    Player Player2;
    Player Player3;
    Game_play(numofplayers, &PLAYERS[4], dealer, Player1, Player2, Player3);
}

void Game_play(int numofplayers, string PLAYERS[4], Dealer dealer, Player Player1, Player Player2, Player Player3)
{
//    Dealer.DealCard();
//    if (numofplayers == 3)
//    {
//        Player1.DealCard();
//        Player2.DealCard();
//        Player3.DealCard();
//    }
    
}























