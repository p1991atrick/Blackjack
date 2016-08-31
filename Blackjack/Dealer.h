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
    Deck blackjackDeck[6];
	unsigned int total;
	vector
    string card1;
    string card2;
    string card3;
    string card4;
    string card5;
    bool hasAce;
	int decknumber;
    //private functions
    std::string Card1() const;
    std::string Card2() const;
    std::string Card3() const;
    std::string Card4() const;
    std::string Card5() const;
    
public:
    Dealer();
    ~Dealer();
    std::string givecard();
    void calctotal(int);
    int returntotal() const;
    int givevalue() ;
    void hit(string);
    int cardtotal(int);
    std::string returncards();
    std::string returncard1();
	void reset();
};

#endif /* Dealer_h */
