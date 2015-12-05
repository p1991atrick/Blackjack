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

std::string Dealer::givecard()
{
    return deckone.getCard();
}

int Dealer::givevalue()
{
    return deckone.return_j();
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
   return Card1();
}

std::string Dealer::returncards()
{
    std::string tempstring;
    tempstring += Card1();
    tempstring += ", ";
    tempstring += Card2();
    if(card3 != "0")
    {
        tempstring += ", ";
        tempstring += Card3();
    }
    if (card4 != "0")
    {
        tempstring += ", ";
        tempstring += Card4();
    }
    if (card5 != "0")
    {
        tempstring += ", ";
        tempstring += Card5();
    }
    return tempstring;
}

int Dealer::cardtotal(int x)
{
    return total;
}

string Dealer::Card1() const
{
    return card1;
    
}
string Dealer::Card2() const
{
    return card2;
    
}

string Dealer::Card3() const
{
    return card3;
    
}
string Dealer::Card4() const
{
    return card4;
    
}
string Dealer::Card5() const
{
    return card5;
    
}
