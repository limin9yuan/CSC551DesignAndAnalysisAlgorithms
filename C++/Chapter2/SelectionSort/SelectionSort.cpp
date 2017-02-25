// SelectionSort.cpp : Defines the entry point for the console application.
//

#define _CRT_SECURE_NO_WARNINGS
//#include "stdafx.h"
#include "stdio.h"

int main()
{
	int totalElements, i, j, temp, a[100];
	printf("Enter total elements.");
	scanf("%d", &totalElements);
	for (i = 0; i < totalElements; i++)
	{
		printf("Enter %d elements: ", i + 1);
		scanf("%d", &a[i]);
	}
	for (i = 0; i < totalElements; i++)
	{
		for (j = i + 1; j < totalElements; j++)
		{
			if (a[j] < a[i])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	printf("Output\n");
	for (i = 0; i < totalElements; i++)
		printf("%d ", a[i]);
    return 0;
}

