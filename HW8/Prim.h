/*
file  :  Prim.h
author:
desc. :  this file contains the definition of the Prim class.
         an outline of this algorithm from the Cormen book follows.
         \TODOs:
             process
             getMSTCost

         MST_Prim ( G, w, r )
            1 foreach u in V
            2     u.key = +infinity
            3     u.p   = nil
            6 while !empty( Q )
            7     u = EXTRACT_MIN( Q )
            8     foreach v in G.Adj[ u ]
            9         if v in Q and w( u, v ) < v.key
           10             v.p = u
           11             v.key = w( u, v )

Copyright (c) George J. Grevera, 2016.  All rights reserved.
*/
#pragma once
/*
MST-PRIM ( G, w, r )
    1 foreach u in G.V
    2     u.key = inf
    3     u.p = null
    4 r.key = 0
    5 Q = G.V
    6 while !empty( Q )
    7     u = EXTRACT_MIN( Q )
    8     foreach v in G.Adj[ u ]
    9         if v in Q and w(u,v) < v.key
   10             v.p = u
   11             v.key = w(u,v)
*/
#include  <assert.h>
#include  <fstream>
#include  <iostream>
#include  <queue>
#include  <set>

#include  "Vertex.h"

using namespace std;

class Prim {

private:
    int             mVertexCount  = 0;        //number of nodes/vertices (0..mVertexCount-1)
    double**        mW            = nullptr;  //matrix of weights:  mW[u][v] = mW[v][u] = weight value for edge (u,v)
    double          totalCost     = 0;

    typedef         priority_queue< Vertex*, vector< Vertex* >, Vertex >  SortedVertices;
    SortedVertices  mQ;                       //vertices sorted by edge weights
    //the following are subscripted by vertex (one for each vertex):
    bool*           mIsInQ        = nullptr;  //is it in the q or not?
    double*         mBestKeyValue = nullptr;  //best assigned key value so far
    int*            mBestParent   = nullptr;  //the resulting MST (keep track of best parent)
    //-----------------------------------------------------------------------
    //perform initialization/allocation
    void init ( int vCount ) {
        mVertexCount  = vCount;
        mIsInQ        = new bool[   mVertexCount ];
        mBestKeyValue = new double[ mVertexCount ];
        mBestParent   = new int[    mVertexCount ];
        for (int i = 0; i < mVertexCount; i++) {
            mIsInQ[ i ]        = false;
            mBestKeyValue[ i ] = DBL_MAX;
            mBestParent[ i ]   = -1;
        }

        //init 2d matrix of weights
        mW = new double*[ mVertexCount ];
        for (int r = 0; r < mVertexCount; r++) {
            mW[ r ] = new double[ mVertexCount ];
        }
        for (int r = 0; r < mVertexCount; r++) {
            for (int c = 0; c < mVertexCount; c++) {
                mW[ r ][ c ] = DBL_MAX;
            }
        }
    }

public:
    //ctor which simply sets the numbers of vertices and puts each one in its
    // own set.  if you use this, you will have to add edges on your own and
    // one at a time.
    Prim ( string fname ) {
        //open the input file
        ifstream  in( fname );
        if (in.fail()) {
            cerr << "error opening file" << endl;
            return;
        }

        //read the number of vertices and edges in the file
        int  vertices, edges;
        in >> vertices >> edges;
        init( vertices );
        //load the edges and their weights
        for (int i = 0; i < edges; i++) {
            int  u, v;
            double  w;
            in >> u >> v >> w;
            mW[ u ][ v ] = mW[ v ][ u ] = w;
            //print something every once in a while when processing large
            // input files.
            if (i > 0) {
                if      (i % 1000000 == 0)    cout << "!" << flush;
                else if (i %  100000 == 0)    cout << "*" << flush;
                else if (i %   10000 == 0)    cout << "." << flush;
            }
        }

        in.close();

        //init root vertex (choice is arbitrary, so we'll choose 0)
        Vertex*  r = new Vertex( 0, 0.0, -1 );
        mQ.push( r );
        mIsInQ[ r->getI() ] = true;
        mBestKeyValue[r->getI()] = 0;

        //init the remaining vertices
        for (int i = 1; i < mVertexCount; i++) {
            Vertex*  v = new Vertex( i, DBL_MAX, -1 );
            mQ.push( v );
            mIsInQ[ v->getI() ] = true;
        }
    }
    //-----------------------------------------------------------------------
    //dtor
    ~Prim ( void ) {
        //prints are useful to determine when dtors are actually called (or not).
        cout << "Prim::~Prim " << hex << this << dec << endl;
        if (mW != nullptr) {
            for (int r = 0; r < mVertexCount; r++) {
                delete[] mW[ r ];
                mW[ r ] = nullptr;
            }
            mW = nullptr;
        }
        if (mIsInQ != nullptr) {
            delete[] mIsInQ;
            mIsInQ = nullptr;
        }
        if (mBestKeyValue != nullptr) {
            delete[] mBestKeyValue;
            mBestKeyValue = nullptr;
        }
        if (mBestParent != nullptr) {
            delete[] mBestParent;
            mBestParent = nullptr;
        }
    }

    // bool adjacent(Vertex u, Vertex v) {
    //     for (int i = 0; i < mVertexCount; i++) {
    //         if (mW[u][i] < DBL_MAX) {
    //
    //         }
    //     }
    //     return mW[u][v] != DBL_MAX;
    // }
    //-----------------------------------------------------------------------
    //(public for testing.)
    //implement the algorithm (lines 6 through 11):
    //     6 while !empty( Q )
    //     7     u = EXTRACT_MIN( Q )
    //     8     foreach v in G.Adj[ u ]
    //     9         if v in Q and w( u, v ) < v.key
    //    10             v.p = u
    //    11             v.key = w( u, v )
    void process ( void ) {
        int u;
        //double w;
        Vertex * uVertx = nullptr;
        Vertex * vVertex = nullptr;
        while (!mQ.empty()) {
            uVertx = mQ.top();
            u = uVertx->getI();
            mQ.pop();
            if (mIsInQ[u]) {
                mIsInQ[u] = false;
                for (int v = 0; v < mVertexCount; v++) {
                    if (mIsInQ[v] && mW[u][v] < mBestKeyValue[v]) {
                        mBestParent[v] = u;
                        mBestKeyValue[v] = mW[u][v];
                        vVertex = new Vertex(v, mW[u][v], u);
                        mQ.push(vVertex);
                        vVertex = nullptr;
                    }
                }
            }
        }
    }
    //-----------------------------------------------------------------------
    double getMSTCost ( void ) const {
        double  sum = 0;
        for (int i = 0; i < mVertexCount; i++) {
            sum += mBestKeyValue[i];
        }
        return sum;
    }
    //-----------------------------------------------------------------------
    //allow one to pretty print the contents of the Prim object to an output
    // stream.
    //note: unsigned long casts below should be unsigned long long when building
    // 64-bit versions.
    friend ostream& operator<< ( ostream& os, const Prim& p ) {
        os << "--------------------" << endl;
        os << "Prim:" << endl;
        os << "    MST edges: " << endl;
        for (int i = 0; i < p.mVertexCount; i++) {
            if (p.mBestParent[ i ] != -1) {
                os << "        " << "(" << i << "," << p.mBestParent[ i ] << ")  w=" << p.mBestKeyValue[ i ] << endl;
            }
        }
        os << "    MST cost: " << p.getMSTCost() << endl;
        return os;
    }

};
