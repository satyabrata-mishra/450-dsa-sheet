import java.util.*;

class Solution {
    public long maxSum(Long[] a) {
        Arrays.sort(a);
        int n = a.length;
        long[] permutation = new long[n];
        int i = 0, left = 0, right = n - 1;
        while (left < right) {
            permutation[i] = a[left];
            permutation[i + 1] = a[right];
            left++;
            right--;
            i += 2;
        }
        if (n % 2 != 0) {
            permutation[n - 1] = a[n / 2];
        }
        int ans = 0;
        for (int j = 0; j < n - 1; j++) {
            ans += Math.abs(permutation[j + 1] - permutation[j]);
        }
        ans += Math.abs(permutation[n - 1] - permutation[0]);
        return ans;
    }
}

public class Eighteen {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.maxSum(new Long[] { 1L, 2L, 4L, 8L })); // 18
        System.out.println(sol.maxSum(new Long[] { 1L, 2L, 4L, 8L, 15L })); // 40
    }
}
