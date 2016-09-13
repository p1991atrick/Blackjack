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
	strncpy(name, "empty", 5);
    hasAce = false;

}

Player::Player(char *playername)
{
    total = 0;
    strncpy(name, playername, strlen(playername));
    hasAce = false;
}

Player::~Player()
{
    delete name;
}


void Player::hit(char *card)
{
	//string tempcard(card);
	cards.push_back(card);
}

char * Player::nameout() const
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
char * Player::returncards()
{
	char *tempcstring = new char;
	for (int i=0;i<=cards.size()-1;i++)
	{
		strcat(tempcstring, cards[i].c_str());
		if (i<cards.size()-1)
			strcat(tempcstring, ", ");
	}
	return tempcstring;
}

int Player::CardTotal(int x)
{
    return total;
}

void Player::setname(char * lable)
{
	strcpy(name, lable);
}
void Player::reset()
{
	cards.resize(0);
	total = 0;
	hasAce = false;
}



