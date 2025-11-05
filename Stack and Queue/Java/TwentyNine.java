class Solution {
    public int startStation(int[] gas, int[] cost) {
        int n = gas.length;
        int totalGas = 0, totalCost = 0, startPoint = 0, netGas = 0;
        for (int i = 0; i < n; i++) {
            totalGas += gas[i];
            totalCost += cost[i];
            netGas += (gas[i] - cost[i]);
            if (netGas < 0) {
                startPoint = i + 1;
                netGas = 0;
            }
        }
        if (totalCost > totalGas) {
            return -1;
        }
        return startPoint;
    }
}

public class TwentyNine {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.startStation(new int[]{4, 5, 7, 4},new int[]{6, 6, 3, 5}));
        System.out.println(sol.startStation(new int[]{3,9},new int[]{7, 6}));
    }
}
