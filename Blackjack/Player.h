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
    unsigned int total;
    string name;
    string card1;
    string card2;
    string card3;
    string card4;
    string card5;
    bool hasAce;
    //private functions
    std::string Card1() const;
    std::string Card2() const;
    std::string Card3() const;
    std::string Card4() const;
    std::string Card5() const;
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
