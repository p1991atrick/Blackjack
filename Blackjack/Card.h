//
//  Card.hpp
//  Blackjack
//
//  Created by Gordon Freeman on 11/17/15.
//  Copyright © 2015 Patrick Kelly. All rights reserved.
//

#ifndef Card_h
#define Card_h

#include <string>
#include <ctime>

using std::string;

class Card
{
    char cards[4][13] ={
        {'2', '3', '4', '5', '6', '7', '8', '9', 'J', 'Q', 'K', 'A'},
        {'2', '3', '4', '5', '6', '7', '8', '9', 'J', 'Q', 'K', 'A'},
        {'2', '3', '4', '5', '6', '7', '8', '9', 'J', 'Q', 'K', 'A'},
        {'2', '3', '4', '5', '6', '7', '8', '9', 'J', 'Q', 'K', 'A'},};

public:
    char getCard(int* s, int* f) const;
};

#endif /* Card_hpp */
