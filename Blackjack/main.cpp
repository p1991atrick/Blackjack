//
//  main.cpp
//  Blackjack
//
//  Created by Gordon Freeman on 11/17/15.
//  Copyright © 2015 Patrick Kelly. All rights reserved.
//

/* -----------------------------------------------------------------------------
 
 FILE:              main.cpp
 
 DESCRIPTION:       driver for blackjack (21) game
 
 COMPILER:          GNU++11, MVS
 
 NOTES:             Might have build errors on MVS, but should still run
 
 MODIFICATION HISTORY:
 
 Author                  Date               Version
 ---------------         ----------         --------------
 Patrick Kelly           2015-12-1          Under Source Control
 
 ----------------------------------------------------------------------------- */

#include <iostream>
#include <iomanip>
#include <string>
#include <queue>
#include "Player.h"
#include "Dealer.h"
#include "Deck.h"
using std::cout;

//function prototypes
string CLI_Args(int argc, char * argv[]);
void Help();
void Game_setup(Dealer &dealer, Player &Player1, Player &Player2, Player &Player3, bool *havep2, bool *havep3, Deck &deck1, char * goagain);
void Game_play(Dealer &dealer, Player &Player1, Player &Player2, Player &Player3, bool *havep2, bool *havep3, Deck &deck1);
void Display_Board(Player &Player1, Player &Player2, Player &Player3, Dealer &dealer, bool *havep2, bool *havep3);
void Display_Board_end(Player &Player1, Player &Player2, Player &Player3, Dealer &dealer, bool *havep2, bool *havep3);
void Playerturn(Player &Player1, Deck &deck1);
void dealerturn(Dealer &dealer, Deck &deck1);
void Winners(Dealer &dealer, Player &Player1, Player &Player2, Player &Player3, bool *havep2, bool *havep3);


int main(int argc, char * argv[])
{
    std::string savefile = CLI_Args(argc, argv);
    //Dealer and vars
    Dealer dealer;
    Player Player1;
    Player Player2;
    Player Player3;
    Deck deck1;
    bool havep2;
    bool havep3;
    havep2 = false;
    havep3 = false;
    char goagain = 'N';
    
    //the game
    do{
        Game_setup(dealer, Player1, Player2, Player3, &havep2, &havep3, deck1, &goagain);
        Game_play(dealer, Player1, Player2, Player3, &havep2, &havep3, deck1);
        Display_Board_end(Player1, Player2, Player3, dealer, &havep2, &havep3);
        Winners(dealer, Player1, Player2, Player3, &havep2, &havep3);
        cout << "\n\nGo Again?   (y,N)\n";
        std::cin >> goagain;
    }while (goagain == 'y' || goagain == 'Y');
    return 0;
}


string CLI_Args(int argc, char * argv[])
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
                i++;
                return argv[i];
            }
        }
    }
    else
    {
        Help();
    }
    return "none";
}

void Help()
{
    cout << std::setw(20) << std::right << "Help Menu\n";
    cout << std::setw(15) << std::left << "-?" << "| " << "Shows this help menu\n";
    cout << std::setw(17) << std::right << "|\n";
    cout << std::setw(15) << std::left << "--Output-file" << "| " << "name of file for saving game\n\n";
    exit(5);
}

