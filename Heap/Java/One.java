class Solution {
    public void heapSort(int arr[]) {
        int n = arr.length;
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }
        for (int i = n - 1; i >= 0; i--) {
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
            heapify(arr, i, 0);
        }
    }

    private void heapify(int arr[], int n, int i) {
        int parent = i, left = 2 * i + 1, right = 2 * i + 2;
        if (left < n && arr[parent] < arr[left]) {
            parent = left;
        }
        if (right < n && arr[parent] < arr[right]) {
            parent = right;
        }
        if (parent != i) {
            int temp = arr[parent];
            arr[parent] = arr[i];
            arr[i] = temp;
            heapify(arr, n, parent);
        }
    }
}

public class One {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int arr[] = { 4, 1, 3, 9, 7 };
        sol.heapSort(arr);
        arr = new int[] { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
        sol.heapSort(arr);
        arr = new int[] { 2, 1, 5 };
        sol.heapSort(arr);
    }
}
