//
//  Player.h
//  Blackjack
//
//  Created by Gordon Freeman on 11/17/15.
//  Copyright © 2015 Patrick Kelly. All rights reserved.
//

#ifndef Player_h
#define Player_h

#include <ostream>
using std::string;

class Player
{   //ints to hold the count 
    int total;
    string name;
    string card1;
    string card2;
    string card3;
    string card4;
    string card5;
    bool hasAce;
public:
    Player();
    Player(string);
    ~Player();
    void calctotal(int);
    void stay();
    void hit(string);
    int CardTotal(int);
    std::string nameout()const;
    std::string returncards();
    void setname(string);
    int returnTotal();
    void reset();
    
};

#endif /* BlackJackDealer_hpp */
