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
	cash = 0;
	currentbid = 0;
}

Player::Player(char *playername)
{
    total = 0;
    strncpy(name, playername, strlen(playername));
    hasAce = false;
	cash = 0;
	currentbid = 0;
}

Player::Player(char *playername, int *startingcash)
{
	total = 0;
	strncpy(name, playername, strlen(playername));
	hasAce = false;
	cash = *startingcash;
	currentbid = 0;
}

Player::~Player()
{
    delete[] name;
}

void Player::addcash(double x)
{
	cash += x;
}

double Player::getcash()
{
	return cash;
}

double Player::setbet(double *betamount, int a)
{
	currentbid = *betamount;
	if (currentbid < cash)
	{
		cash = cash - currentbid;
		return 0;
	}
	else if (currentbid >= cash && a == 0) //all in
	{
		return 1;
	}
	else if (currentbid >= cash && a ==1)
	{
		currentbid = cash;
		cash = 0;
		return 0;
	}
	else return 2;//can never get returned
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
	char *tempstring = new char[50];
	for (int i=0;i<=cards.size()-1;i++)
	{
		strncat(tempstring, cards[i], strlen(cards[i]));
		if (i<cards.size()-1)
			strncat(tempstring, ", ", 2);
	}
	return tempstring;
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

void Player::winner(int w)
{
	if (total == 21 && w == 0)
	{
		currentbid *= 3;
		cash += currentbid;
	}
	else if (total == 21 && w == 1)
	{
		cash += currentbid;
	}
	if (total < 21 && w ==0)
	{
		currentbid *= 2;
		cash += currentbid;
	}
}


