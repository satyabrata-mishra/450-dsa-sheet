class Solution {
    public int maxProfit(int[] prices) {
        int buy = prices[0], profit = 0, n = prices.length;
        for (int i = 1; i < n; i++) {
            if (prices[i] < buy)
                buy = prices[i];
            else if (prices[i] - buy > profit)
                profit = prices[i] - buy;
        }
        return profit;
    }
}

public class Sixteen {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.maxProfit(new int[] { 7, 1, 5, 3, 6, 4 }));
        System.out.println(sol.maxProfit(new int[] { 7, 6, 4, 3, 1 }));
    }
}
