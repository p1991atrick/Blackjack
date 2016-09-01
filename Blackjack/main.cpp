//
//  main.cpp
//  Blackjack
//
//  Created by Gordon Freeman on 11/17/15.
//  Copyright © 2015 Patrick Kelly. All rights reserved.
//
#include "main.h"

int main(int argc, char * argv[])
{
	std::string savefile = CLI_Args(argc, argv);
    //Dealer and vars
    Dealer dealer;
    vector<Player> Players;
	int numofgames = 1;

    
    //the game
	char continueplay = 'n';
	do{
		Game_setup(&dealer, &Players, &numofgames);
		Game_play(&dealer, Players);
		Display_Board_end(&dealer, &Players);
		Winners(&dealer, &Players);
		cout << "Would you like to play again (y or n):  ";
		std::cin >> continueplay;
		Reset_Board(&Players, &dealer);
	}while(continueplay == 'y');

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
            if (strcmp(arg, "--output-file")==0)
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

void Game_setup(Dealer *dealer, vector<Player> *Players, int *numofgames)
{
    if (*numofgames == 1)
	{
		int numofplayers;
		do{
		cout << "How many Players are there? (1-5)\n";
		std::cin >> numofplayers;
		}while (numofplayers < 1 || numofplayers > 5);

		Players->resize(numofplayers);
		
		//build players
		for(int i = 0; i< numofplayers; i++)
		{
			string name;
			cout << "Enter name of player " << i+1 << ": ";
			cin >> name;
			Players->at(i).setname(name);
		}
	}
    //start game deal
    int x=0;
    cout << "Dealing....."<< std::endl;
    do{
        dealer->hit(dealer->givecard());
        dealer->calctotal(dealer->givevalue());
		for (int i=0;i<Players->size();i++)
		{
			Players->at(i).hit(dealer->givecard());
			Players->at(i).calctotal(dealer->givevalue());
		}
		x++;
    }while(x<2);
}

void Game_play(Dealer *dealer, vector<Player> &Players)
{
    string hitstay = "stay";
	for (int i=0;i<Players.size();i++)
	{
		Display_Board(dealer);
		Player *currentplayer = &Players[i]; //pointer to current vector record
		Playerturn(currentplayer, dealer, &hitstay);
	}
	dealerturn(dealer, &hitstay);
}

void Playerturn(Player *currentplayer, Dealer *dealer, string *hitstay)
{
    cout << currentplayer->nameout() << "'s  turn:\n";
    system( "read -n 1 -s -p \"Press any key to return to continue...\"\n" );
    cout << "\nHere are your Cards,\n";
    cout << currentplayer->returncards() << std::endl;
    cout <<"for a total of: " << currentplayer->returnTotal() << std::endl << std::endl;
    if(currentplayer->returnTotal() == 21)
    {
        cout << "You have Blackjack and win!\n";
    }
    else
    {
        do{
            cout << "Would you like to hit or Stay? \n";
            std::cin >> *hitstay;
            if(*hitstay == "Hit" || *hitstay == "hit" || *hitstay == "H" || *hitstay == "h")
            {
                currentplayer->hit(dealer->givecard());
                currentplayer->calctotal(dealer->givevalue());
                cout << "Your new cards are: \n";
                cout <<  currentplayer->returncards() << "\nAnd the total is: " << currentplayer->returnTotal() << std::endl << std::endl;
                if(currentplayer->returnTotal() > 21)
                {
                    cout << "Busted!!\n\n";
                    *hitstay = "stay";
                }
                if (currentplayer->returnTotal() ==21)
                {
                    cout << "Blackjack!! You win\n";
                    *hitstay = "stay";
                }
            }
        }while (*hitstay == "Hit" || *hitstay == "hit" || *hitstay == "H" || *hitstay == "h");
        
    }
    system( "read -n 1 -s -p \"Press any key to continue...\"\n" );
}

void dealerturn(Dealer *dealer,string *hitstay)
{
    system("clear");
    cout << "\nThe Dealer will now play...\n\n";
    cout << "here are the Dealer's cards:\n";
    cout << dealer->returncards() << std::endl;
    cout << "for a total of: " <<  dealer->returntotal() << std::endl << std::endl;
	if (dealer->returntotal() < 16)
	{
		cout << "\nDealer doesn't have 16 and must take another card:\n";
	}
    system( "read -n 1 -s -p \"Press any key to continue...\"\n" );
    if (dealer->returntotal() == 21)
    {
        cout << "\n\nDealer has Blackjack!\n\n";
        system( "read -n 1 -s -p \"Press any key to continue...\"\n" );
    }
    else if (dealer->returntotal() < 16)
    {
        do{
            dealer->hit(dealer->givecard());
            dealer->calctotal(dealer->givevalue());
            cout << "The dealers new cards are:\n";
            cout << dealer->returncards() << std::endl;
            cout << "and the total is: " << dealer->returntotal() << std::endl << std::endl;
            if(dealer->returntotal() > 21)
            {
                cout << "Dealer busts!\n";
            }
            if (dealer->returntotal() ==21)
            {
                cout << "Dealer has Blackjack!\n";
            }
            system( "read -n 1 -s -p \"Press any key to continue...\"\n" );
        }while (dealer->returntotal() < 17);
    }
}

void Display_Board(Dealer *dealer)
{
    system("clear");
    cout << std::setw(25) << std::right << "Here is the Board\n\n";
    cout << std::setw(20) << std::right << "Dealer has\n";
    cout << std::setw(20) << std::right <<  dealer->returncard1() << std::endl << std::endl;
    
}

void Display_Board_end(Dealer *dealer, vector<Player> *Players)
{
    system("clear");
    cout << std::setw(25) << std::right << "Here is the Board\n\n";
    cout << std::setw(20) << std::right << "Dealer has:\n";
    cout << dealer->returncards() << std::endl << "with a total of: " << dealer->returntotal() << std::endl << std::endl;
	int i=0;
	for (;i<Players->size();i++)
	{
		cout << std::setw(15) << Players->at(i).nameout() << " has: \n";
		cout << Players->at(i).returncards() << endl << "With a total of: " << Players->at(i).returnTotal() << endl << endl;
	}
}

void Winners(Dealer *dealer, vector<Player> *Players)
{
	//dealer has < 21
    if(dealer->returntotal() <21)
    {
		for (int i=0;i<Players->size();i++)
		{
			if (Players->at(i).returnTotal() > dealer->returntotal() && Players->at(i).returnTotal() <= 21)
			{
				cout << Players->at(i).nameout() << " Wins!\n";
			}

			else if (Players->at(i).returnTotal() == dealer->returntotal())
			{
				cout << Players->at(i).nameout() << " Tied with the dealer.\n";
			}
			else
				cout << Players->at(i).nameout() << " Lost to the dealer.\n";
		}
    }
    //dealer bust
    else if(dealer->returntotal() > 21)
    {
		for (int i=0;i<Players->size();i++)
		{
			if (Players->at(i).returnTotal() <= 21)
				cout << Players->at(i).nameout() << " Wins!\n";
		}
	}
    //dealer has 21
    else if(dealer->returntotal() == 21)
    {
        cout << "Dealer Wins\n";
		for (int i=0;i<Players->size();i++)
		{
			if (Players->at(i).returnTotal() == 21)
				cout << Players->at(i).nameout() << " Wins!\n";
		}
	}
}

void Reset_Board(vector<Player> *Players, Dealer *dealer)
{
	for (int i=0;i<Players->size();i++)
	{
		Players->at(i).reset();
	}
	dealer->reset();
}

















