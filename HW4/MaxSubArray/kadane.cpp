#include <algorithm>

void kadane ( int A[], int N, int& bestStart, int& bestEnd, int& bestSum )
{
    bestStart = 0;
    bestEnd = 0;
    bestSum = A[0];
    int tempSum = A[0];
    int i;
    //int count = 0;
    int tempStart = 0;
    if (N == 1) {
        bestStart = 0;
        bestEnd = 0;
        bestSum = A[0];
    }
    else if (N != 1)
    {
        for(i = 1; i < N; i++)
        {
            tempSum += A[i];
            if (A[i] > tempSum) {
                tempSum = A[i];
                tempStart = i;
                //bestSum = tempSum;
            }
            if (bestSum < tempSum) {
                bestStart = tempStart;
                bestEnd = i;
                bestSum = tempSum;
            }
        }
    }
}
