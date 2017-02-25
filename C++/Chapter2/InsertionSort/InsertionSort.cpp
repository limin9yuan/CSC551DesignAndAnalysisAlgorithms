// InsertionSort.cpp : Defines the entry point for the console application.
//

#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include "stdio.h"


int main()
{
	int totalElements, i, j, temp, a[100];
	printf("Enter total elements.");
	scanf("%d", &totalElements);
	for (int i = 0; i < totalElements; i++)
	{
		printf("Enter %d elements ", i + 1);
		scanf("%d", &a[i]);
	}
	for (i = 1; i < totalElements; i++)
	{
		temp = a[i];
		for (j = i - 1; j >= 0 && temp < a[j]; j--)
			a[j + 1] = a[j];
		a[j + 1] = temp;
	}
	printf("Output\n");
	for (i = 0; i < totalElements; i++)
		printf("%d ", a[i]);
    return 0;
}

