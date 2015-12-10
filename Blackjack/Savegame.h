//
//  Savegame.h
//  Blackjack
//
//  Created by Gordon Freeman on 12/5/15.
//  Copyright © 2015 Patrick Kelly. All rights reserved.
//

#ifndef Savegame_h
#define Savegame_h

#include <ostream>
//#include "Dealer.h"
#include "Player.h"
using std::string;



template <class Player>
class DynStack
{
private:
    // Structure for stack nodes
    struct StackNode
    {
        Player value;        // Value in the node
        StackNode *next;  // Pointer to the next node
    };
    
    StackNode *top;      // Pointer to the stack top
    
public:
    // Constructor
    DynStack();
    
    // Destructor
    ~DynStack();
    
    // Stack operations
    void push( Player );
    void pop( Player & );
    bool isEmpty();
};



template < class T >
bool DynStack<T>::isEmpty()
{
    bool status;
    
    if (!top)
        status = true;
    else
        status = false;
    
    return status;
}
#endif /* Savegame_h */
