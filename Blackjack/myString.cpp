//
//  myString.cpp
//  Project 2
//
//  Created by Gordon Freeman on 10/13/15.
//  Copyright © 2015 Patrick Kelly. All rights reserved.
//
/* -----------------------------------------------------------------------------
 
 FILE:              myString.cpp
 
 DESCRIPTION:       Custom string class
 
 COMPILER:          MSVS2013 and GNU g++
 
 NOTES:             None
 
 MODIFICATION HISTORY:
 
 Author                  Date               Version
 ---------------         ----------         --------------
 Patrick Kelly           2015-10-15         1.0
 Patrick Kelly           2015-11-2          2.0
 Patrick Kelly           2015-11-11         3.0
 ----------------------------------------------------------------------------- */
#include "myString.h"
#include <iostream>
#include <cstring>

using namespace std;

/* -----------------------------------------------------------------------------
 FUNCTION:          mystring()
 DESCRIPTION:       default constructor for myString
 RETURNS:           Void function
 NOTES:
 ----------------------------------------------------------------------------- */
myString::myString()
{
    //default data null
    data = new char[1];
    data[0]=0;
    //buffer to 0
    bfrsz = 1;
}

/* -----------------------------------------------------------------------------
 FUNCTION:          mystring(const char* s)
 DESCRIPTION:       default overloaded constructor for myString
 RETURNS:           Void function
 NOTES:
 ----------------------------------------------------------------------------- */
myString::myString(const char* s)
{
    //set buffer size to length of string
    bfrsz = (int)std::strlen(s);
    //initialize data size and clear it
    data = new char[bfrsz + 1];
    data[bfrsz] = 0;
    //load s into data
    strncpy(data, s, bfrsz);
}

/* -----------------------------------------------------------------------------
 FUNCTION:          mystring(const myString& str)
 DESCRIPTION:       Copy constructor for class
 RETURNS:           Void function
 NOTES:
 ----------------------------------------------------------------------------- */
myString::myString(const myString& str)
{
    //initialize buffer size
    bfrsz = *new int; strlen(str.data);
    //initialize data cstring to 
    data = new char[bfrsz +1];
    data[bfrsz]='\0';
    //copy to data cstring
    strncpy(data, str.data, bfrsz);
}

/* -----------------------------------------------------------------------------
 FUNCTION:          ~mystring()
 DESCRIPTION:       destructor for class
 RETURNS:           Void function
 NOTES:
 ----------------------------------------------------------------------------- */
myString::~myString()
{
    //destructor
#if SHOW_TRACE
    cout << ".....in destructor.....\n";
#endif
    //removes char's stored in data
    delete[] data;
}

/* -----------------------------------------------------------------------------
 FUNCTION:          myString& append(const char* s)
 DESCRIPTION:       append function for class
 RETURNS:           the final object after adding the cstrings together
 NOTES:
 ----------------------------------------------------------------------------- */
myString& myString::append(const char *s)
{
#if SHOW_TRACE
    cout << ".....in append.....\n";
#endif
    //create temp pointer for original string
    char *tempstring = new char(bfrsz+1);
    tempstring[bfrsz+1] = '\0';
    //copy data into tempsting
    strncpy(tempstring, data, bfrsz+1);
    //reset data size to *s + data
    data = new char(bfrsz + strlen(s) + 1);
    data[bfrsz+1] = '\0';
    //load tempstring back into data
    strncpy(data, tempstring, bfrsz+1);
    delete tempstring;
    //append *s on to data
    strcat(data, s);
    bfrsz = int(bfrsz + strlen(s));
    return *this;
}

/* -----------------------------------------------------------------------------
 FUNCTION:          size_t myString::capacity() const
 DESCRIPTION:       bfrsz size in an int
 RETURNS:           bfrsz
 NOTES:
 ----------------------------------------------------------------------------- */
size_t myString::capacity() const
{
    return bfrsz;
}

/* -----------------------------------------------------------------------------
 FUNCTION:          void clear()
 DESCRIPTION:       clears contents of data
 RETURNS:           void
 NOTES:
 ----------------------------------------------------------------------------- */
void myString::clear()
{
    memset(data, 0, strlen(data));
}

/* -----------------------------------------------------------------------------
 FUNCTION:          int compare(const char* s) const;
 DESCRIPTION:       compairs the cstring given to the data string
 RETURNS:           an int (<0, 0, or >0)
 NOTES:             for given text
 ----------------------------------------------------------------------------- */
int myString::compare(const char *s) const
{
    return strcmp(data, s);
}

/* -----------------------------------------------------------------------------
 FUNCTION:          int compare(const myString& str) const;
 DESCRIPTION:       compairs the cstring given to the data string
 RETURNS:           an int (<0, 0, or >0)
 NOTES:             for data
 ----------------------------------------------------------------------------- */
int myString::compare(const myString& str) const
{
    return strcmp(data, str.data);
}

