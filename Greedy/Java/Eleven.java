import java.util.*;

class Solution {
    public ArrayList<Integer> minMaxCandy(int[] prices, int k) {
        Arrays.sort(prices);

        int n = prices.length;
        int minCost = 0, maxCost = 0;

        int left = 0, right = n - 1;

        // Minimum cost
        while (left <= right) {
            minCost += prices[left];
            left++;
            right -= k;
        }

        left = 0;
        right = n - 1;

        // Maximum cost
        while (left <= right) {
            maxCost += prices[right];
            right--;
            left += k;
        }

        ArrayList<Integer> ans = new ArrayList<>();
        ans.add(minCost);
        ans.add(maxCost);

        return ans;
    }
}

public class Eleven {
    public static void main(String[] args) {
        System.out.println(Solution.minCost(4, 6, new int[] { 2, 1, 3, 1, 4 }, new int[] { 4, 1, 2 })); // 42
        System.out.println(Solution.minCost(4, 4, new int[] { 1, 1, 1 }, new int[] { 1, 1, 1 })); // 15
    }
}
