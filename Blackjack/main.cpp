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
	char *savefile = CLI_Args(argc, argv);
	fstream outputfile;
	outputfile.open(savefile, ios::out | ios::trunc);
	//Dealer and vars
    Dealer dealer;
    vector<Player> Players;
	int numofgames = 1;
    
    //the game
	char continueplay = 'n';
	do{
		Game_setup(&dealer, &Players, &numofgames);
		Game_play(&dealer, &Players);
		Display_Board_end(&dealer, &Players);
		Winners(&dealer, &Players);
		Write_to_file(&outputfile, &dealer, &Players, &numofgames);
		cout << "Would you like to play again (y or n):  ";
		cin >> continueplay;
		numofgames++;
		Reset_Board(&Players, &dealer);
	}while(continueplay == 'y' || continueplay == 'Y');
	outputfile.close(); /* <-- very importaint !! */
	delete savefile;
    return 0;
}


char * CLI_Args(int argc, char * argv[])
{
	char * returnable = new char[50];
	strncpy(returnable, "temp", 5);
    if (argc > 1)
    {
        for (int i = 1; i< argc; i++)
        {
            char *arg = argv[i];
            if(arg[0] != '-')
                Help();
            if (strcmp(arg, "-?")==0 || strcmp(arg, "-h")==0)
            {
                Help();
            }
            if (strncmp(arg, "--output-file", 14)==0)
            {
                i++;
				arg = argv[i];
				if (strlen(arg) <= 30 && strstr(arg, ".txt")!=0)
				{
					strcpy(returnable, arg);
				}
				else if (strlen(arg) > 30 && strstr(arg, ".txt")!=0)
				{
					strncpy(returnable, arg, 30);
				}
				else if (strlen(arg) > 26 && strstr(arg, ".txt")==0)
				{
					strncpy(returnable, arg, 26);
					strncat(returnable, ".txt", 4);
				}
				else if (strlen(arg) <= 26 && strstr(arg, ".txt")==0)
				{
					strncpy(returnable, arg, (strlen(arg)+1));
					strncat(returnable, ".txt", 4);
				}
            }
        }
    }
    else
    {
        Help();
		strncpy(returnable, "none", 4);
    }
	return returnable;
}

void Help()
{
    cout << setw(20) << right << "Help Menu\n";
    cout << setw(15) << left << "-?" << "| " << "Shows this help menu\n";
    cout << setw(17) << right << "|\n";
    cout << setw(15) << left << "--Output-file" << "| " << "name of file for saving game\n\n";
    exit(5);
}

