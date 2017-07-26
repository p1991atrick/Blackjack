//
//  BlackJackDealer.h
//  Blackjack
//
//  Created by Gordon Freeman on 11/17/15.
//  Copyright © 2015 Patrick Kelly. All rights reserved.
//

#ifndef BlackJackDealer_h
#define BlackJackDealer_h

#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::string;

class Player
{   //ints to hold the count 
    unsigned int total;
    char *name = new char[25];
	vector<char *> cards;
    bool hasAce;
	double cash;
	double currentbid;

public:
    Player();
    Player(char *);
	Player(char *, int *);
    ~Player();
	void calctotal(int);//money functions
	void addcash(double);
	double getcash();
	double setbet(double *, int a = 0);
	void hit(char *);//game functions
    char * nameout()const;
    char* returncards();
    void setname(char *);
    int returnTotal();
	void reset();
	void winner(int w=0);
};

#endif /* BlackJackDealer_hpp */
