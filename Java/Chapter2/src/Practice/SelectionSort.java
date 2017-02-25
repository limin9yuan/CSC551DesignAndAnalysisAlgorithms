package Practice;

/**
 * Created by Mingyuan Li on 2016/1/26.
 * Package name: Practice.
 * Project name: Chapter2.
 */
public class SelectionSort
{
    public static int[] selectionSort(int[] a)
    {
        for (int i = 0; i < a.length; i++)
        {
            for (int j = i + 1; j < a.length; j++)
                if (a[j] < a[i])
                {
                    int temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
        }
        return a;
    }
    public static void main(String[] args)
    {
        int[] numbers = {4,3,2,1,1,2,3};
        int[] result = selectionSort(numbers);
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < result.length; i++)
            sb.append(result[i] + " ");
        System.out.println(sb);
    }
}
