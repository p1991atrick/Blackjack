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
using std::string;

class Deck
{
    //variables
    unsigned int shuffleyet;
    int ii;
    int* i; //suite
    int jj;
    int* j; //value
                // i , j
    bool deckarray[4][13];
//private functions
    void getValue() ;
    void getSuite() ;
    void CardUsed();
public:
    Deck();
    ~Deck();
    string getCard();
    int return_i() const;
    int return_j() const;
    void shuffle();
};

#endif /* Deck_hpp */
