//
//  Deck.h
//  Blackjack
//
//  Created by Gordon Freeman on 11/17/15.
//  Copyright © 2015 Patrick Kelly. All rights reserved.
//

#ifndef Deck_h
#define Deck_h

#include "Card.h"
#include <ostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
using std::string;
using std::vector;

class Deck : public Card
{
    bool deckarray[4][13];
    
public:
    Deck();
    ~Deck();
    void Shuffle();
    string getCard();
};

#endif /* Deck_hpp */
