import java.util.Arrays;

class Solution {
    public int minSubset(int[] arr) {

        // Sort in descending order
        Arrays.sort(arr);
        int n = arr.length;

        // reverse to make descending
        for (int i = 0; i < n / 2; i++) {
            int temp = arr[i];
            arr[i] = arr[n - 1 - i];
            arr[n - 1 - i] = temp;
        }

        int totalSum = 0;
        for (int x : arr) {
            totalSum += x;
        }

        int currSum = 0;

        for (int i = 0; i < n; i++) {
            currSum += arr[i];

            if (currSum > totalSum / 2) {
                return i + 1;
            }
        }
        return -1;
    }
}

public class Twentytwo {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.minSubset(new int[] { 2, 17, 7, 3 })); // 1
        System.out.println(sol.minSubset(new int[] { 20, 12, 18, 4 })); // 2
        System.out.println(sol.minSubset(new int[] { 1, 1, 1, 1, 10 })); // 1
    }
}
