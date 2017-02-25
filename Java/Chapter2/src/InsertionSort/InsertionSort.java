package InsertionSort;

/**
 * Created by Mingyuan Li on 2016/1/26.
 * Package name: InsertionSort.
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
    public static void main(String[] args)
    {
        int[] numbers = {4,3,2,1,1,2,3};
        int[] result = insertionSort(numbers);
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < result.length; i++)
            sb.append(result[i] + " ");
        System.out.println(sb);
    }
}
