//
//  Deck.cpp
//  Blackjack
//
//  Created by Gordon Freeman on 11/17/15.
//  Copyright © 2015 Patrick Kelly. All rights reserved.
//

#include "Deck.h"
//using namespace std;


Deck::Deck()
{
    shuffleyet = 0;
    Deck::shuffle();
    //generate random seed
    srand(int(time(NULL)));
}

Deck::~Deck()
{
   // delete[] &deckarray;
}

void Deck::getValue()
{
    if (shuffleyet > 45)
    {
        shuffle();
    }
    //rand ints
    //do while loop to only use new cards
    do{
        //sleep(1);
        *j = ((rand()*rand())%13);
        if(*j < 0)
            *j = *j * -1;
    }while (*j > 13);
}

void Deck::getSuite()
{
    //rand int
    do{
        *i = (rand()%4);
    }while(*i >= 4);
}


void Deck::CardUsed()
{
    do{
    //run verify for rand card
    getValue();
    getSuite();
    }while (deckarray[*i][*j] == true);
    deckarray[*i][*j] = true;
}

char * Deck::getCard()
{
    //find open card
    CardUsed();
    shuffleyet++;
    //print what it is
	char *tempstring = new char;
    {//find value
        if(*j == 0)
            strncpy(tempstring, "2", 1);
        else if (*j == 1)
            strncpy(tempstring, "3", 1);
        else if (*j == 2)
            strncpy(tempstring, "4", 1);
        else if (*j == 3)
            strncpy(tempstring, "5", 1);
        else if (*j == 4)
            strncpy(tempstring, "6", 1);
        else if (*j == 5)
            strncpy(tempstring, "7", 1);
        else if (*j == 6)
            strncpy(tempstring, "8", 1);
        else if (*j == 7)
            strncpy(tempstring, "9", 1);
        else if (*j == 8)
            strncpy(tempstring, "10", 2);
        else if (*j == 9)
            strncpy(tempstring, "Jack", 4);
        else if (*j == 10)
            strncpy(tempstring, "Queen", 5);
        else if (*j == 11)
            strncpy(tempstring, "King", 4);
        else if (*j == 12)
            strncpy(tempstring, "Ace", 3);
    }

    {//find suite
        if(*i == 0)
        {
            strncat(tempstring, " of Clubs", 9);
        }
        else if (*i == 1)
        {
            strncat(tempstring, " of Dimonds", 11);
        }
        else if (*i == 2)
        {
            strncat(tempstring, " of Hearts", 10);
        }
        else if (*i == 3)
        {
            strncat(tempstring, " of Spades", 10);
        }
    }
    return tempstring;
}


int Deck::return_i() const
{
    return *i;
}


int Deck::return_j() const
{
    return *j;
}

void Deck::shuffle()
{
    for(int i=0; i<4; i++)
    {
        for (int j=0; j<13; j++)
        {
            deckarray[i][j] = false;
        }
    }
}



