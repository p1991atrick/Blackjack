//
//  Deck.hpp
//  Blackjack
//
//  Created by Gordon Freeman on 11/17/15.
//  Copyright © 2015 Patrick Kelly. All rights reserved.
//

#ifndef Deck_hpp
#define Deck_hpp

#include <stdio.h>
#include <iostream>

class Deck
{
    //Clubs
    bool C2;
    bool C3;
    bool C4;
    bool C5;
    bool C6;
    bool C7;
    bool C8;
    bool C9;
    bool CJ;
    bool CQ;
    bool CK;
    bool CA;
    //Dimonds
    bool D2;
    bool D3;
    bool D4;
    bool D5;
    bool D6;
    bool D7;
    bool D8;
    bool D9;
    bool DJ;
    bool DQ;
    bool DK;
    bool DA;
    //Hearts
    bool H2;
    bool H3;
    bool H4;
    bool H5;
    bool H6;
    bool H7;
    bool H8;
    bool H9;
    bool HJ;
    bool HQ;
    bool HK;
    bool HA;
    //Spades
    bool S2;
    bool S3;
    bool S4;
    bool S5;
    bool S6;
    bool S7;
    bool S8;
    bool S9;
    bool SJ;
    bool SQ;
    bool SK;
    bool SA;
public:
    //Member Functions
    void shuffle();
    void deal(int n);   //number of cards to deal
    
};

#endif /* Deck_hpp */
