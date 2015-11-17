//
//  main.cpp
//  Blackjack
//
//  Created by Gordon Freeman on 11/17/15.
//  Copyright © 2015 Patrick Kelly. All rights reserved.
//

#include <iostream>
#include "Deck.h"
using std::cout;
int main(int argc, const char * argv[]) {
    
    std::cout << "Hello, World!\n";
    Deck deckone;
    int i =2, j = 9;
    
    cout << deckone.Card::getCard(&i, &j) << std::endl;
    
    return 0;
}
