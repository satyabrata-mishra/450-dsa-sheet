class Solution {
    public int minJumps(int[] arr) {
        if (arr.length >= 1 && arr[0] == 0) {
            return -1;
        }
        int maxReach = arr[0], jumps = 1, steps = arr[0], n = arr.length;
        for (int i = 1; i < n; i++) {
            if (i == n - 1) {
                return jumps;
            }
            maxReach = Math.max(maxReach, i + arr[i]);
            --steps;
            if (steps == 0) {
                jumps++;
                if (i >= maxReach) {
                    return -1;
                }
                steps = maxReach - i;
            }
        }
        return -1;
    }
}

public class Nine {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.minJumps(new int[] { 1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9 }));
        System.out.println(sol.minJumps(new int[] { 1, 4, 3, 2, 6, 7 }));
        System.out.println(sol.minJumps(new int[] { 0, 10, 20 }));
    }
}
