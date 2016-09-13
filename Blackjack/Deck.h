//
//  Deck.h
//  Blackjack
//
//  Created by Gordon Freeman on 11/17/15.
//  Copyright © 2015 Patrick Kelly. All rights reserved.
//

#ifndef Deck_h
#define Deck_h


#include <ostream>
#include <ctime>
#include <cstdlib>
#include <cstring>

class Deck
{
    //variables
    unsigned short int shuffleyet;
    short int* i = new short int; //suite
    short int* j = new short int; //value
                // i , j
    bool deckarray[4][13];
//private functions
    void getValue() ;
    void getSuite() ;
    void CardUsed();
public:
    Deck();
    ~Deck();
    char * getCard();
    int return_i() const;
    int return_j() const;
    void shuffle();
};

#endif /* Deck_hpp */
