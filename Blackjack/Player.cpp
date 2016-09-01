//
//  BlackJackDealer.cpp
//  Blackjack
//
//  Created by Gordon Freeman on 11/17/15.
//  Copyright © 2015 Patrick Kelly. All rights reserved.
//

#include "Player.h"

Player::Player()
{
    total = 0;
    name = "empty";
    hasAce = false;
}

Player::Player(std::string playername)
{
    total = 0;
    name = playername;
    hasAce = false;
}

Player::~Player()
{
//    delete[] &total;
//    delete[] &name;
//    delete[] &hasAce;
}


void Player::hit(string card)
{
	cards.push_back(card);
}
std::string Player::nameout() const
{
    return name;
}

void Player::calctotal(int x)
{
    if(x< 9)
    {
        total += (x+2);
    }
    else if (x >= 9 && x<=11)
    {
        total += 10;
    }
    else if (x==12)
    {
        if(total < 11)
        {
            total+=11;
            hasAce = true;
        }
        else
            total +=1;
    }
    if (total > 21 && hasAce == true)
    {
        total -= 10;
        hasAce = false;
    }
}

int Player::returnTotal()
{
    return total;
}
string Player::returncards()
{
	std::string tempstring;
	for (int i=0;i<=cards.size()-1;i++)
	{
		tempstring += cards[i];
		if (i<cards.size()-1)
			tempstring += ", ";
	}
	return tempstring;
}

int Player::CardTotal(int x)
{
    return total;
}

void Player::setname(string lable)
{
    name = lable;
}
void Player::reset()
{
	cards.resize(0);
	total = 0;
	hasAce = false;
}



