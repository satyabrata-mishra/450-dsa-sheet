// User function Template for Java

import java.util.Arrays;

class Solution {
    long countTriplets(int n, int sum, long arr[]) {
        long ans = 0;
        Arrays.sort(arr);
        for (int i = 0; i < n; i++) {
            int left = i + 1, right = n - 1;
            while (left < right) {
                long targetSum = arr[i] + arr[left] + arr[right];
                if (targetSum < sum) {
                    ans += (right - left);
                    ++left;
                } else {
                    --right;
                }
            }
        }
        return ans;
    }
}

public class Tweleve {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.countTriplets(18, 36,
                new long[] { 30, 8, 23, 6, 10, 9, 31, 7, 19, 20, 1, 33, 21, 27, 28, 3, 25, 26 }));
    }
}
