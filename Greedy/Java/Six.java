import java.util.*;

class Solution {

    public int maxStop(int plat, int[][] trains) {

        Arrays.sort(trains, (a, b) -> {
            if (a[2] == b[2]) {
                return a[1] - b[1]; // sort by departure
            }
            return a[2] - b[2]; // sort by platform
        });

        int ans = 0;
        int lastDept = -1;
        int lastPlat = -1;

        for (int[] t : trains) {

            if (t[2] != lastPlat) {
                ans++;
                lastPlat = t[2];
                lastDept = t[1];
            } else if (t[0] >= lastDept) {
                ans++;
                lastDept = t[1];
            }
        }
        return ans;
    }
}

public class Six {
    public static void main(String[] args) {

        Solution sol = new Solution();

        int[][] trains = {
                { 1000, 1030, 1 },
                { 1010, 1030, 1 },
                { 1000, 1020, 2 },
                { 1030, 1230, 2 },
                { 1200, 1230, 3 },
                { 900, 1005, 1 }
        };
        int platforms = 3;
        int result = sol.maxStop(platforms, trains);
        System.out.println(result);
    }
}
