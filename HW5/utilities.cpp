//file  : utilities.cpp
//author: Mingyuan Li
//desc. : this file contains the following utility functions:
//            copy, cost, fact, factRecursive, print, and randomize_in_place.
#include  <assert.h>
#include  <iostream>
#include  <math.h>
#include  <random>

using namespace std;

mt19937_64  g;
//---------------------------------------------------------------------------
//this function copies the tour in B (of length n) into tour A (also of length
// n.  the caller must properly init and allocate the tours.
void copy( double A[][ 2 ], int n, double B[][ 2 ] ) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            A[i][j] = B[i][j];
        }
    }
}
//---------------------------------------------------------------------------
//this functions returns the cost of tour A (of length n).  don't forget that
// the distance from the end back to the start must be included.
double cost ( double A[][ 2 ], int n ) {
    double distance = 0;
    for (int i = 1; i < n; i++) {
        distance += sqrt(pow((A[i][0] - A[i - 1][0]),2) + pow((A[i][1] - A[i - 1][1]),2));
    }
    distance += sqrt(pow((A[4][0] - A[0][0]),2) + pow((A[4][1] - A[0][1]),2));
    return distance;
}
//---------------------------------------------------------------------------
//non-recursive version of n factorial.  n! is returned.
long fact ( long n ) {
    int temp = 1;
    if (n <= 1) {
        return 1;
    }
    else {
        for (int i = 1; i <= n; i++) {
            temp = temp * i;
        }
        return temp;
    }
}
//---------------------------------------------------------------------------
//recursive version of n factorial.  n! is returned.
long factRecursive ( long n ) {
    int temp = 1;
	if(n <= 1){
        return 1;
    }
    else {
        temp = n * factRecursive(n - 1);
	    return temp;
    }
}
//---------------------------------------------------------------------------
//pretty print (to cout) tour A of length n.
void print ( double A[][ 2 ], int n ) {
    for (int i = 0; i < n; i++) {
        cout<<i<<":("<<A[i][0]<<","<<A[i][1]<<")"<<endl;
    }
}
//---------------------------------------------------------------------------
//randomize tour A of length n in place
void randomize_in_place ( double A[][ 2 ], int n ) {
    double temp;
    int j;
    uniform_int_distribution<int> dis (0, n - 1);
    g.seed(time(NULL));
    for (int i = 0; i < n; i++) {
        j = dis(g);
        while (i == j) {
            j = dis(g);
        }
        temp = A[i][0];
        A[i][0] = A[j][0];
        A[j][0] = temp;

        temp = A[i][1];
        A[i][1] = A[j][1];
        A[j][1] = temp;
    }
}
//---------------------------------------------------------------------------
