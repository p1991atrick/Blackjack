//
//  Dealer.hpp
//  Blackjack
//
//  Created by Gordon Freeman on 12/3/15.
//  Copyright © 2015 Patrick Kelly. All rights reserved.
//

#ifndef Dealer_h
#define Dealer_h

#include "Deck.h"
using std::string;

class Dealer
{
    Deck deckone;
    unsigned int *total;
    string card1;
    string card2;
    string card3;
    string card4;
    string card5;
    bool hasAce;
    
public:
    Dealer();
    ~Dealer();
    
};

#endif /* Dealer_h */