void Game_setup(Dealer &dealer, Player &Player1, Player &Player2, Player &Player3, bool * havep2, bool * havep3, Deck &deck1, char * goagain)
{
    
    int numofplayers;
    
    deck1.shuffle();
    
    //build players
    if(*goagain == 'n' || *goagain == 'N')
    {
        std::queue <string> PLAYERS;
        do{
            cout << "How many Players? (1-3)\n";
            std::cin >> numofplayers;
        }while (numofplayers < 1 || numofplayers > 3);

        for(int i = 0; i< numofplayers; i++)
        {
            std::string tempplayer;
            cout << "Enter name of player " << i+1 << ": ";
            std::cin >> tempplayer;
            PLAYERS.push (tempplayer);
            if (i==1)
                *havep2 = true;
            if (i==2)
                *havep3 = true;
        }
        Player1.setname(PLAYERS.front());
        if(*havep2 == true)
        {
            PLAYERS.pop();
            Player2.setname(PLAYERS.front());
        }
        if(*havep3 == true)
        {
            PLAYERS.pop();
            Player3.setname(PLAYERS.front());
        }
        
    }
    if(*goagain == 'y' || *goagain == 'Y')
    {
        dealer.reset();
        Player1.reset();
        if(*havep2 == true)
        {
            Player2.reset();
        }
        if(*havep3 ==true)
        {
            Player3.reset();
        }
    }
    
    //start game deal
    int x=0;
    cout << "Dealing....."<< std::endl;
    do{
        dealer.hit(deck1.getCard());
        dealer.calctotal(deck1.return_j());
        Player1.hit(deck1.getCard());
        Player1.calctotal(deck1.return_j());
        if(*havep2 == true)
        {
            Player2.hit(deck1.getCard());
            Player2.calctotal(deck1.return_j());
        }
        if(*havep3 == true)
        {
            Player3.hit(deck1.getCard());
            Player3.calctotal(deck1.return_j());
        }
        x++;
    }while(x<2);
}

void Game_play(Dealer &dealer, Player &Player1, Player &Player2, Player &Player3, bool *havep2, bool *havep3, Deck &deck1)
{
    Display_Board(Player1, Player2, Player3, dealer, havep2, havep3);
    Playerturn(Player1, deck1);
    if(*havep2 == true)
    {
        Display_Board(Player1, Player2, Player3, dealer, havep2, havep3);
        Playerturn(Player2, deck1);
    }
    if(*havep3 == true)
    {
        Display_Board(Player1, Player2, Player3, dealer, havep2, havep3);
        Playerturn(Player3, deck1);
    }
    dealerturn(dealer, deck1);
}

void Playerturn(Player &Playertemp, Deck &deck1)
{
    string hitstay = "stay";
    cout << Playertemp.nameout() << "'s  turn:\n";
    system( "read -n 1 -s -p \"Press any key to continue...\"\n" );
    cout << "\nHere are your Cards,\n";
    cout << Playertemp.returncards() << std::endl;
    cout <<"for a total of: " << Playertemp.returnTotal() << std::endl << std::endl;
    if(Playertemp.returnTotal() == 21)
    {
        cout << "You have Blackjack and win!\n";
    }
    else
    {
        do{
            cout << "Would you like to hit or Stay? \n";
            std::cin >> hitstay;
            if(hitstay == "Hit" || hitstay == "hit" || hitstay == "H" || hitstay == "h")
            {
                Playertemp.hit(deck1.getCard());
                Playertemp.calctotal(deck1.return_j());
                cout << "Your new cards are: \n";
                cout <<  Playertemp.returncards() << "\nAnd the total is: " << Playertemp.returnTotal() << std::endl << std::endl;
                if(Playertemp.returnTotal() > 21)
                {
                    cout << "Busted!!\n\n";
                    hitstay = "stay";
                }
                if (Playertemp.returnTotal() ==21)
                {
                    cout << "Blackjack!! You win\n";
                    hitstay= "stay";
                }
            }
        }while (hitstay == "Hit" || hitstay == "hit" || hitstay == "H" || hitstay == "h");
        
    }
    system( "read -n 1 -s -p \"Press any key to continue...\"\n" );
}

void dealerturn(Dealer &dealer, Deck &deck1)
{
    
    system("clear");
    cout << "\nThe Dealer will now play...\n\n";
    cout << "here are the Dealer's cards:\n";
    cout << dealer.returncards() << std::endl;
    cout << "for a total of: " <<  dealer.returntotal() << std::endl << std::endl;
    system( "read -n 1 -s -p \"Press any key to continue...\"\n" );
    if (dealer.returntotal() == 21)
    {
        cout << "Dealer has Blackjack!\n\n";
        system( "read -n 1 -s -p \"Press any key to continue...\"\n" );
    }
    else if (dealer.returntotal() < 17)
    {
        do{
            cout << "\nDealer must take another card:\n";
            dealer.hit(deck1.getCard());
            dealer.calctotal(deck1.return_j());
            cout << "The dealers new cards are:\n";
            cout << dealer.returncards() << std::endl;
            cout << "and the total is: " << dealer.returntotal() << std::endl << std::endl;
            if(dealer.returntotal() > 21)
            {
                cout << "Dealer busts!\n";
            }
            if (dealer.returntotal() ==21)
            {
                cout << "Dealer has Blackjack!\n";
            }
            system( "read -n 1 -s -p \"Press any key to continue...\"\n" );
        }while (dealer.returntotal() < 17);
    }
}

