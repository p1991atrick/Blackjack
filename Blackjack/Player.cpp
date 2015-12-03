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
    total = &localtotal;
    *total = 0;
    name = "\0";
    card1 = "";
    card2 = "";
    card3 = "";
    card4 = "";
    card5 = "";
    hasAce = false;
}

Player::~Player()
{
    delete[] total;
    delete[] &name;
    delete[] &hasAce;
    delete[] &card2;
    delete[] &card1;
    delete[] &card3;
    delete[] &card4;
    delete[] &card5;
}

void Player::namein()
{
    
}
