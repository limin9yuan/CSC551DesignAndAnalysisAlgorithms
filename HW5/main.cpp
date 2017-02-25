// file  : main.cpp
// author: Mingyuan Li
// desc. : this file defines and initializes (seeds) our random number generator.
//         it also contains code that exercises/tests the following functions:
//           copy, cost, fact, factRecursive, print, randomize_in_place,
//           bruteForce1,
//           bruteForce2 (required for grads/extra credit for undergrads),
//           bruteForce3 employing recursion (optional/extra credit for everyone), and
//           bruteForce4 NOT employing recursion (optional/extra credit for everyone).
#include  <iostream>
#include  <random>
#include  <time.h>

using namespace std;

#define  GRAD
//#define  EXTRA_CREDIT_RECURSIVE
//#define  EXTRA_CREDIT_NON_RECURSIVE

extern void   copy(   double A[][ 2 ], int n, double B[][ 2 ] );
extern double cost (  double A[][ 2 ], int n );
extern void   print ( double A[][ 2 ], int n );
extern void   randomize_in_place ( double A[][ 2 ], int n );
extern long   fact (          long n );
extern long   factRecursive ( long n );

extern void bruteForce1 ( double A[][ 2 ], int n, long repeats );
#ifdef  GRAD
    extern long   bruteForce2 ( double A[ 5 ][ 2 ] );
#endif
#ifdef  EXTRA_CREDIT_RECURSIVE
    extern void   bruteForce3 ( double A[][ 2 ], int n );
#endif
#ifdef  EXTRA_CREDIT_NON_RECURSIVE
    extern void   bruteForce4 ( double A[][ 2 ], int n );
#endif

extern mt19937_64  g;
const int  n = 5;
double  A[ n ][ 2 ] = {
    { 0.631980, 0.7925150 },
    { 0.489609, 0.2541210 },
    { 0.975682, 0.0843492 },
    { 0.414236, 0.6135660 },
    { 0.338385, 0.0315477 }
};
//---------------------------------------------------------------------------
int main ( int argc, char* argv[] ) {

    bruteForce1(A, 5, 1200000);
    bruteForce2(A);
    return 0;
}
