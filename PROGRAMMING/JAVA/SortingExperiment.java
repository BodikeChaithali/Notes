import java.util.*;

public class SortingExperiment {

    // ---------- Insertion Sort ----------
    static void insertionSort(int[] arr) {
        int n = arr.length;
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;

            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }

    // ---------- Merge Sort ----------
    static void mergeSort(int[] arr, int l, int r) {
        if (l < r) {
            int m = (l + r) / 2;
            mergeSort(arr, l, m);
            mergeSort(arr, m + 1, r);
            merge(arr, l, m, r);
        }
    }

    static void merge(int[] arr, int l, int m, int r) {
        int n1 = m - l + 1;
        int n2 = r - m;

        int[] L = new int[n1];
        int[] R = new int[n2];

        for (int i = 0; i < n1; i++) L[i] = arr[l + i];
        for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

        int i = 0, j = 0, k = l;

        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) arr[k++] = L[i++];
            else arr[k++] = R[j++];
        }

        while (i < n1) arr[k++] = L[i++];
        while (j < n2) arr[k++] = R[j++];
    }

    // ---------- Quick Sort ----------
    static void quickSort(int[] arr, int low, int high) {
        if (low < high) {
            int p = partition(arr, low, high);
            quickSort(arr, low, p - 1);
            quickSort(arr, p + 1, high);
        }
    }

    static int partition(int[] arr, int low, int high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;
                int temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
            }
        }

        int temp = arr[i + 1]; arr[i + 1] = arr[high]; arr[high] = temp;
        return i + 1;
    }

    // ---------- Utility Functions ----------
    static int[] generateRandomArray(int n) {
        Random rand = new Random();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++)
            arr[i] = rand.nextInt();
        return arr;
    }

    static long measureInsertion(int[] arr) {
        long start = System.nanoTime();
        insertionSort(arr);
        return System.nanoTime() - start;
    }

    static long measureMerge(int[] arr) {
        long start = System.nanoTime();
        mergeSort(arr, 0, arr.length - 1);
        return System.nanoTime() - start;
    }

    static long measureQuick(int[] arr) {
        long start = System.nanoTime();
        quickSort(arr, 0, arr.length - 1);
        return System.nanoTime() - start;
    }

    // ---------- Main Experiment ----------
    public static void main(String[] args) {

        int[] sizes = {10, 100, 1000, 10000, 100000, 1000000};

        System.out.println("n\tInsertion\tMerge\t\tQuick");

        for (int n : sizes) {

            long insTotal = 0, mergeTotal = 0, quickTotal = 0;

            for (int i = 0; i < 3; i++) {

                int[] a1 = generateRandomArray(n);
                int[] a2 = a1.clone();
                int[] a3 = a1.clone();

                insTotal += measureInsertion(a1);
                mergeTotal += measureMerge(a2);
                quickTotal += measureQuick(a3);
            }

            double insAvg = insTotal / 3e9;
            double mergeAvg = mergeTotal / 3e9;
            double quickAvg = quickTotal / 3e9;

            System.out.printf("%d\t%.6f\t%.6f\t%.6f\n",
                    n, insAvg, mergeAvg, quickAvg);
        }
    }
}
