//
//  Savegame.cpp
//  Blackjack
//
//  Created by Gordon Freeman on 12/5/15.
//  Copyright © 2015 Patrick Kelly. All rights reserved.
//

#include "Savegame.h"


template <class T>
DynStack<T>::DynStack()
{
    top = 0; 
}


template < class T >
DynStack<T>::~DynStack()
{
    StackNode *nodePtr, *nextNode;
    
    // Position nodePtr at the top of the stack.
    nodePtr = top;
    
    // Traverse the list deleting each node.
    while (nodePtr != 0)
    {
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
}


template < class T >
void DynStack<T>::push( T Player )
{
    StackNode *newNode; // Pointer to a new node
    
    // Allocate a new node and store num there.
    newNode = new StackNode;
    newNode->value = Player;
    
    // If there are no nodes in the list
    // make newNode the first node.
    if (isEmpty())
    {
        top = newNode;
        newNode->next = 0;
    }
    else  // Otherwise, insert NewNode before top.
    {
        newNode->next = top;
        top = newNode;
    }
}


