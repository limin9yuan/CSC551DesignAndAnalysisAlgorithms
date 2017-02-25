package Practice;

/**
 * Created by Mingyuan Li on 2016/2/10.
 * Package name: Practice.
 * Project name: Chapter2.
 */
public class MergeSort
{
    private int[] array;
    private int[] tempArray;

    public static void main(String a[]){

        int[] inputArr = {45,23,11,89,77,98,4,28,65,43};
        MergeSort mms = new MergeSort();
        mms.mergeSort(inputArr);
        for(int i:inputArr){
            System.out.print(i);
            System.out.print(" ");
        }
    }

    public void mergeSort(int[] a)
    {
        array = a;
        tempArray = new int[a.length];
        doSort(0, a.length - 1);
    }
    private void doSort(int lowerIndex, int higherIndex)
    {
        if (lowerIndex < higherIndex)
        {
            int middleIndex = (lowerIndex + higherIndex) / 2;
            doSort(lowerIndex, middleIndex);
            doSort(middleIndex + 1, higherIndex);
            mergeParts(lowerIndex, middleIndex, higherIndex);
        }
    }
    private void mergeParts(int lowerIndex, int middleIndex, int higherIndex)
    {
        for (int i = lowerIndex; i <= higherIndex; i++)
            tempArray[i] = array[i];
        int i = lowerIndex;
        int j = middleIndex + 1;
        int k = lowerIndex;
        while (i <= middleIndex && j <= higherIndex)
        {
            if (tempArray[i] <= tempArray[j])
            {
                array[k] = tempArray[i];
                i++;
            }
            else
            {
                array[k] = array[j];
                j++;
            }
            k++;
        }
        while (i <= middleIndex)
        {
            array[k] = tempArray[i];
            i++;
            k++;
        }
    }
}
