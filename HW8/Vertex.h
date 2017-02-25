//
//file  :  Vertex.h
//author:  george j. grevera, ph.d.
//desc. :  this file contains the definition of the Vertex class.
//         a vertex i consists of an i, the value of its parent p, and a key
//         value.  the key value is the edge weight between i and p.
//         no changes necessary.
//Copyright (c) George J. Grevera, 2016.  All rights reserved.
//
#pragma once

#include  <iostream>
#include  <limits>
#include <float.h>

using namespace std;

class Vertex {

private:
    int     mI = -1;       //vertex number
    int     mP = -1;       //parent vertex number (-1 = null)
    double  mK = DBL_MAX;  //key value for this entry

public:
    //Vertex class ctor
    Vertex ( int i, double k, int p ) {
        mI = i;
        mK = k;
        mP = p;
    }
    //-----------------------------------------------------------------------
    //dtor (nothing to do)
    ~Vertex ( void ) {
        //prints are useful to determine when dtors are actually called (or not).
        cout << "Vertex::~Vertex " << hex << this << dec << endl;
    }
    //-----------------------------------------------------------------------
    //getter for vertex number
    int getI ( void )  {  return mI;  }
    //-----------------------------------------------------------------------
    //allow one to pretty print the contents of the Vertex object to an output
    // stream.
    friend ostream& operator<< ( ostream& os, const Vertex& v ) {
        os << "vertex: i=" << v.mI
           << " key=" << v.mK
           << " p=" << v.mP << endl;
        return os;
    }
    //-----------------------------------------------------------------------
    //do not use (used for priority queue sorting):
    Vertex ( void )  {  }
    //-----------------------------------------------------------------------
    //do not use (used for priority queue sorting):
    bool operator() ( const Vertex* v1, const Vertex* v2 ) {
        return v2->mK < v1->mK;
    }

};
