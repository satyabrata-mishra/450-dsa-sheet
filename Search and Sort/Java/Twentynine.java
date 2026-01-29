import java.util.*;

class Solution {
    public int findPages(int[] arr, int k) {
        int n = arr.length;
        if (k > n)
            return -1;

        int left = Arrays.stream(arr).max().getAsInt(); // max element
        int right = Arrays.stream(arr).sum(); // sum of array
        int ans = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int currSum = 0;
            int requiredStudent = 1;

            for (int i = 0; i < n; i++) {
                if (currSum + arr[i] > mid) {
                    requiredStudent++;
                    currSum = arr[i];
                } else {
                    currSum += arr[i];
                }
            }

            if (requiredStudent <= k) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
}

public class Twentynine {
    public static void main(String[] args) {
        Solution sol = new Solution();

        System.out.println(sol.findPages(new int[] { 12, 34, 67, 90 }, 2)); // 113
        System.out.println(sol.findPages(new int[] { 15, 17, 20 }, 5)); // -1
    }
}
