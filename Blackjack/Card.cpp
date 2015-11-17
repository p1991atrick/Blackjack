//
//  Card.cpp
//  Blackjack
//
//  Created by Gordon Freeman on 11/17/15.
//  Copyright © 2015 Patrick Kelly. All rights reserved.
//

#include "Card.h"



std::string Card::getCard(int* s, int* f) const
{
    std::string tempstring;
    tempstring = cards[*s][*f];
    if(*s == 0)
    {
        tempstring = tempstring + " of Clubs";
    }
    if(*s == 1)
    {
        tempstring = tempstring + " of Dimonds";
    }
    if(*s == 2)
    {
        tempstring = tempstring + " of Hearts";
    }
    if(*s == 3)
    {
        tempstring = tempstring + " of Spades";
    }
    return tempstring;
}