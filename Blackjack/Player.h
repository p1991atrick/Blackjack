//
//  BlackJackDealer.h
//  Blackjack
//
//  Created by Gordon Freeman on 11/17/15.
//  Copyright © 2015 Patrick Kelly. All rights reserved.
//

#ifndef BlackJackDealer_h
#define BlackJackDealer_h

#include <ostream>
using std::string;

class Player
{   //ints to hold the count 
    int* total;
    int localtotal;
    string name;
    string card1;
    string card2;
    string card3;
    string card4;
    string card5;
    bool hasAce;
    
public:
    Player();
    ~Player();
    //std::string DealCard();
    void stay();
    void hit();
    int CardTotal();
    void namein();
    std::string nameout();
    
    
};

#endif /* BlackJackDealer_hpp */
