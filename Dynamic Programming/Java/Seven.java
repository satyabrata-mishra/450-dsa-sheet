class Solution {
    private static boolean subsetSumToK(int n, int target, int arr[]) {
        boolean dp[][] = new boolean[n][target + 1];
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= target; j++) {
                boolean notTake = dp[i - 1][j];
                boolean take = false;
                if (arr[i] <= j) {
                    take = dp[i - 1][j - arr[i]];
                }
                dp[i][j] = take | notTake;
            }
        }
        return dp[n - 1][target];
    }

    static boolean equalPartition(int arr[]) {
        int n = arr.length, target = 0;
        for (int i : arr) {
            target += i;
        }
        if (target % 2 != 0) {
            return false;
        }
        target /= 2;
        return subsetSumToK(n, target, arr);
    }
}

public class Seven {
    public static void main(String[] args) {
        System.out.println(Solution.equalPartition(new int[] { 1, 5, 11, 5 }));// true
        System.out.println(Solution.equalPartition(new int[] { 1, 3, 5 }));// false
    }
}
