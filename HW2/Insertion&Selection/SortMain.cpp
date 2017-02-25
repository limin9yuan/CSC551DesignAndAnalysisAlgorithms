// SortMain.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <Windows.h>

extern void selectionSort(int n, int a[]);
extern void insertionSort(int n, int a[]);

using namespace std;

static double cpuTime(void) {
	FILETIME  createTime, exitTime, kernelTime, userTime;

	if (GetProcessTimes(GetCurrentProcess(), &createTime, &exitTime,
		&kernelTime, &userTime) != -1) {
		SYSTEMTIME  userSystemTime;
		if (FileTimeToSystemTime(&userTime, &userSystemTime) != -1)
			return (double)userSystemTime.wHour   * 3600.0 +
			(double)userSystemTime.wMinute    *     60.0 +
			(double)userSystemTime.wSecond +
			(double)userSystemTime.wMilliseconds / 1000.0;
	}
	return -1;
}




int main(int argc, char* argv[])
{
	cout << "Array size of 10" << endl;
	int *a;
	a = (int*)malloc(10 * sizeof(int));
	int *a1;
	a1 = (int*)malloc(10 * sizeof(int));
	clock_t start_elap = clock();
	double start_CPU = cpuTime();
	for (int i = 0; i < 10000000; i++)
	{
		srand(time(NULL));
		for (int i = 0; i < 10; i++)
		{
			a[i] = rand() % 10000;
		}
		selectionSort(10, a);
	}
	double end_CPU = cpuTime();
	clock_t end_elap = clock();

	clock_t start1_elap = clock();
	double start1_CPU = cpuTime();
	for (int i = 0; i < 10000000; i++)
	{
		srand(time(NULL));
		for (int i = 0; i < 10; i++)
		{
			a1[i] = rand() % 10000;
		}
		insertionSort(10, a1);
	}
	double end1_CPU = cpuTime();
	clock_t end1_elap = clock();
	
	double CPU = ((double)end_CPU - start_CPU);
	double CPU1 = ((double)end1_CPU - start1_CPU);
	double elapsed = ((double)end_elap - start_elap);
	double elapsed1 = ((double)end1_elap - start1_elap);
	cout << "Output selection sort" << endl;
	for (int i = 0; i < 10; i++)
		cout << a[i] << endl;
	cout << "CPU for selection sort = " << CPU << endl;
	cout << "Elapsed for selection sort = " << elapsed << endl;
	cout << endl;
	cout << "Output insertion sort" << endl;
	for (int i = 0; i < 10; i++)
		cout << a1[i] << endl;
	cout << "CPU for insertion sort = " << CPU1 << endl;
	cout << "Elapsed for insertion sort =" << elapsed1 << endl;
	free(a);
	free(a1);
	cout << endl;

	cout << "Array size of 100" << endl;
	int *b;
	b = (int*)malloc(100 * sizeof(int));
	int *b1;
	b1 = (int*)malloc(100 * sizeof(int));
	start_elap = clock();
	start_CPU = cpuTime();
	for (int i = 0; i < 1000000; i++)
	{
		srand(time(NULL));
		for (int i = 0; i < 100; i++)
		{
			b[i] = rand() % 10000;
		}
		selectionSort(100, b);
	}
	end_CPU = cpuTime();
	end_elap = clock();

	start1_elap = clock();
	start1_CPU = cpuTime();
	for (int i = 0; i < 1000000; i++)
	{
		srand(time(NULL));
		for (int i = 0; i < 100; i++)
		{
			b1[i] = rand() % 10000;
		}
		insertionSort(100, b1);
    }
	end1_CPU = cpuTime();
	end1_elap = clock();
	
	CPU = ((double)end_CPU - start_CPU);
	CPU1 = ((double)end1_CPU - start1_CPU);
	elapsed = ((double)end_elap - start_elap);
	elapsed1 = ((double)end1_elap - start1_elap);
	cout << "CPU for selection sort = " << CPU << endl;
	cout << "Elapsed for selection sort = " << elapsed << endl;
	cout << "CPU for insertion sort = " << CPU1 << endl;
	cout << "Elapsed for insertion sort =" << elapsed1 << endl;
	free(b);
	free(b1);
	cout << endl;

	cout << "Array size of 1000" << endl;
	int *c;
	c = (int*)malloc(1000 * sizeof(int));
	int *c1;
	c1 = (int*)malloc(1000 * sizeof(int));
	start_elap = clock();
	start_CPU = cpuTime();
	for (int i = 0; i < 10000; i++)
	{
		srand(time(NULL));
		for (int i = 0; i < 1000; i++)
		{
			c[i] = rand() % 10000;
		}
		selectionSort(1000, c);
	}
	end_CPU = cpuTime();
	end_elap = clock();

	start1_elap = clock();
	start1_CPU = cpuTime();
	for (int i = 0; i < 100000; i++)
	{
		srand(time(NULL));
		for (int i = 0; i < 1000; i++)
		{
			c1[i] = rand() % 10000;
		}
		insertionSort(1000, c1);
	}
	end1_CPU = cpuTime();
	end1_elap = clock();
	
	CPU = ((double)end_CPU - start_CPU);
	CPU1 = ((double)end1_CPU - start1_CPU);
	elapsed = ((double)end_elap - start_elap);
	elapsed1 = ((double)end1_elap - start1_elap);
	cout << "CPU for selection sort = " << CPU << endl;
	cout << "Elapsed for selection sort = " << elapsed << endl;
	cout << "CPU for insertion sort = " << CPU1 << endl;
	cout << "Elapsed for insertion sort =" << elapsed1 << endl;
	free(c);
	free(c1);
	cout << endl;


	cout << "Array size of 10000" << endl;
	int *d;
	d = (int*)malloc(10000 * sizeof(int));
	int *d1;
	d1 = (int*)malloc(10000 * sizeof(int));
	start_elap = clock();
	start_CPU = cpuTime();
	for (int i = 0; i < 100; i++)
	{
		srand(time(NULL));
		for (int i = 0; i < 10000; i++)
		{
			d[i] = rand() % 10000;
		}
		selectionSort(10000, d);
	}
	end_CPU = cpuTime();
	end_elap = clock();

	start1_elap = clock();
	start1_CPU = cpuTime();
	for (int i = 0; i < 1000; i++)
	{
		srand(time(NULL));
		for (int i = 0; i < 10000; i++)
		{
			d1[i] = rand() % 10000;
		}
		insertionSort(10000, d1);
	}
	end1_CPU = cpuTime();
	end1_elap = clock();
	
	CPU = ((double)end_CPU - start_CPU);
	CPU1 = ((double)end1_CPU - start1_CPU);
	elapsed = ((double)end_elap - start_elap);
	elapsed1 = ((double)end1_elap - start1_elap);
	cout << "CPU for selection sort = " << CPU << endl;
	cout << "Elapsed for selection sort = " << elapsed << endl;
	cout << "CPU for insertion sort = " << CPU1 << endl;
	cout << "Elapsed for insertion sort =" << elapsed1 << endl;
	free(d);
	free(d1);
	cout << endl;

	cout << "Array size of 100000" << endl;
	int *e;
	e = (int*)malloc(100000 * sizeof(int));
	srand(time(NULL));
	for (int i = 0; i < 100000; i++)
	{
		e[i] = rand() % 10000;
	}
	int *e1;
	e1 = (int*)malloc(100000 * sizeof(int));
	start_elap = clock();
	start_CPU = cpuTime();
	selectionSort(100000, e);
	end_CPU = cpuTime();
	end_elap = clock();

	start1_elap = clock();
	start1_CPU = cpuTime();
	for (int i = 0; i < 10; i++)
	{
		srand(time(NULL));
		for (int i = 0; i < 100000; i++)
		{
			e1[i] = rand() % 10000;
		}
		insertionSort(100000, e1);
	}
	end1_CPU = cpuTime();
	end1_elap = clock();
	
	CPU = ((double)end_CPU - start_CPU);
	CPU1 = ((double)end1_CPU - start1_CPU);
	elapsed = ((double)end_elap - start_elap);
	elapsed1 = ((double)end1_elap - start1_elap);
	cout << "CPU for selection sort = " << CPU << endl;
	cout << "Elapsed for selection sort = " << elapsed << endl;
	cout << "CPU for insertion sort = " << CPU1 << endl;
	cout << "Elapsed for insertion sort =" << elapsed1 << endl;
	free(e);
	free(e1);
	cout << endl;

	cout << "Array size of 200000" << endl;
	int *f;
	f = (int*)malloc(200000 * sizeof(int));
	srand(time(NULL));
	for (int i = 0; i < 200000; i++)
	{
	f[i] = rand() % 100000;
	}
	int *f1;
	f1 = (int*)malloc(200000 * sizeof(int));
	srand(time(NULL));
	for (int i = 0; i < 200000; i++)
	{
		f1[i] = rand() % 100000;
	}
	start_elap = clock();
	start_CPU = cpuTime();
	selectionSort(200000, f);
	end_CPU = cpuTime();
	end_elap = clock();

	start1_elap = clock();
	start1_CPU = cpuTime();
	insertionSort(200000, f1);
	end1_CPU = cpuTime();
	end1_elap = clock();
	
	CPU = ((double)end_CPU - start_CPU);
	CPU1 = ((double)end1_CPU - start1_CPU);
	elapsed = ((double)end_elap - start_elap);
	elapsed1 = ((double)end1_elap - start1_elap);
	cout << "CPU for selection sort = " << CPU << endl;
	cout << "Elapsed for selection sort = " << elapsed << endl;
	cout << "CPU for insertion sort = " << CPU1 << endl;
	cout << "Elapsed for insertion sort =" << elapsed1 << endl;
	free(f);
	free(f1);
	cout << endl;

	cout << "Array size of 300000" << endl;
	int *g;
	g = (int*)malloc(300000 * sizeof(int));
	srand(time(NULL));
	for (int i = 0; i < 300000; i++)
	{
	g[i] = rand() % 100000;
	}
	int *g1;
	g1 = (int*)malloc(300000 * sizeof(int));
	srand(time(NULL));
	for (int i = 0; i < 300000; i++)
	{
		g1[i] = rand() % 100000;
	}
	start_elap = clock();
	start_CPU = cpuTime();
	selectionSort(300000, g);
	end_CPU = cpuTime();
	end_elap = clock();

	start1_elap = clock();
	start1_CPU = cpuTime();
	insertionSort(300000, g1);
	end1_CPU = cpuTime();
	end1_elap = clock();
	
	CPU = ((double)end_CPU - start_CPU);
	CPU1 = ((double)end1_CPU - start1_CPU);
	elapsed = ((double)end_elap - start_elap);
	elapsed1 = ((double)end1_elap - start1_elap);
	cout << "CPU for selection sort = " << CPU << endl;
	cout << "Elapsed for selection sort = " << elapsed << endl;
	cout << "CPU for insertion sort = " << CPU1 << endl;
	cout << "Elapsed for insertion sort =" << elapsed1 << endl;
	free(g);
	free(g1);
	cout << endl;

	cout << "Array size of 400000" << endl;
	int *h;
	h = (int*)malloc(400000 * sizeof(int));
	srand(time(NULL));
	for (int i = 0; i < 400000; i++)
	{
	h[i] = rand() % 100000;
	}
	int *h1;
	h1 = (int*)malloc(400000 * sizeof(int));
	srand(time(NULL));
	for (int i = 0; i < 400000; i++)
	{
		h1[i] = rand() % 100000;
	}
	start_elap = clock();
	start_CPU = cpuTime();
	selectionSort(400000, h);
	end_CPU = cpuTime();
	end_elap = clock();

	start1_elap = clock();
	start1_CPU = cpuTime();
	insertionSort(400000, h1);
	end1_CPU = cpuTime();
	end1_elap = clock();
	
	CPU = ((double)end_CPU - start_CPU);
	CPU1 = ((double)end1_CPU - start1_CPU);
	elapsed = ((double)end_elap - start_elap);
	elapsed1 = ((double)end1_elap - start1_elap);
	cout << "CPU for selection sort = " << CPU << endl;
	cout << "Elapsed for selection sort = " << elapsed << endl;
	cout << "CPU for insertion sort = " << CPU1 << endl;
	cout << "Elapsed for insertion sort =" << elapsed1 << endl;
	free(h);
	free(h1);
	cout << endl;

	cout << "Array size of 500000" << endl;
	int *j;
	j = (int*)malloc(500000 * sizeof(int));
	srand(time(NULL));
	for (int i = 0; i < 500000; i++)
	{
	j[i] = rand() % 100000;
	}
	int *j1;
	j1 = (int*)malloc(500000 * sizeof(int));
	srand(time(NULL));
	for (int i = 0; i < 500000; i++)
	{
		j1[i] = rand() % 100000;
	}
	start_elap = clock();
	start_CPU = cpuTime();
	selectionSort(500000, j);
	end_CPU = cpuTime();
	end_elap = clock();

	start1_elap = clock();
	start1_CPU = cpuTime();
	insertionSort(500000, j1);
	end1_CPU = cpuTime();
	end1_elap = clock();
	
	CPU = ((double)end_CPU - start_CPU);
	CPU1 = ((double)end1_CPU - start1_CPU);
	elapsed = ((double)end_elap - start_elap);
	elapsed1 = ((double)end1_elap - start1_elap);
	cout << "CPU for selection sort = " << CPU << endl;
	cout << "Elapsed for selection sort = " << elapsed << endl;
	cout << "CPU for insertion sort = " << CPU1 << endl;
	cout << "Elapsed for insertion sort =" << elapsed1 << endl;
	free(j);
	free(j1);
	cout << endl;

	cout << "Array size of 1000000" << endl;
	int *k;
	k = (int*)malloc(1000000 * sizeof(int));
	srand(time(NULL));
	for (int i = 0; i < 1000000; i++)
	{
	k[i] = rand() % 100000;
	}
	int *k1;
	k1 = (int*)malloc(1000000 * sizeof(int));
	srand(time(NULL));
	for (int i = 0; i < 1000000; i++)
	{
		k1[i] = rand() % 100000;
	}
	start_elap = clock();
	start_CPU = cpuTime();
	selectionSort(1000000, k);
	end_CPU = cpuTime();
	end_elap = clock();

	start1_elap = clock();
	start1_CPU = cpuTime();
	insertionSort(1000000, k1);
	end1_CPU = cpuTime();
	end1_elap = clock();
	
	CPU = ((double)end_CPU - start_CPU);
	CPU1 = ((double)end1_CPU - start1_CPU);
	elapsed = ((double)end_elap - start_elap);
	elapsed1 = ((double)end1_elap - start1_elap);
	cout << "CPU for selection sort = " << CPU << endl;
	cout << "Elapsed for selection sort = " << elapsed << endl;
	cout << "CPU for insertion sort = " << CPU1 << endl;
	cout << "Elapsed for insertion sort =" << elapsed1 << endl;
	free(k);
	free(k1);
	cout << endl;
	return 0;
}