void Game_setup(Dealer *dealer, vector<Player> *Players, int *numofgames)
{
    if (*numofgames == 1)
	{
		int numofplayers;
		do{
		cout << "How many Players are there?: ";
		cin >> numofplayers;
		}while (numofplayers < 1);

		Players->resize(numofplayers);
		
		//build players
		for(int i = 0; i< numofplayers; i++)
		{
			char name[26];
			cout << "Enter name of player " << i+1 << ": ";
			cin >> name;
			Players->at(i).setname(name);
			double *cashonhand = new double;
			cout << "How much money does " << Players->at(i).nameout() << " want to start with?: ";
			cin >> *cashonhand;
			Players->at(i).addcash(*cashonhand);
		}
	}
    //start game deal
    int x=0;
    cout << "Dealing....."<< endl;
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

void Game_play(Dealer *dealer, vector<Player> *Players)
{
	for (int i=0;i<Players->size();i++)
	{
		Display_Board(dealer);
		Playerturn(&Players->at(i), dealer);
	}
	dealerturn(dealer);
}

void Playerturn(Player *currentplayer, Dealer *dealer)
{
	char *hitstay = new char[6];
	strncpy(hitstay, "stay", 4);
    cout << currentplayer->nameout() << "'s  turn...\n";
    system( "read -n 1 -s -p \"Press any key to continue...\"\n" );
	//bid system     ----------------------------------------------------------------------
	cout << "You have $" << currentplayer->getcash() << endl;
	cout << "How much will you bet this hand?: ";
	double *currentbet = new double;
	cin >> *currentbet;
	while (currentplayer->setbet(currentbet) == 1)
	{
		cout << "This bet will have you go all in, is this alright? (y/n): ";
		char *yesno = new char;
		cin >> yesno;
		if (*yesno == 'n' || *yesno == 'N')
		{
			cout << "Enter new bet: ";
			cin >> *currentbet;
			currentplayer->setbet(currentbet);
		}
		else
		{
			currentplayer->setbet(currentbet, 1);
		}
	}
	//play system
    cout << "\nHere are your Cards:\n";
    cout << setw(15) << right << currentplayer->returncards() << endl;
    cout <<"for a total of: " << currentplayer->returnTotal() << endl << endl;
    if(currentplayer->returnTotal() == 21)
    {
        cout << "You have Blackjack and win!\n";
    }
    else
    {
        do{
            cout << "Would you like to hit or Stay?: ";
            cin >> hitstay;
            if(strncmp(hitstay, "Hit", 4) || strncmp(hitstay, "hit", 4) || strncmp(hitstay, "H", 2) || strncmp(hitstay, "h", 2))
            {
                currentplayer->hit(dealer->givecard());
                currentplayer->calctotal(dealer->givevalue());
                cout << "\nYour new cards are: \n";
                cout << setw(15) << right << currentplayer->returncards() << "\nAnd the total is: " << currentplayer->returnTotal() << endl << endl;
                if(currentplayer->returnTotal() > 21)
                {
                    cout << "Busted!!\n\n";
                    strncpy(hitstay, "stay", 4);
                }
                if (currentplayer->returnTotal() == 21)
                {
                    cout << "Blackjack!! You win\n";
                    strncpy(hitstay, "stay", 4);
                }
            }
        }while (strncmp(hitstay, "Hit", 4) || strncmp(hitstay, "hit", 4) || strncmp(hitstay, "H", 2) || strncmp(hitstay, "h", 2));
        
    }
    system( "read -n 1 -s -p \"Press any key to continue...\"\n" );
	delete[] hitstay;
}

void dealerturn(Dealer *dealer)
{
    system("clear");
    cout << "\nThe Dealer will now play...\n\n";
    cout << "here are the Dealer's cards:\n";
    cout << dealer->returncards() << endl;
    cout << "for a total of: " <<  dealer->returntotal() << endl << endl;
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
            cout << dealer->returncards() << endl;
            cout << "and the total is: " << dealer->returntotal() << endl << endl;
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
    cout << setw(25) << right << "Here is the Board\n\n";
    cout << setw(20) << right << "Dealer has\n";
    cout << setw(20) << right <<  dealer->returncard1() << endl << endl;
    
}

void Display_Board_end(Dealer *dealer, vector<Player> *Players)
{
    system("clear");
    cout << setw(25) << right << "Here is the Board\n\n";
    cout << setw(sizeof("Dealer")+15) << right << "Dealer has:\n";
    cout << dealer->returncards() << endl << "\nwith a total of: " << dealer->returntotal() << endl << endl;
	int i=0;
	for (;i<Players->size();i++)
	{
		cout << setw(20) << right<< Players->at(i).nameout() << " has: \n";
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
				Players->at(i).winner();
			}

			else if (Players->at(i).returnTotal() == dealer->returntotal())
			{
				cout << Players->at(i).nameout() << " Tied with the dealer.\n";
				Players->at(i).winner(1);
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
			{
				cout << Players->at(i).nameout() << " Wins!\n";
				Players->at(i).winner();
			}
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
void Write_to_file(fstream *fout, Dealer *dealer, vector<Player> * Players, int *numofgames)
{
	*fout << setw(20) << right << "Game Number " << *numofgames << endl << endl;
	*fout << setw(10) << right << "Dealer's total was: " << dealer->returntotal() << endl;
	*fout << setw(10) << right << "Dealer's cards: " << dealer->returncards() << endl;
	for (int i=0;i<Players->size();i++)
	{
		*fout << setw(10) << right << "Player " << i+1 << " (" << Players->at(i).nameout() << ") had: " << Players->at(i).returnTotal() << endl;
		*fout << setw(10) << right << Players->at(i).nameout() << "'s cards are: " << Players->at(i).returncards() << endl;
	}
	*fout << endl << endl << endl;

}

void Reset_Board(vector<Player> *Players, Dealer *dealer)
{
	for (int i=0;i<Players->size();i++)
	{
		Players->at(i).reset();
	}
	dealer->reset();
}

