/* -----------------------------------------------------------------------------
 FUNCTION:          bool empty() const;
 DESCRIPTION:       checks for data length
 RETURNS:           bool bfrszempty
 NOTES:
 ----------------------------------------------------------------------------- */
bool myString::empty() const
{
    //temp bool variable for true/false
    bool bfrszempty = false;
    //check for data string length = to 0
    if (strlen(data) == 0)
    {
        bfrszempty = true;
    }
    return bfrszempty;
}

/* -----------------------------------------------------------------------------
 FUNCTION:          size_t myString::length() const
 DESCRIPTION:       length of the string in Bytes
 RETURNS:           string length
 NOTES:
 ----------------------------------------------------------------------------- */
size_t myString::length() const
{
    return bfrsz;
}

/* -----------------------------------------------------------------------------
 FUNCTION:          myString& myString::operator+= (char c)
 DESCRIPTION:       appends one char to the end of the string
 RETURNS:           new string (*this)
 NOTES:
 ----------------------------------------------------------------------------- */
myString& myString::operator+= (char c)
{
    //create temp char
    char *tempchar = new char(bfrsz +1);
    tempchar[bfrsz+1]='\0';
    //move data to tempchar
    strncpy(tempchar, data, bfrsz+1);
    //reinitialize data
    bfrsz = bfrsz+1;
    data = new char(bfrsz + 1);
    data[bfrsz] = '\0';
    //copy tempchar into data
    strncpy(data, tempchar, bfrsz+1);
    delete tempchar;
    //add c onto data and recalculate bfrsz
    strcat(data, &c);
    //current string
    return *this;
}

/* -----------------------------------------------------------------------------
 FUNCTION:          myString& myString::operator+= (const char *s)
 DESCRIPTION:       appends string to the end of the string
 RETURNS:           new string (*this)
 NOTES:
 ----------------------------------------------------------------------------- */
myString& myString::operator+= (const char* s)
{
    //create temp char
    char *tempstring = new char(bfrsz +1);
    tempstring[bfrsz+1]='\0';
    //move data to tempchar
    strncpy(tempstring, data, bfrsz);
    //empty data
    delete[] data;
    //reinitialize data
    data = new char(bfrsz + strlen(s) + 1);
    data[bfrsz+1 + strlen(s)] = '\0';
    //copy tempchar into data
    strncpy(data, tempstring, bfrsz);
    delete tempstring;
    //add c onto data and recalculate bfrsz
    strcat(data, s);
    bfrsz = int(bfrsz + strlen(s));
    //current string
    return *this;
}

/* -----------------------------------------------------------------------------
 FUNCTION:          myString& myString::operator+= (const string& str)
 DESCRIPTION:       appends string to the end of the string
 RETURNS:           new string (*this)
 NOTES:
 ----------------------------------------------------------------------------- */
myString& myString::operator+= (const myString& str)
{
    //create temp char
    char *tempstring = new char(bfrsz +1);
    tempstring[bfrsz]='\0';
    //move data to tempchar
    strncpy(tempstring, data, bfrsz);
    //reinitialize data
    data = new char(bfrsz + strlen(str.data) + 1);
    data[bfrsz + strlen(str.data)] = '\0';
    //copy tempchar into data
    strncpy(data, tempstring, bfrsz);
    //add str onto data and recalculate bfrsz
    strcat(data, str.data);
    bfrsz = int(bfrsz + strlen(str.data));
    //current string
    delete tempstring;
    return *this;
    
}

/* -----------------------------------------------------------------------------
 FUNCTION:          myString& myString::operator= (char c)
 DESCRIPTION:       replaces data with char 'c'
 RETURNS:           new string (*this)
 NOTES:
 ----------------------------------------------------------------------------- */
myString& myString::operator=(char c)
{
    //clear data and rest bfrsz;
    bfrsz = 1;
    data = new char[bfrsz+1];
    data[bfrsz] = '\0';
    //replace data[0] with c
    data[0] = c;
    return *this;
}

/* -----------------------------------------------------------------------------
 FUNCTION:          myString& operator=  (const char* s)
 DESCRIPTION:       replaces data with string S
 RETURNS:           new string (*this)
 NOTES:
 ----------------------------------------------------------------------------- */
myString& myString::operator=(const char* s)
{
    //clear data and rest bfrsz
    bfrsz = int(strlen(s));
    data = new char[bfrsz+1];
    data[bfrsz] = '\0';
    //load S into data
    strncpy(data, s, bfrsz);
    return *this;
}

/* -----------------------------------------------------------------------------
 FUNCTION:          myString& operator=  (const myString& str)
 DESCRIPTION:       replaces data with string str
 RETURNS:           new string (*this)
 NOTES:
 ----------------------------------------------------------------------------- */
