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
    //fill vector with string values
    cards.push_back("Two of ");
    cards.push_back("Three of ");
    cards.push_back("Four of ");
    cards.push_back("Five of ");
    cards.push_back("Six of ");
    cards.push_back("Seven of ");
    cards.push_back("Eight of ");
    cards.push_back("Nine of ");
    cards.push_back("Ten of ");
    cards.push_back("Jack of ");
    cards.push_back("Queen of ");
    cards.push_back("King of ");
    cards.push_back("Ace of ");
}

Deck::~Deck()
{
    //delete[] deckarray;
}

void Deck::getValue()
{
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

std::string Deck::getCard()
{
    //find open card
    CardUsed();
    //print what it is
    std::string tempstring;
    
    tempstring = cards[*j];
    {//find suite
        if(*i == 0)
        {
            tempstring = tempstring + "Clubs";
        }
        else if (*i == 1)
        {
            tempstring = tempstring + "Diamonds";
        }
        else if (*i == 2)
        {
            tempstring = tempstring + "Hearts";
        }
        else if (*i == 3)
        {
            tempstring = tempstring + "Spades";
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



