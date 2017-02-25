void bruteForce_n2 (int A[], int N, int& bestStart, int& bestEnd, int& bestSum )
{
    bestStart = A[0];
    bestEnd = A[0];
    bestSum = A[0];
    for (int i = 0; i < N; i++)
    {
        int tempSum = A[i];
        if (tempSum >= bestSum)
        {
            bestSum = tempSum;
            bestStart = i;
            bestEnd = i;
        }
        for (int j = i + 1; j < N; j++)
        {
            tempSum += A[j];
            if (tempSum >= bestSum)
            {
                bestSum = tempSum;
                bestEnd = j;
                bestStart = i;
            }
        }
    }
}
void bruteForce_n3 ( int A[], int N, int& bestStart, int& bestEnd, int& bestSum )
{
    bestStart = A[0];
    bestEnd = A[0];
    bestSum = A[0];
    for (int i = 0; i < N; i++) {
        for (int i = 0; i < N; i++)
        {
            int tempSum = A[i];
            if (tempSum >= bestSum)
            {
                bestSum = tempSum;
                bestStart = i;
                bestEnd = i;
            }
        }
        for (int i = 0; i < N; i++)
        {
            int tempSum2 = A[i];
            for (int j = i + 1; j < N; j++)
            {
                tempSum2 += A[j];
                if (tempSum2 >= bestSum)
                {
                    bestSum = tempSum2;
                    bestStart = i;
                    bestEnd = j;
                }
            }
        }
    }
}
