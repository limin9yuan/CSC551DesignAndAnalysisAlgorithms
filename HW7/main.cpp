//
//file  :  main.cpp
//author:  george j. grevera, ph.d.
//desc. :  test MST.
//Copyright (c) George J. Grevera, 2016.  All rights reserved.
//

/*
example input file from: http://algs4.cs.princeton.edu/43mst/
tinyEWG.txt contains 8 vertices and 16 edges.
note:  vertices start at 0.

8
16
4 5 0.35
4 7 0.37
5 7 0.28
0 7 0.16
1 5 0.32
0 4 0.38
2 3 0.17
1 7 0.19
0 2 0.26
1 2 0.36
1 3 0.29
2 7 0.34
6 2 0.40
3 6 0.52
6 0 0.58
6 4 0.93
*/

#include  "Kruskal.h"

using namespace std;
//---------------------------------------------------------------------------
int main ( int argc, char* argv[] ) {
    //one test
    Kruskal  k1( 8 );
    k1.addEdge( 4, 5, 0.35 );
    k1.addEdge( 4, 7, 0.37 );
    k1.addEdge( 5, 7, 0.28 );
    k1.addEdge( 0, 7, 0.16 );
    k1.addEdge( 1, 5, 0.32 );
    k1.addEdge( 0, 4, 0.38 );
    k1.addEdge( 2, 3, 0.17 );
    k1.addEdge( 1, 7, 0.19 );
    k1.addEdge( 0, 2, 0.26 );
    k1.addEdge( 1, 2, 0.36 );
    k1.addEdge( 1, 3, 0.29 );
    k1.addEdge( 2, 7, 0.34 );
    k1.addEdge( 6, 2, 0.40 );
    k1.addEdge( 3, 6, 0.52 );
    k1.addEdge( 6, 0, 0.58 );
    k1.addEdge( 6, 4, 0.93 );
    k1.process();
    cout << "after: " << k1;
    cout << "cost = " << k1.getMSTCost() << endl;

    //another test
    Kruskal  k2( "tinyEWG.txt" );
    cout << "before: " << k2;
    k2.process();
    cout << "after: " << k2;
    cout << "cost = " << k2.getMSTCost() << endl;

    return 0;
}
//---------------------------------------------------------------------------
