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
using std::string;

template <class T>
class save
{
private:
    T *stackArray;
    int stackSize;
    int top;
    
    
public:
    save(int);
    save(const save&);
    ~save();
    void push(T);
    void pop(T &);
    bool isfull();
    bool isempty();
};



#endif /* Savegame_h */
