//
//  Card.cpp
//  Blackjack
//
//  Created by Gordon Freeman on 11/17/15.
//  Copyright © 2015 Patrick Kelly. All rights reserved.
//

#include "Card.h"



char Card::getCard(int* s, int* f) const
{
    return cards[*s][*f];
}