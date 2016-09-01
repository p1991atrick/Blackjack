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
	decknumber = rand() % 6;
    return blackjackDeck[decknumber].getCard();
}

int Dealer::givevalue()
{
    return blackjackDeck[decknumber].return_j();
}

void Dealer::hit(string card)
{
	cards.push_back(card);
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
   return cards[0];
}

std::string Dealer::returncards()
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

int Dealer::cardtotal(int x)
{
    return total;
}

void Dealer::reset()
{
	cards.resize(0);
	total = 0;
	hasAce = false;
}