myString& myString::operator= (const myString& str)
{
    //clear data and rest bfrsz
    bfrsz = int(strlen(str.data));
    data = new char[bfrsz+1];
    data[bfrsz] = '\0';
    //load S into data
    strncpy(data, str.data, bfrsz+1);
    return *this;
}

/* -----------------------------------------------------------------------------
 FUNCTION:          void myString::reserve(size_t n)
 DESCRIPTION:       resizes data size to n if needed
 RETURNS:           void
 NOTES:
 ----------------------------------------------------------------------------- */
void myString::reserve(size_t n)
{
    if (bfrsz > n)
    {
        //create tempstring to hold data
        char *tempstring = new char[bfrsz+1];
        tempstring[bfrsz]='\0';
        strncpy(tempstring, data, bfrsz);
        //recreate data with size n
        data = new char[n+1];
        data[n] = '\0';
        //move tempstring back into data and reset bfrsz
        strncpy(data, tempstring, n);
        bfrsz=int(n);
        delete[] tempstring;
    }
}

/* -----------------------------------------------------------------------------
 FUNCTION:          void myString::resize(size_t n)
 DESCRIPTION:       resizes data size
 RETURNS:           void
 NOTES:             can cut off end of text
 ----------------------------------------------------------------------------- */
void myString::resize (size_t n)
{
    //create tempstring to hold data
    char *tempstring = new char[bfrsz+1];
    tempstring[bfrsz+1]='\0';
    strncpy(tempstring, data, bfrsz);
    //recreate data with size n
    data = new char[n+1];
    data[n] = '\0';
    //move tempstring back to data with n length
    strncpy(data, tempstring, n);
    bfrsz=int(n);
    delete[] tempstring;
}

/* -----------------------------------------------------------------------------
 FUNCTION:          void myString::resize(size_t n, char c)
 DESCRIPTION:       resizes data size
 RETURNS:           void
 NOTES:             can cut off end of text
 ----------------------------------------------------------------------------- */
void myString::resize (size_t n, char c)
{
    //create temp string
    char *tempstring = new char[bfrsz+1];
    tempstring[bfrsz+1]='\0';
    strncpy(tempstring, data, bfrsz);
    //resize data and fill with tempstring or c
    data = new char[n+1];
    data[n]= c;
    for(int i=0; i<n; i++)
    {
        if(i<bfrsz)
        {
            data[i]=tempstring[i];
        }
        else if (i>=bfrsz)
        {
            data[i] = c;
        }
    }
    //move tempstring back to data with n length
    bfrsz=int(n);
    delete[] tempstring;
}

/* -----------------------------------------------------------------------------
 FUNCTION:          size_t myString::size () const
 DESCRIPTION:       duplicate of length()
 RETURNS:           size of string in bytes
 NOTES:             just calls length()
 ----------------------------------------------------------------------------- */
size_t myString::size () const
{
    return myString::length();
}


/* -----------------------------------------------------------------------------
 FUNCTION:          myString myString::substr (size_t pos, size_t len) const
 DESCRIPTION:       creates new string out of current one
 RETURNS:           the new string
 NOTES:
 ----------------------------------------------------------------------------- */
myString myString::substr (size_t pos, size_t len) const
{
    //setup variables
    int count = 0;
    myString string;
    string = '\0';
    //if position is out of range stop with error
    if(pos>bfrsz)
    {
        cout << "Not a valid position, pick a location within the string.\n";
    }
    //continue with replacement
    else if (pos < bfrsz)
    {
        //move though data coping the amount of char's as needed
        for (int i = int(pos-1); i < int(pos+len); i++)
        {
            //check for end of string
            if (i<=bfrsz)
            {
                string.data[count]=data[i];
                count++;
            }
        }
    }
    return string;
}

/* -----------------------------------------------------------------------------
 FUNCTION:          void myString::swap (myString& str)
 DESCRIPTION:       creates new string out of current one
 RETURNS:           void
 NOTES:
 ----------------------------------------------------------------------------- */
void myString::swap (myString& str)
{
    //temp string holder
    char *tempstr = new char[bfrsz+1];
    tempstr[bfrsz]='\0';
    int lenstr = 0;
    //move data to tempstr
    strncpy(tempstr, data, bfrsz);
    lenstr = bfrsz;
    //copy str to data
    bfrsz = int(strlen(str.data));
    strncpy(data, str.data, bfrsz);
    //copy temstr to str
    myString::~myString();
    data = new char[lenstr+1];
    data[lenstr]= '\0';
    strncpy(str.data, tempstr, lenstr);
}

/* -----------------------------------------------------------------------------
 FUNCTION:          ostream&  operator<< (ostream& os, const myString& str)
 DESCRIPTION:       sends str to ostream
 RETURNS:           os
 NOTES:
 ----------------------------------------------------------------------------- */
ostream&  operator<< (ostream& os, const myString& str)
{
    //send str to ostream file
    os << str.data;
    //return file
    return os;
}



































