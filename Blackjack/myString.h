//
//  myString.hpp
//  Project 2
//
//  Created by Gordon Freeman on 10/13/15.
//  Copyright © 2015 Patrick Kelly. All rights reserved.
//

#ifndef myString_h
#define myString_h

/* -----------------------------------------------------------------------------
 
 FILE:              myString.h
 
 DESCRIPTION:       Custom string class
 
 COMPILER:          MSVS2013 and GNU g++
 
 NOTES:             None
 
 MODIFICATION HISTORY:
 
 Author                  Date               Version
 ---------------         ----------         --------------
 Patrick Kelly           2015-10-15         X.X (can't change)
 
 ----------------------------------------------------------------------------- */
#include <iostream>
using std::ostream;

class myString
{
    
private:
    char * data;
    int    bfrsz;
    
public:
    // Construction and destruction
    myString   ();
    myString   (const char* s);
    myString   (const myString& str);
    ~myString  ();
    
    // Member functions
    myString& append     (const char* s);
    size_t    capacity   () const;
    void      clear      ();
    int       compare    (const char* s) const;
    int       compare    (const myString& str) const;
    bool      empty      () const;
    size_t    length     () const;
    myString& operator+= (char c);
    myString& operator+= (const char* s);
    myString& operator+= (const myString& str);
    myString& operator=  (char c);
    myString& operator=  (const char* s);
    myString& operator=  (const myString& str);
    void      reserve    (size_t n = 0);
    void      resize     (size_t n);
    void      resize     (size_t n, char c);
    size_t    size       () const;
    myString  substr     (size_t pos = 0, size_t len = 1) const;
    void      swap       (myString& str);
    
    // Non-member overloads
    friend ostream&  operator<< (ostream& os, const myString& str);
    
    // Optional member functions
    char&     at         (size_t pos);
    char&     operator[] (size_t pos);
    
};

#endif // __MYSTRING_H__
