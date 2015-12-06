//
//  Dealer.cpp
//  Blackjack
//
//  Created by Gordon Freeman on 12/3/15.
//  Copyright © 2015 Patrick Kelly. All rights reserved.
//

#include "Dealer.h"
#include "Deck.h"


Dealer::Dealer()
{
    total = 0;
    card1 = "0";
    card2 = "0";
    card3 = "0";
    card4 = "0";
    card5 = "0";
    hasAce = false;
}

Dealer::~Dealer()
{
//    delete[] &total;
//    delete[] &hasAce;
//    delete[] &card2;
//    delete[] &card1;
//    delete[] &card3;
//    delete[] &card4;
//    delete[] &card5;
}


void Dealer::hit(string card)
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

void Dealer::calctotal(int x)
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
            total+=11;
        else
            total +=1;
        hasAce = true;
    }
}

int Dealer::returntotal() const
{
    return total;
}

std::string Dealer::returncard1()
{
   return card1;
}

std::string Dealer::returncards()
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

void Dealer::reset()
{
    card1 = "0";
    card2 = "0";
    card3 = "0";
    card4 = "0";
    card5 = "0";
    total = 0;
    hasAce = false;
}
