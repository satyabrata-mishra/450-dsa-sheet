import java.util.Arrays;

class Solution {
    public static long maximizeSum(long a[], int n, int k) {
        Arrays.sort(a);
        for (int i = 0; i < n && k > 0; i++) {
            if (a[i] < 0) {
                a[i] *= -1;
                --k;
            }
        }
        long sum = 0, min = Long.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            sum += a[i];
            min = Math.min(min, a[i]);
        }
        if (k % 2 == 1) {
            sum -= 2 * min;
        }
        return sum;
    }
}

public class Fiveteen {
    public static void main(String[] args) {
        System.out.println(Solution.maximizeSum(new long[] { 1, 2, -3, 4, 5 }, 5, 1)); // 15
        System.out.println(Solution.maximizeSum(new long[] { 5, -2, 5, -4, 5, -12, 5, 5, 5, 20 }, 10, 5)); // 68
    }
}
