// MergeSort.cpp : Defines the entry point for the console application.
//

void mergeParts(int lowerIndex, int middleIndex, int higherIndex, int a[])
{
	int *temp = new int[higherIndex - lowerIndex + 1];
	int i = lowerIndex;
	int j = middleIndex + 1;
	int k = 0;

	while (i <= middleIndex && j <= higherIndex)
	{
		if (a[i] <= a[j])
		{
			temp[k] = a[i];
			i++;
		}
		else
		{
			temp[k] = a[j];
			j++;
		}
		k++;
	}
	while (i <= middleIndex)
	{
		temp[k] = a[i];
		i++;
		k++;
	}
	while (j <= higherIndex)
	{
		temp[k] = a[j];
		j++;
		k++;
	}
	for (int i = lowerIndex; i <= higherIndex; i++)
	{
		a[i] = temp[i - lowerIndex];
	}

	delete[] temp;
}

void doSort(int lowerIndex, int higherIndex, int a[])
{
	if (lowerIndex < higherIndex)
	{
		int middleIndex = (lowerIndex + higherIndex) / 2;
		doSort(lowerIndex, middleIndex, a);
		doSort(middleIndex + 1, higherIndex, a);
		mergeParts(lowerIndex, middleIndex, higherIndex, a);
	}
}


void mergeSort(int a[], int n)
{
	doSort(0, n - 1, a);
}


