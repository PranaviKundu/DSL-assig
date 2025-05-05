import java.util.*;

public class HeapSortExample {

    public static void heapify(int[] arr, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[largest] < arr[left]) {
            largest = left;
        }

        if (right < n && arr[largest] < arr[right]) {
            largest = right;
        }

        if (largest != i) {
            int temp = arr[largest];
            arr[largest] = arr[i];
            arr[i] = temp;

            heapify(arr, n, largest);
        }
    }

    public static void heapSort(int[] arr, int n) {
        int size = n;
        while (size > 0) {
            int temp = arr[size - 1];
            arr[size - 1] = arr[0];
            arr[0] = temp;

            size--;
            heapify(arr, size, 0);
        }
    }

    public static void main(String[] args) {
        int[] arr = {40, 42, 41, 49, 45};
        int n = arr.length;

        // Build max heap
        for (int i = n / 2; i >= 0; i--) {
            heapify(arr, n, i);
        }

        System.out.println("Array after heapify:");
        for (int i : arr) {
            System.out.print(i + " ");
        }
        System.out.println();

        // Heap sort
        heapSort(arr, n);
        System.out.println("Array after sort:");
        for (int i : arr) {
            System.out.print(i + " ");
        }
        System.out.println();
    }
}
