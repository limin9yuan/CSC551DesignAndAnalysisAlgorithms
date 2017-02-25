package MergeSort;

/**
 * Created by Mingyuan Li on 2016/2/9.
 * Package name: MergeSort.
 * Project name: Chapter2.
 */
public class MergeSort
{
    private int[] array;
    private int[] tempMergArr;

    public static void main(String a[]){

        int[] inputArr = {45,23,11,89,77,98,4,28,65,43};
        MergeSort mms = new MergeSort();
        mms.sort(inputArr);
        for(int i:inputArr){
            System.out.print(i);
            System.out.print(" ");
        }
    }

    public void sort(int inputArr[]) {
        this.array = inputArr;
        this.tempMergArr = new int[inputArr.length];
        doMergeSort(0, inputArr.length - 1);
    }

    private void doMergeSort(int lowerIndex, int higherIndex) {

        if (lowerIndex < higherIndex) {
            int middle = lowerIndex + (higherIndex - lowerIndex) / 2;
            // Below step sorts the left side of the array
            doMergeSort(lowerIndex, middle);
            // Below step sorts the right side of the array
            doMergeSort(middle + 1, higherIndex);
            // Now merge both sides
            mergeParts(lowerIndex, middle, higherIndex);
        }
    }

    private void mergeParts(int lowerIndex, int middle, int higherIndex) {

        /*for (int i = lowerIndex; i <= higherIndex; i++) {
            tempMergArr[i] = array[i];
        }*/
        int i = lowerIndex;
        int j = middle + 1;
        int k = 0;
        while (i <= middle && j <= higherIndex) {
            if (array[i] <= array[j]) {
                tempMergArr[k] = array[i];
                i++;
            } else {
                tempMergArr[k] = array[j];
                j++;
            }
            k++;
        }
        while (i <= middle) {
            tempMergArr[k] = array[i];
            k++;
            i++; 
        }
        while (j <= higherIndex)
        {
            tempMergArr[k] = array[j];
            k++;
            j++;
        }
        for (int t = lowerIndex; t <= higherIndex; t++)
        {
            array[t] = tempMergArr[t - lowerIndex];
        }
    }
}
