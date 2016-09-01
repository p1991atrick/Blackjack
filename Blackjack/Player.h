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
#include <vector>
#include <cstdlib>

using std::vector;
using std::string;

class Player
{   //ints to hold the count 
    unsigned int total;
    string name;
	vector<string> cards;
    bool hasAce;
    //private functions

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
