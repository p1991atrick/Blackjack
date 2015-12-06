//
//  BlackJackDealer.cpp
//  Blackjack
//
//  Created by Gordon Freeman on 11/17/15.
//  Copyright © 2015 Patrick Kelly. All rights reserved.
//

#include "Player.h"
#include <cstdlib>

Player::Player()
{
    total = 0;
    name = "empty";
    card1 = "0";
    card2 = "0";
    card3 = "0";
    card4 = "0";
    card5 = "0";
    hasAce = false;
}

Player::Player(std::string playername)
{
    total = 0;
    name = playername;
    card1 = "0";
    card2 = "0";
    card3 = "0";
    card4 = "0";
    card5 = "0";
    hasAce = false;
}

Player::~Player()
{
//    delete[] &total;
//    delete[] &name;
//    delete[] &hasAce;
//    delete[] &card2;
//    delete[] &card1;
//    delete[] &card3;
//    delete[] &card4;
//    delete[] &card5;
}


void Player::hit(string card)
{
    if (card1 == "0")
        card1 = card;
    else if (card2 == "0")
        card2 = card;
    else if (card3 == "0")
        card3 = card;
    else if (card4 == "0")
        card4 = card;
    else if (card5 == "0")
        card5 = card;
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
    tempstring += card1;
    tempstring += ", ";
    tempstring += card2;
    if(card3 != "0")
    {
        tempstring += ", ";
        tempstring += card3;
    }
    if (card4 != "0")
    {
        tempstring += ", ";
        tempstring += card4;
    }
    if (card5 != "0")
    {
        tempstring += ", ";
        tempstring += card5;
    }
    return tempstring;
}

int Player::CardTotal(int x)
{
    return total;
}
void Player::reset()
{
    card1 = "0";
    card2 = "0";
    card3 = "0";
    card4 = "0";
    card5 = "0";
    total = 0;
    hasAce = false;
}

void Player::setname(string lable)
{
    name = lable;
}