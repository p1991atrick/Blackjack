//
//  Savegame.cpp
//  Blackjack
//
//  Created by Gordon Freeman on 12/5/15.
//  Copyright © 2015 Patrick Kelly. All rights reserved.
//

#include "Savegame.h"


template <class T>
Savegame<T>::Savegame()
{
    head = nullptr;
}

template <class T>
Savegame<T>::~Savegame()
{
    Save *nodePtr;
    Save *nextNode;
    
    nodePtr = head;
    
    while (nodePtr != nullptr)
    {
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
}
//template <class T>
//void Savegame<T>::setfilename(string filename)
//{
//    file = filename;
//}

template <class T>
void Savegame<T>::appendNode(T newValue)
{
    
    Save *newNode;
    Save *nodePtr;
    //allocate new node and store data there
    newNode = new Save;
    newNode->value = newValue;
    newNode->next = nullptr;
    //if no nodes, make new begining
    if (!head)
    {
        head = newNode;
    }
    else
    {
        nodePtr = head;
        
        while (nodePtr->next)
        {
            nodePtr = nodePtr->next;
        }
        
        nodePtr->next = newNode;
    }
    
}

template <class T>
void Savegame<T>::displayList() const
{
    Save *nodePtr;
    nodePtr = head;
    
    while (nodePtr)
    {
        //std::cout << nodePtr->value << std::endl;
        
        nodePtr = nodePtr->next;
    }
}

template <class T>
void Savegame<T>::insertNode(T newValue)
{
    Save *nodePtr;
    Save *newNode;
    Save * previousNode = nullptr;
    
    newNode = new Save;
    newNode->value = newValue;
    
    if (!head)
    {
        head = newNode;
        newNode->next = nullptr;
    }
    else
    {
        nodePtr = head;
        
        previousNode = nullptr;
        
        while (nodePtr != nullptr && nodePtr->value < newValue)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        
        if (previousNode == nullptr)
        {
            head = newNode;
            newNode->next = nodePtr;
        }
        else
        {
            previousNode->next = newNode;
            newNode->next = nodePtr;
        }
    }
}







