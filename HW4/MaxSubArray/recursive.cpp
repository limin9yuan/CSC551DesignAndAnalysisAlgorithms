#include <limits.h>

int leftSum;
int rightSum;
int sum;
//int sum1;

static void find_max_crossing_subarray(int A[], int low, int mid, int high, int& crossStart, int& crossEnd, int& crossSum)
{
    leftSum = INT_MIN;
    sum = 0;
    int i;
    for (i = mid; i >= low; i--)
    {
        sum += A[i];
        if (sum >= leftSum)
        {
            leftSum = sum;
            crossStart = i;
        }
    }
    rightSum = INT_MIN;
    sum = 0;
    for (i = mid + 1; i <= high; i++)
    {
        sum += A[i];
        if (sum >= rightSum) {
            rightSum = sum;
            crossEnd = i;
        }
    }
    crossSum = leftSum + rightSum;
}

static void find_maximum_subarray(int A[], int low, int high, int& bestStart, int& bestEnd, int& bestSum)
{
    int mid = (high + low) / 2;
    if (high == low)
    {
        bestStart = low;
        bestEnd = high;
        bestSum = A[high];
    }
    else
    {
        int leftStart, leftEnd, leftSum;
        int rightStart, rightEnd, rightSum;
        int crossStart, crossEnd, crossSum;
        find_maximum_subarray(A, low, mid, leftStart, leftEnd, leftSum);
        find_maximum_subarray(A, mid + 1, high, rightStart, rightEnd, rightSum);
        find_max_crossing_subarray(A, low, mid, high, crossStart, crossEnd, crossSum);
        if (leftSum >= rightSum && leftSum >= crossSum)
        {
            bestStart = leftStart;
            bestEnd = leftEnd;
            bestSum = leftSum;
        }
        else if (rightSum >= leftSum && rightSum >= crossSum)
        {
            bestStart = rightStart;
            bestEnd = rightEnd;
            bestSum = rightSum;
        }
        else
        {
            bestStart = crossStart;
            bestEnd = crossEnd;
            bestSum = crossSum;
        }
    }
}

void find_maximum_subarray ( int A[], int N, int& bestStart, int& bestEnd, int& bestSum )
{
    bestStart = 0;
    bestEnd = 0;
    bestSum = 0;
    find_maximum_subarray( A, 0, N - 1, bestStart, bestEnd, bestSum );
}
