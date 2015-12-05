//
//  Deck.cpp
//  Blackjack
//
//  Created by Gordon Freeman on 11/17/15.
//  Copyright © 2015 Patrick Kelly. All rights reserved.
//

#include "Deck.h"
#include <iostream>
//using namespace std;


Deck::Deck()
{
    i= &ii;
    j= &jj;
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
    
    //rand ints
    //do while loop to only use new cards
    do{
        sleep(1);
        *j = ((rand()*rand())%13);
        if(*j < 0)
            *j = *j * -1;
    }while (*j > 13);
}

void Deck::getSuite()
{
    //rand int
    do{
        //sleep(.2335333);
        *i = (rand()%4);
    }while(*i >= 4);
}


void Deck::CardUsed()
{
    do{
    //run verify for rand card
    getSuite();
    //sleep(1);
    getValue();
    }while (deckarray[*i][*j] == true);
    deckarray[*i][*j] = true;
}

std::string Deck::getCard()
{
    //find open card
    CardUsed();
    //print what it is
    std::string tempstring;
    {//find value
        if(*j == 0)
            tempstring = "2";
        else if (*j == 1)
            tempstring = "3";
        else if (*j == 2)
            tempstring = "4";
        else if (*j == 3)
            tempstring = "5";
        else if (*j == 4)
            tempstring = "6";
        else if (*j == 5)
            tempstring = "7";
        else if (*j == 6)
            tempstring = "8";
        else if (*j == 7)
            tempstring = "9";
        else if (*j == 8)
            tempstring = "10";
        else if (*j == 9)
            tempstring = "Jack";
        else if (*j == 10)
            tempstring = "Queen";
        else if (*j == 11)
            tempstring = "King";
        else if (*j == 12)
            tempstring = "Ace";
    }

    {//find suite
        if(*i == 0)
        {
            tempstring = tempstring + " of Clubs";
        }
        else if (*i == 1)
        {
            tempstring = tempstring + " of Dimonds";
        }
        else if (*i == 2)
        {
            tempstring = tempstring + " of Hearts";
        }
        else if (*i == 3)
        {
            tempstring = tempstring + " of Spades";
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



