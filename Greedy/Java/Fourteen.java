import java.util.*;

class Solution {
    public long findMaxProduct(int[] arr) {
        int n = arr.length, mod = 1000000007;
        if (n == 1) {
            return arr[0];
        }
        int product = 1, countNeg = 0, countZeros = 0, maxNeg = Integer.MIN_VALUE;
        for (int i = 0; i < n; ++i) {
            if (arr[i] == 0) {
                ++countZeros;
                continue;
            }
            if (arr[i] < 0) {
                ++countNeg;
                maxNeg = Math.max(maxNeg, arr[i]);
            }
            product = (product * arr[i]) % mod;
        }
        if (countZeros == n)
            return 0;
        if (countNeg % 2 == 1) {
            if (countNeg == 1 && countZeros + countNeg == n)
                return 0;
            product /= maxNeg;
        }
        return product % mod;
    }
}

public class Fourteen {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.findMaxProduct(new int[] { -1, 0, -2, 4, 3 })); // 24
        System.out.println(sol.findMaxProduct(new int[] { -1, 0 })); // 0
        System.out.println(sol.findMaxProduct(new int[] { 5 })); // 5
        System.out.println(sol.findMaxProduct(new int[] { -1 })); // -1
    }
}
