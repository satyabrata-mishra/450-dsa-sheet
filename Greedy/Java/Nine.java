import java.util.*;

class Solution {
    public List<Integer> minMaxCandy(int[] prices, int k) {
        Arrays.sort(prices);

        int minCost = 0, maxCost = 0;
        int n = prices.length;

        int left = 0, right = n - 1;

        // Minimum cost
        while (left <= right) {
            minCost += prices[left];
            left++;
            right -= k;
        }

        // Reset pointers
        left = 0;
        right = n - 1;

        // Maximum cost
        while (left <= right) {
            maxCost += prices[right];
            right--;
            left += k;
        }

        return Arrays.asList(minCost, maxCost);
    }
}

public class Nine {
    public static void main(String[] args) {
        Solution sol = new Solution();

        List<Integer> ans = sol.minMaxCandy(new int[] { 3, 2, 1, 4 }, 2);
        for (int i : ans) {
            System.out.print(i + " ");
        }
        System.out.println();

        ans = sol.minMaxCandy(new int[] { 3, 2, 1, 4, 5 }, 4);
        for (int i : ans) {
            System.out.print(i + " ");
        }
        System.out.println();
    }
}
