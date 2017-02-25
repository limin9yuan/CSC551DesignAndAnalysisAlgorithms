//file  : brutes.cpp
//author: Mingyuan Li
//desc. : this file contains the functions bruteForce1, bruteForce2 (grads only),
//        and bruteForce3 (optional, extra credit).
#include  <iostream>

using namespace std;

#define  GRAD
//#define  EXTRA_CREDIT

extern void   copy(  double A[][ 2 ], int n, double B[][ 2 ] );
extern double cost ( double A[][ 2 ], int n );
extern void   randomize_in_place ( double A[][ 2 ], int n );
extern long factRecursive ( long n );
extern void print ( double A[][ 2 ], int n );

// void permuatation(double A[5][2], int start, int size) {
//     int result = cost(A, size);
//     int temp = 0;
//     if (start == size - 1) {
//         temp = cost(A, size);
//         if (temp <= result) {
//             result = temp;
//             copy(tempArray, size, A);
//         }
//         print(A, size);
//     }
//     else {
//         for (int i = start; i < size; i++) {
//             swap(A[start][2], A[i][2] );
//             permuatation(A, start + 1, size);
//             swap(A[start][2], A[i][2]);
//         }
//     }
// }
//---------------------------------------------------------------------------
//this function finds the optimal solution by repeatedly calling
//  randomize_in_place while keeping track of the best solution.
//  repeats is the number of repeats.
//  A is the initial tour and n is its length.
//  this function returns the best solution in A.
//note:
//  to dynamically allocate 2D arrays, user the following:
//      double  (*tmp)[2] = new double[n][2];  //tmp is a ptr to pairs of doubles
void bruteForce1 ( double A[][ 2 ], int n, long repeats ) {
    double result = cost(A, n);
    double temp = 0;
    double  (*tmp)[2] = new double[5][2];
    //double  (*f)[2] = new double[5][2];
    for (int i = 0; i < repeats; i++) {
        randomize_in_place(A, n);
        copy(tmp, n, A);
        temp = cost(tmp, n);
        if (temp < result){
            result = temp;
            copy(A, n, tmp);
        }
    }
    print(A, n);
    cout<<"best cost "<<result<<endl;
}
//---------------------------------------------------------------------------
#ifdef  GRAD
//this function generates (exactly) all permutations of the tour A.
//  your solution should be hard-coded to only work for an array of length 5.
//  the optimal tour should be returned in A.  the number of permutations
//  tested should be returned.
void swap(double A[][2], int i, int j) {
    double temp;
    temp = A[i][0];
    A[i][0] = A[j][0];
    A[j][0] = temp;

    temp = A[i][1];
    A[i][1] = A[j][1];
    A[j][1] = temp;
}
long bruteForce2 ( double A[ 5 ][ 2 ] ) {
    //double temp = 0;
    double result = cost(A, 5);
    int count = 0;
    double  (*path1)[2] = new double[5][2];
    double  (*path2)[2] = new double[5][2];
    double  (*path3)[2] = new double[5][2];
    double  (*path4)[2] = new double[5][2];
    double  (*currentPath)[2] = new double[5][2];
    double  (*tmp)[2] = new double[5][2];
    copy(path1, 5, A);
    for (int i = 0; i < 5; i++) {
        swap(path1, 0, i);
        copy(path2, 5, path1);
        for (int j = 1; j < 5; j++) {
            swap(path2, 1, j);
            copy(path3, 5, path2);
            for (int k = 2; k < 5; k++) {
                swap(path3, 2, k);
                copy(path4, 5, path3);
                for (int l = 3; l < 5; l++) {
                    swap(path4, 3, l);
                    copy(currentPath, 5, path4);
                    double temp = cost(currentPath, 5);
                    if (temp < result) {
                        result = temp;
                        copy(tmp, 5, currentPath);
                    }
                    count++;
                }
            }
        }
    }
    print(tmp,5);
    cout<<"best cost "<< result<<endl;
    return count;
}
#endif
//---------------------------------------------------------------------------
#ifdef  EXTRA_CREDIT_RECURSIVE
//this recursive function generates (exactly) all permutations of the tour A.
//  your solution should work for an array of any length n.
//  the optimal tour should be returned in A.
//note:
//  to dynamically allocate 2D arrays, use the following:
//      double  (*tmp)[2] = new double[n][2];  //tmp is a ptr to pairs of doubles
void bruteForce3 ( double A[][ 2 ], int n ) {
    ...
}
#endif
//---------------------------------------------------------------------------
#ifdef  EXTRA_CREDIT_NON_RECURSIVE
//this nonrecursive function generates (exactly) all permutations of the tour A.
//  your solution should work for an array of any length n.
//  the optimal tour should be returned in A.
//note:
//  to dynamically allocate 2D arrays, use the following:
//      double  (*tmp)[2] = new double[n][2];  //tmp is a ptr to pairs of doubles
void bruteForce4 ( double A[][ 2 ], int n ) {
    ...
}
#endif
//---------------------------------------------------------------------------
