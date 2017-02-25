#pragma once
//
//file  :  Edge.h
//author:  george j. grevera, ph.d.
//desc. :  this file contains the definition of the Edge class.
//         an edge  consists of a u, a v, and a weight.
//         no changes necessary.
//Copyright (c) George J. Grevera, 2016.  All rights reserved.
//
#include  <iostream>

using namespace std;

class Edge {

private:
    int     mFrom   = -1;    //'from' vertex (i.e., u in <u,v>)
    int     mTo     = -1;    //'to'   vertex (i.e., v in <u,v>)
    double  mWeight = -1;    //weight associated with this edge

public:
    Edge ( int from, int to, double weight ) {
        mFrom   = from;
        mTo     = to;
        mWeight = weight;
    }
    //-----------------------------------------------------------------------
    //dtor (nothing to do)
    ~Edge ( void ) {
        //prints are useful to determine when dtors are actually called (or not).
        //cout << "Edge::~Edge" << endl;
    }
    //-----------------------------------------------------------------------
    //getters:
    double getW    ( void ) {  return mWeight;  }
    int    getFrom ( void ) {  return mFrom;    }
    int    getTo   ( void ) {  return mTo;      }
    //-----------------------------------------------------------------------
    //allow one to pretty print the contents of the Edge object to an
    // output stream.
    friend ostream& operator<< ( ostream& os, const Edge& e ) {
        os << "edge: f=" << e.mFrom << " t=" << e.mTo << " w=" << e.mWeight << endl;
        return os;
    }
    //-----------------------------------------------------------------------
    //do not use (used for priority queue sorting):
    Edge ( void ) { }
    //-----------------------------------------------------------------------
    //do not use (used for priority queue sorting):
    bool operator() ( const Edge* e1, const Edge* e2 ) {
        return e2->mWeight < e1->mWeight;
    }

};