void Display_Board(Player &Player1, Player &Player2, Player &Player3, Dealer &dealer, bool *havep2, bool *havep3)
{
    system("clear");
    cout << std::setw(25) << std::right << "Here is the Board\n\n";
    cout << std::setw(20) << std::right << "Dealer has\n";
    cout << std::setw(20) << std::right <<  dealer.returncard1() << std::endl << std::endl;
    
}

void Display_Board_end(Player &Player1, Player &Player2, Player &Player3, Dealer &dealer, bool *havep2, bool *havep3)
{
    system("clear");
    cout << std::setw(25) << std::right << "Here is the Board\n\n";
    cout << std::setw(20) << std::right << "Dealer has:\n";
    cout <<  dealer.returncards() << std::endl << "with a total of: " << dealer.returntotal() << std::endl << std::endl;
    
    cout << std::setw(15) << Player1.nameout() << " has: \n";
    cout <<Player1.returncards() << std::endl << "With a total of: " << Player1.returnTotal() << std::endl << std::endl;
    if (*havep2 == true)
    {
        cout << std::setw(15) << Player2.nameout() << " has: \n";
        cout <<Player2.returncards() << std::endl << "With a total of: " << Player2.returnTotal() << std::endl << std::endl;
    }
    if (*havep3 == true)
    {
        cout << std::setw(15) << Player3.nameout() << " has: \n";
        cout <<Player3.returncards() << std::endl << "With a total of: " << Player3.returnTotal() << std::endl << std::endl;
    }

}

void Winners(Dealer &dealer, Player &Player1, Player &Player2, Player &Player3, bool *havep2, bool *havep3)
{
    bool p1 = false, p2 = false, p3 = false;
    //dealer has < 21
    if(dealer.returntotal() <21)
    {
        if (Player1.returnTotal() > dealer.returntotal() && Player1.returnTotal() <= 21)
        {
            cout << Player1.nameout() << " Wins\n";
            p1=true;
        }
        if (Player2.returnTotal() > dealer.returntotal() && Player2.returnTotal() <= 21 && *havep2 == true)
        {
            cout << Player2.nameout() << " Wins\n";
            p2=true;
        }
        if (Player3.returnTotal() > dealer.returntotal() && Player3.returnTotal() <= 21 && *havep3 == true)
        {
            cout << Player3.nameout() << " Wins\n";
            p3=true;
        }
        if(p1 == false && p2 == false && p3 == false)
        {
            if (Player1.returnTotal() == dealer.returntotal() || Player2.returnTotal() == dealer.returntotal() || Player3.returnTotal() == dealer.returntotal())
            {
                cout << "Draw.\n";
            }
            else
                cout << "Dealer Wins\n";
        }
    }
    //dealer bust
    else if(dealer.returntotal() > 21)
    {
        if (Player1.returnTotal() <= 21)
        {
            cout << Player1.nameout() << " Wins\n";
        }
        if (Player2.returnTotal() <= 21 && *havep2 == true)
        {
            cout << Player2.nameout() << " Wins\n";
        }
        if (Player3.returnTotal() <= 21 && *havep3 == true)
        {
            cout << Player3.nameout() << " Wins\n";
        }
    }
    //dealer has 21
    else if(dealer.returntotal() == 21)
    {
        cout << "Dealer Wins\n";
        if (Player1.returnTotal() == 21)
        {
            cout << Player1.nameout() << " Wins\n";
        }
        if (Player2.returnTotal() == 21 && *havep2 == true)
        {
            cout << Player2.nameout() << " Wins\n";
        }
        if (Player3.returnTotal() == 21 && *havep3 == true)
        {
            cout << Player3.nameout() << " Wins\n";
        }
    }
}







