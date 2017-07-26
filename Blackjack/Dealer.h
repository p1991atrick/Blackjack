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
#include <vector>

using std::vector;

class Dealer
{
    Deck blackjackDeck[6];
	unsigned int total;
	vector<char *> cards;
    bool hasAce;
	int decknumber;

public:
    Dealer();
    ~Dealer();
    char * givecard();
    void calctotal(int);
    int returntotal() const;
    int givevalue() ;
    void hit(char *);
    int cardtotal(int);
    char * returncards();
    char * returncard1();
	void reset();
};

#endif /* Dealer_h */
