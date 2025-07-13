
import java.util.ArrayList;
import java.util.Collections;

class Knapsack {

    int val, wt;
    double profit;

    Knapsack(int val, int wt, double profit) {
        this.val = val;
        this.wt = wt;
        this.profit = profit;
    }
}

class Solution {

    double fractionalKnapsack(int[] values, int[] weights, int W) {
        ArrayList<Knapsack> list = new ArrayList<>();
        int n = values.length;
        for (int i = 0; i < n; i++) {
            list.add(new Knapsack(values[i], weights[i], (double) values[i] / weights[i]));
        }
        Collections.sort(list, (a, b) -> Double.compare(b.profit, a.profit));
        double ans = 0;
        for (Knapsack i : list) {
            if (W > i.wt) {
                W -= i.wt;
                ans += i.val;
            } else {
                ans += i.profit * W;
                break;
            }
        }
        return ans;
    }
}

public class Four {

    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.fractionalKnapsack(new int[]{60, 100, 120}, new int[]{10, 20, 30}, 50)); //240

        System.out.println(sol.fractionalKnapsack(new int[]{60, 100}, new int[]{10, 20}, 50)); //160

        System.out.println(sol.fractionalKnapsack(new int[]{10, 20, 30}, new int[]{5, 10, 15}, 100)); //60
    }
}
