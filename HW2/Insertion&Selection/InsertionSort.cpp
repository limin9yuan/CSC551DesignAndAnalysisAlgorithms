// InsertionSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


void insertionSort(int n, int a[])
{
	int i, j, temp;
	for (i = 1; i < n; i++)
	{
		temp = a[i];
		for (j = i - 1; j >= 0 && temp < a[j]; j--)
			a[j + 1] = a[j];
		a[j + 1] = temp;
	}
}
