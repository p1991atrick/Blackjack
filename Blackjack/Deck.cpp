//
//  Deck.cpp
//  Blackjack
//
//  Created by Gordon Freeman on 11/17/15.
//  Copyright © 2015 Patrick Kelly. All rights reserved.
//

#include "Deck.h"
#include <iostream>
using namespace std;


Deck::Deck()
{
    for(int i=0; i<4; i++)
    {
        for (int j=0; j<13; j++)
        {
            deckarray[i][j] = false;
        }
    }
}

Deck::~Deck()
{
    //delete deckarray[52];
}

char Deck::getCard()
{
    //generate random seed
    srand(int(time(NULL)));
    //rand ints
    int i=0, j=0;
    //do while loop to only use new cards
    do{
        while (i >= 4)
        {
            i = rand()%4;
        }
        while (j >=13)
        {
            j = rand()%13;
        }
    }while (deckarray[i][j] == true);
    return Card::getCard(&i, &j);
}


void Deck::Shuffle()
{
    Deck();
    
}