//
//  Savegame.cpp
//  Blackjack
//
//  Created by Gordon Freeman on 12/5/15.
//  Copyright © 2015 Patrick Kelly. All rights reserved.
//

#include "Savegame.h"


template <class T>
save<T>::save(int size)
{
    stackArray = new T[size];
    
}

template < class T >
save<T>::save(const save &obj)
{
    if(obj.stackSize > 0)
        stackArray = new T[obj.stackSize];
    else
        stackArray = nullptr;
    
}

template <class T>
save<T>::~save()
{
    if (stackSize > 0)
        delete [] stackArray;
}


template < class T >
void save<T>::push(T item)
{
    top++;
    stackArray[top] = item;
}

template<class T>
void save<T>::pop(T &item)
{
    item = stackArray[top];
    top--;
}


template < class T >
bool save<T>::isfull()
{
    bool status;
    
    if (top == stackSize -1)
        status = true;
    else
        status = false;
    
    return status;
}


template < class T >
bool save<T>::isempty()
{
    bool status;
    
    if (top == -1)
        status = true;
    else
        status = false;
    
    return status;
}


