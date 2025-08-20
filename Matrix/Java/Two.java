class Solution {
    public int median(int[][] mat) {
        int minVal = Integer.MAX_VALUE, maxVal = Integer.MIN_VALUE, rSize = mat.length, cSize = mat[0].length;
        for (int[] i : mat) {
            minVal = Math.min(minVal, i[0]);
            maxVal = Math.max(maxVal, i[cSize - 1]);
        }
        int median = (rSize * cSize + 1) / 2;
        while (minVal < maxVal) {
            int mid = minVal + (maxVal - minVal) / 2;
            int nosLessThanMid = 0;
            for (int[] row : mat) {
                for (int val : row) {
                    if (val <= mid)
                        nosLessThanMid++;
                    else
                        break; // since rows are sorted, we can stop early
                }
            }
            if (nosLessThanMid < median)
                minVal = mid + 1;
            else
                maxVal = mid;
        }
        return minVal;

    }
}

public class Two {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.median(new int[][] { { 1, 3, 5 },
                { 2, 6, 9 },
                { 3, 6, 9 } }));
        System.out.println(sol.median(new int[][] { { 2, 4, 9 },
                { 3, 6, 7 },
                { 4, 7, 10 } }));
        System.out.println(sol.median(new int[][] { { 3 },
                { 4 },
                { 8 } }));
    }
}
