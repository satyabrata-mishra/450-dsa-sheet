// User function Template for Java

class Solution {
    public int[] mergeHeaps(int[] a, int[] b, int n, int m) {
        int size = n + m, index = 0;
        int c[] = new int[size];
        for (int i = 0; i < n; i++) {
            c[index++] = a[i];
        }
        for (int i = 0; i < m; i++) {
            c[index++] = b[i];
        }
        for (int i = size / 2 - 1; i >= 0; i--) {
            heapify(c, size, i);
        }
        return c;
    }

    public void heapify(int arr[], int n, int i) {
        int parent = i, left = 2 * i + 1, right = 2 * i + 2;
        if (left < n && arr[left] > arr[parent]) {
            parent = left;
        }
        if (right < n && arr[right] > arr[parent]) {
            parent = right;
        }
        if (i != parent) {
            int temp = arr[i];
            arr[i] = arr[parent];
            arr[parent] = temp;
            heapify(arr, n, parent);
        }
    }
}

public class Six {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int a[] = { 10, 5, 6, 2 };
        int b[] = { 12, 7, 9 };
        int ans[] = sol.mergeHeaps(a, b, a.length, b.length);
        for (int i : ans) {
            System.out.print(i + " ");
        }
    }
}
