package Practice;

import java.util.Random;

/**
 * Created by Mingyuan Li on 2016/1/26.
 * Package name: Practice.
 * Project name: Chapter2.
 */
public class InsertionSort
{
    public static int[] insertionSort(int[] a)
    {
        for (int i = 1; i < a.length; i++)
        {
            int temp = a[i];
            int j;
            for (j = i - 1; j >= 0 && temp < a[j]; j--)
                a[j + 1] = a[j];
            a[j + 1] = temp;
        }
        return a;
    }
    public static int[] doInsertionSort(int[] a)
    {
        for (int i = 1; i < a.length; i++)
        {
            int temp = a[i];
            int j = i - 1;
            while (j >= 0 && temp < a[j])
            {
                a[j + 1] = a[j];
                j--;
            }
            a[j + 1] = temp;
        }
        return a;
    }
    public static void main(String[] args)
    {
        int[] numbers = new int[100000];
        Random nubs = new Random();
        for (int i = 0; i < 100000; i++)
        {
            numbers[i] = nubs.nextInt() % 10000;
        }
        long start = System.currentTimeMillis();
        insertionSort(numbers);
        long end = System.currentTimeMillis();
        double elapsed = end - start;
        System.out.println("Elapsed time for insertion sort is " + elapsed);
    }
}
