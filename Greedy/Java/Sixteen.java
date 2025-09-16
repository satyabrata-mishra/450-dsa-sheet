import java.util.Arrays;

class Solution {
    int maxValue(int arr[]) {
        int MOD = 1000000007;
        Arrays.sort(arr);
        long ans = 0;
        int n = arr.length;

        for (int i = 0; i < n; i++) {
            ans = (ans + (long) arr[i] * i) % MOD;
        }

        return (int) ans;
    }
}

public class Sixteen {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.err.println(sol.maxValue(new int[] { 5, 3, 2, 1, 4 }));
    }
}
