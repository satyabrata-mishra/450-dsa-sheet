
import java.util.ArrayList;
import java.util.Arrays;

class Solution {

    public int[][] merge(int[][] intervals) {
        ArrayList<int[]> list = new ArrayList<>();
        Arrays.sort(intervals, (a, b) -> a[0] - b[0]);
        int start = intervals[0][0], finish = intervals[0][1], n = intervals.length;
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] <= finish) {
                finish = Math.max(finish, intervals[i][1]);
            } else {
                list.add(new int[]{start, finish});
                start = intervals[i][0];
                finish = intervals[i][1];
            }
        }
        list.add(new int[]{start, finish});
        int ans[][] = new int[list.size()][2];
        for (int i = 0; i < list.size(); i++) {
            ans[i] = list.get(i);
        }
        return ans;
    }
}

public class Thirteen {

    public static void main(String[] args) {
        int arr[][] = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
        Solution sol = new Solution();
        arr = sol.merge(arr);
        for (int i[] : arr) {
            for (int j : i) {
                System.out.print(j + " ");
            }
            System.out.println();
        }
    }
}
