// User function Template for Java

import java.util.Arrays;

class Solution {
    long findMinSum(int[] a, int[] b, int n) {
        Arrays.sort(a);
        Arrays.sort(b);
        long ans = 0;
        for (int i = 0; i < n; i++) {
            int temp = Math.abs(a[i] - b[i]);
            ans += temp;
        }
        return ans;
    }
}

public class Nineteen {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.findMinSum(new int[] { 4, 1, 8, 7 }, new int[] { 2, 3, 6, 5 }, 4));
    }
}
