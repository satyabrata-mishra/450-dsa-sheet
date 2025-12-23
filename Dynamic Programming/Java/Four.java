class Solution {
    public int prefixStrings(int n) {
        long dp[] = new long[n + 1];
        int mod = 1000000007;
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] += ((dp[j] % mod) * (dp[i - j - 1] % mod)) % mod;
            }
        }
        return (int) (dp[n] % mod);
    }
}

public class Four {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.prefixStrings(19));// 767263183
        System.out.println(sol.prefixStrings(20));// 564120378
        System.out.println(sol.prefixStrings(65));// 887145589
    }
}
