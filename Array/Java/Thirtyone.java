class Solution {
    public void threeWayPartition(int arr[], int a, int b) {
        int n = arr.length;
        int low = 0, mid = 0, high = n - 1;
        while (mid <= high) {
            if (arr[mid] < a) {
                int temp = arr[low];
                arr[low] = arr[mid];
                arr[mid] = temp;
                ++low;
                ++mid;
            } else if (arr[mid] > b) {
                int temp = arr[mid];
                arr[mid] = arr[high];
                arr[high] = temp;
                --high;
            } else {
                ++mid;
            }
        }
    }
}

public class Thirtyone {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int arr[] = { 1, 2, 3, 3, 4 };
        sol.threeWayPartition(arr, 1, 2);
        for (int i : arr) {
            System.out.print(i + " ");
        }
        System.out.println();
    }
}
