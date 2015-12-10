//
//  Savegame.h
//  Blackjack
//
//  Created by Gordon Freeman on 12/5/15.
//  Copyright © 2015 Patrick Kelly. All rights reserved.
//

#ifndef Savegame_h
#define Savegame_h

#include <iostream>
#include "Dealer.h"
#include "Player.h"
using std::string;
//using std::cout;


template <class T>
class Savegame
{
    struct Save
    {
        T value;
        struct Save *next;
    };
    Save *head;
public:
    Savegame();
    ~Savegame();
    
    //linked list ops
    void appendNode(T);
    void insertNode(T);
    void deleteNode(T);
    void displayList() const;
};
#endif /* Savegame_h */
