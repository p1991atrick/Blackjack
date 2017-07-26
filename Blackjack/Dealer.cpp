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

}

char * Dealer::givecard()
{
	decknumber = rand() % 6;
	char *toreturn = new char[35];
	strcpy(toreturn, blackjackDeck[decknumber].getCard());
    return toreturn;
}

int Dealer::givevalue()
{
    return blackjackDeck[decknumber].return_j();
}

void Dealer::hit(char *card)
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

char * Dealer::returncard1()
{
	char *card = new char[30];
	int length = static_cast<int>(strlen(cards[0])+1);
	strncpy(card, cards[0], length);
	return card;
}

char * Dealer::returncards()
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

