import java.util.*;

class MaxSumDifference {
    static int maxSumDifference(int[] a, int n) {
        Arrays.sort(a);
        int[] permutation = new int[n];
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

public class Seventeen {
    public static void main(String[] args) {
        System.out.println(MaxSumDifference.maxSumDifference(new int[] { 1, 2, 4, 8 }, 4)); // 18
        System.out.println(MaxSumDifference.maxSumDifference(new int[] { 1, 2, 4, 8, 15 }, 5)); // 40
    }
}
