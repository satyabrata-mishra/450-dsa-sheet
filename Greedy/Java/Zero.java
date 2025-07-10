
import java.util.Arrays;

class Solution {

    public int activitySelection(int[] start, int[] finish) {
        int n = start.length;
        int job[][] = new int[n][2];
        for (int i = 0; i < n; i++) {
            job[i][0] = start[i];
            job[i][1] = finish[i];
        }
        Arrays.sort(job, (a, b) -> a[1] - b[1]);
        int ans = 1, deadline = job[0][1];
        for (int i = 1; i < n; i++) {
            if (job[i][0] > deadline) {
                ++ans;
                deadline = job[i][1];
            }
        }
        return ans;
    }
}

public class Zero {

    public static void main(String[] args) {
        Solution sol = new Solution();
        int start[] = {1, 3, 0, 5, 8, 5};
        int finish[] = {2, 4, 6, 7, 9, 9};
        System.out.println(sol.activitySelection(start, finish));
    }
}
