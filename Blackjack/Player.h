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
    char *name = new char;
	vector<string> cards;
    bool hasAce;
    //private functions

public:
    Player();
    Player(char *);
    ~Player();
    void calctotal(int);
    void stay();
    void hit(char *);
    int CardTotal(int);
    char * nameout()const;
    char * returncards();
    void setname(char *);
    int returnTotal();
	void reset();
};

#endif /* BlackJackDealer_hpp */
