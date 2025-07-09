class Solution {
    public static int kthSmallest(int[] arr, int k) {
        int n = arr.length;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
        return arr[k - 1];
    }
}

public class Three {
    public static void main(String[] args) {
        int arr[] = { 7, 10, 4, 3, 20, 15 };
        System.out.println(Solution.kthSmallest(arr, 3));
    }
}
