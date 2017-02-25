#include <stdio.h>
#include <stdlib.h>
#include <iostream>


using namespace std;
extern void bruteForce_n2 (int A[], int N, int& bestStart, int& bestEnd, int& bestSum );
extern void bruteForce_n3 ( int A[], int N, int& bestStart, int& bestEnd, int& bestSum );
extern void find_maximum_subarray ( int A[], int N, int& bestStart, int& bestEnd, int& bestSum );
extern void kadane ( int A[], int N, int& bestStart, int& bestEnd, int& bestSum );

int main(int argc, char* argv[])
{
    int bestStart, bestEnd, bestSum;
    int A[] = {-1, -2};
    bruteForce_n2(A, 2, bestStart, bestEnd, bestSum);
    cout<<"For n2"<<endl;
    cout<<"BestStart is \n"<<bestStart<<endl;
    cout<<"BestEnd is \n"<<bestEnd<<endl;
    cout<<"BestSum is \n"<<bestSum<<endl;
    cout<<endl;
    bruteForce_n3(A, 2, bestStart, bestEnd, bestSum);
    cout<<"For n3"<<endl;
    cout<<"BestStart is \n"<<bestStart<<endl;
    cout<<"BestEnd is \n"<<bestEnd<<endl;
    cout<<"BestSum is \n"<<bestSum<<endl;
    cout<<endl;
    find_maximum_subarray(A, 2, bestStart, bestEnd, bestSum);
    cout<<"For find_maximum_subarray"<<endl;
    cout<<"BestStart is \n"<<bestStart<<endl;
    cout<<"BestEnd is \n"<<bestEnd<<endl;
    cout<<"BestSum is \n"<<bestSum<<endl;
    cout<<endl;
    kadane(A, 2, bestStart, bestEnd, bestSum);
    cout<<"For kadane"<<endl;
    cout<<"BestStart is \n"<<bestStart<<endl;
    cout<<"BestEnd is \n"<<bestEnd<<endl;
    cout<<"BestSum is \n"<<bestSum<<endl;
    cout<<endl;
    return 0;
}
