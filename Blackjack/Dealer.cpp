//
//  Dealer.cpp
//  Blackjack
//
//  Created by Gordon Freeman on 12/3/15.
//  Copyright © 2015 Patrick Kelly. All rights reserved.
//

#include "Dealer.h"
#include "Deck.h"


Dealer::Dealer()
{
    *total = 0;
    card1 = "";
    card2 = "";
    card3 = "";
    card4 = "";
    card5 = "";
    hasAce = false;
}

Dealer::~Dealer()
{
    delete[] total;
    delete[] &hasAce;
    delete[] &card2;
    delete[] &card1;
    delete[] &card3;
    delete[] &card4;
    delete[] &card5;
}