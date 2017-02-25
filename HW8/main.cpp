//
//file  :  main.cpp
//author:  george j. grevera, ph.d.
//desc. :  test MST - Prim's algorithm.
//Copyright (c) George J. Grevera, 2016.  All rights reserved.
//
#include  "Prim.h"

int main ( int argc, char* argv[] ) {
    Prim  prim( "test4.txt" );
    //Prim  prim( "tinyEWG.txt" );
    //Prim  prim( "1000EWG.txt" );
    prim.process();
    cout << prim.getMSTCost() << endl;
    cout << prim;

    return 0;
}
