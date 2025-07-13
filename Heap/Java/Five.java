

class Solution {

    // Function to merge two sorted arrays
    private int[] mergeSort(int[] list1, int[] list2) {
        int n1 = list1.length, n2 = list2.length;
        int[] merged = new int[n1 + n2];
        int i = 0, j = 0, k = 0;

        while (i < n1 && j < n2) {
            if (list1[i] <= list2[j]) {
                merged[k++] = list1[i++];
            } else {
                merged[k++] = list2[j++];
            }
        }

        while (i < n1) {
            merged[k++] = list1[i++];
        }

        while (j < n2) {
            merged[k++] = list2[j++];
        }

        return merged;
    }

    // Function to merge K sorted arrays
    public int[] mergeKArrays(int[][] arr, int K) {
        if (K == 1) {
            return arr[0];
        }

        int[] ans = mergeSort(arr[0], arr[1]);
        for (int i = 2; i < K; i++) {
            ans = mergeSort(ans, arr[i]);
        }

        return ans;
    }
}

public class Five {

    // Helper function to display the array
    public static void display(int[] list) {
        for (int num : list) {
            System.out.print(num + " ");
        }
        System.out.println();
    }

    // Main method
    public static void main(String[] args) {
        Solution sol = new Solution();

        int[][] list1 = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };
        display(sol.mergeKArrays(list1, list1.length));

        int[][] list2 = {
            {1, 2, 3, 4},
            {2, 2, 3, 4},
            {5, 5, 6, 6},
            {7, 8, 9, 9}
        };
        display(sol.mergeKArrays(list2, list2.length));
    }
}
