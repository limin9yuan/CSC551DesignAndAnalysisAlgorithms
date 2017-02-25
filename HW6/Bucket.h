#pragma once
// file  : Bucket.h
// author: Mingyuan Li
// desc. : this file contains the Bucket class definition.

#include <iostream>
using namespace std;

class Bucket {

public:
    double   mData = -1;       //data value for bucket
    Bucket*  mNext = nullptr;  //ptr to next bucket

    //bucket dtor.
    //  note that this cascades destruction to the next element in the list.
    //  that way, the entire list is dtor's automagically.
    ~Bucket ( void ) {
        cout << "in ~Bucket() dtor" << endl;
        if (mNext != nullptr) {
            delete mNext;
            mNext = nullptr;
        }
    }
    //-----------------------------------------------------------------------
    //allow one to pretty print the contents of a bucket to an output stream.
    //  note that this cascades printing to the next element in the list.
    //  that way, the entire list is printed automagically.
    friend ostream& operator<< ( ostream& os, const Bucket& b ) {
        if (b.mNext != nullptr)    os << "  mData=" << b.mData << "  mNext=" << *b.mNext;
        else                       os << "  mData=" << b.mData << "  mNext=null";
        return os;
    }

};
