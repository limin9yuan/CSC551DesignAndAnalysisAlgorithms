// MergeSortMain.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <Windows.h>

extern void mergeSort(int a[], int n);

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
	int *a = new int[10];
	clock_t start_elap = clock();
	double start_CPU = cpuTime();
	for (int i = 0; i < 10000000; i++)
	{
		srand(time(NULL));
		for (int i = 0; i < 10; i++)
		{
			a[i] = rand() % 10000;
		}
		mergeSort(a, 10);
	}
	double end_CPU = cpuTime();
	clock_t end_elap = clock();

	double CPU = ((double)end_CPU - start_CPU);
	double elapsed = ((double)end_elap - start_elap);
	cout << "Output selection sort" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << endl;
	}
	cout << "CPU for selection sort = " << CPU << endl;
	cout << "Elapsed for selection sort = " << elapsed << endl;
	cout << endl;
	cout << endl;

	cout << "Array size of 100" << endl;
	int *b = new int[100];
	start_elap = clock();
	start_CPU = cpuTime();
	for (int i = 0; i < 1000000; i++)
	{
		srand(time(NULL));
		for (int i = 0; i < 100; i++)
		{
			b[i] = rand() % 10000;
		}
		mergeSort(b, 100);
	}
	end_CPU = cpuTime();
	end_elap = clock();

	CPU = ((double)end_CPU - start_CPU);	
	elapsed = ((double)end_elap - start_elap);
	cout << "CPU for selection sort = " << CPU << endl;
	cout << "Elapsed for selection sort = " << elapsed << endl;
	cout << endl;

	cout << "Array size of 1000" << endl;
	int *c = new int[1000];
	start_elap = clock();
	start_CPU = cpuTime();
	for (int i = 0; i < 100000; i++)
	{
		srand(time(NULL));
		for (int i = 0; i < 1000; i++)
		{
			c[i] = rand() % 10000;
		}
		mergeSort(c, 1000);
	}
	end_CPU = cpuTime();
	end_elap = clock();

	CPU = ((double)end_CPU - start_CPU);
	elapsed = ((double)end_elap - start_elap);
	cout << "CPU for selection sort = " << CPU << endl;
	cout << "Elapsed for selection sort = " << elapsed << endl;
	cout << endl;


	cout << "Array size of 10000" << endl;
	int *d = new int[10000];
	start_elap = clock();
	start_CPU = cpuTime();
	for (int i = 0; i < 10000; i++)
	{
		srand(time(NULL));
		for (int i = 0; i < 10000; i++)
		{
			d[i] = rand() % 10000;
		}
		mergeSort(d, 10000);
	}
	end_CPU = cpuTime();
	end_elap = clock();

	CPU = ((double)end_CPU - start_CPU);
	elapsed = ((double)end_elap - start_elap);
	cout << "CPU for selection sort = " << CPU << endl;
	cout << "Elapsed for selection sort = " << elapsed << endl;
	cout << endl;

	cout << "Array size of 100000" << endl;
	int *e = new int[100000];
	start_elap = clock();
	start_CPU = cpuTime();
	for (int i = 0; i < 1000; i++)
	{
		srand(time(NULL));
		for (int i = 0; i < 100000; i++)
		{
			e[i] = rand() % 10000;
		}
		mergeSort(e, 100000);
	}
	end_CPU = cpuTime();
	end_elap = clock();

	CPU = ((double)end_CPU - start_CPU);
	elapsed = ((double)end_elap - start_elap);
	cout << "CPU for selection sort = " << CPU << endl;
	cout << "Elapsed for selection sort = " << elapsed << endl;
	cout << endl;

	cout << "Array size of 200000" << endl;
	int *f = new int[200000];
	start_elap = clock();
	start_CPU = cpuTime();
	for (int i = 0; i < 100; i++)
	{
		srand(time(NULL));
		for (int i = 0; i < 200000; i++)
		{
			f[i] = rand() % 100000;
		}
		mergeSort(f, 200000);
	}
	end_CPU = cpuTime();
	end_elap = clock();

	CPU = ((double)end_CPU - start_CPU);
	elapsed = ((double)end_elap - start_elap);
	cout << "CPU for selection sort = " << CPU << endl;
	cout << "Elapsed for selection sort = " << elapsed << endl;
	cout << endl;

	cout << "Array size of 300000" << endl;
	int *g = new int[300000];
	start_elap = clock();
	start_CPU = cpuTime();
	for (int i = 0; i < 100; i++)
	{
		srand(time(NULL));
		for (int i = 0; i < 300000; i++)
		{
			g[i] = rand() % 100000;
		}
		mergeSort(g, 300000);
	}
	end_CPU = cpuTime();
	end_elap = clock();

	CPU = ((double)end_CPU - start_CPU);
	elapsed = ((double)end_elap - start_elap);
	cout << "CPU for selection sort = " << CPU << endl;
	cout << "Elapsed for selection sort = " << elapsed << endl;
	cout << endl;

	cout << "Array size of 400000" << endl;
	int *h = new int[400000];
	start_elap = clock();
	start_CPU = cpuTime();
	for (int i = 0; i < 100; i++)
	{
		srand(time(NULL));
		for (int i = 0; i < 400000; i++)
		{
			h[i] = rand() % 100000;
		}
		mergeSort(h, 400000);
	}
	end_CPU = cpuTime();
	end_elap = clock();

	CPU = ((double)end_CPU - start_CPU);
	elapsed = ((double)end_elap - start_elap);
	cout << "CPU for selection sort = " << CPU << endl;
	cout << "Elapsed for selection sort = " << elapsed << endl;
	cout << endl;

	cout << "Array size of 500000" << endl;
	int *j = new int[500000];
	start_elap = clock();
	start_CPU = cpuTime();
	for (int i = 0; i < 100; i++)
	{
		srand(time(NULL));
		for (int i = 0; i < 500000; i++)
		{
			j[i] = rand() % 100000;
		}
		mergeSort(j, 500000);
	}
	end_CPU = cpuTime();
	end_elap = clock();

	CPU = ((double)end_CPU - start_CPU);
	elapsed = ((double)end_elap - start_elap);
	cout << "CPU for selection sort = " << CPU << endl;
	cout << "Elapsed for selection sort = " << elapsed << endl;
	cout << endl;

	cout << "Array size of 1000000" << endl;
	int *k = new int[1000000];
	start_elap = clock();
	start_CPU = cpuTime();
	for (int i = 0; i < 100; i++)
	{
		srand(time(NULL));
		for (int i = 0; i < 1000000; i++)
		{
			k[i] = rand() % 100000;
		}
		mergeSort(k, 1000000);
	}
	end_CPU = cpuTime();
	end_elap = clock();

	CPU = ((double)end_CPU - start_CPU);
	elapsed = ((double)end_elap - start_elap);
	cout << "CPU for selection sort = " << CPU << endl;
	cout << "Elapsed for selection sort = " << elapsed << endl;
	cout << endl;

	return 0;

}
