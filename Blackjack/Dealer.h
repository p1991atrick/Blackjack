//
//  Dealer.h
//  Blackjack
//
//  Created by Gordon Freeman on 12/3/15.
//  Copyright © 2015 Patrick Kelly. All rights reserved.
//

#ifndef Dealer_h
#define Dealer_h

#include <ostream>
using std::string;

class Dealer
{
    unsigned int total;
    string card1;
    string card2;
    string card3;
    string card4;
    string card5;
    bool hasAce;
    
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
