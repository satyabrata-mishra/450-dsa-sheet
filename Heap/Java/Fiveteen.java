class Solution {
    static void convertMinToMaxHeap(int n, int arr[]) {
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }
    }

    static void heapify(int arr[], int n, int i) {
        int parent = i, left = 2 * i + 1, right = 2 * i + 2;
        if (left < n && arr[parent] < arr[left]) {
            parent = left;
        }
        if (right < n && arr[parent] < arr[right]) {
            parent = right;
        }
        if (parent != i) {
            int temp = arr[i];
            arr[i] = arr[parent];
            arr[parent] = temp;
            heapify(arr, n, parent);
        }
    }
}

public class Fiveteen {
    public static void main(String[] args) {

    }
}
