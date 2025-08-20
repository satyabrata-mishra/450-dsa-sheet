class Solution {
    public int kthSmallest(int[][] mat, int k) {
        int min = Integer.MAX_VALUE, max = Integer.MIN_VALUE, rSize = mat.length, cSize = mat[0].length;
        for (int i[] : mat) {
            min = Math.min(min, i[0]);
            max = Math.max(max, i[cSize - 1]);
        }
        while (min < max) {
            int mid = min + (max - min) / 2;
            int nosLessThanMid = 0;
            for (int i[] : mat) {
                for (int j : i) {
                    if (j <= mid)
                        nosLessThanMid++;
                    else
                        break;
                }
            }
            if (nosLessThanMid <= k - 1)
                min = mid + 1;
            else
                max = mid;
        }
        return min;
    }
}

public class Eight {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.kthSmallest(new int[][] { { 16, 28, 60, 64 },
                { 22, 41, 63, 91 },
                { 27, 50, 87, 93 },
                { 36, 78, 87, 94 } }, 3));
        System.out.println(sol.kthSmallest(new int[][] { { 10, 20, 30, 40 },
                { 15, 25, 35, 45 },
                { 24, 29, 37, 48 },
                { 32, 33, 39, 50 } }, 7));
    }
}
