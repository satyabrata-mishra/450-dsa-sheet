import java.util.Arrays;

class Solution {
    static int solve(int bt[]) {
        Arrays.sort(bt);
        int time = 0, n = bt.length, sum = 0;
        for (int i = 0; i < n; i++) {
            int temp = bt[i];
            time += bt[i];
            bt[i] = time;
            bt[i] -= temp;
            sum += bt[i];
        }
        return sum / n;
    }
}

public class Twenty {
    public static void main(String[] args) {
        System.err.println(Solution.solve(new int[] { 4, 3, 7, 1, 2 }));
        System.err.println(Solution.solve(new int[] { 1, 2, 3, 4 }));
    }
}
