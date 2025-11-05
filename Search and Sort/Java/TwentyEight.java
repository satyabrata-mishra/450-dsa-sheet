class Solution {
    private int findZeros(int x) {
        int count = 0;
        while (x > 0) {
            x /= 5;
            count += x;
        }
        return count;
    }

    public int findNum(int n) {
        int low = 0, high = 5 * n, ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int zeros = findZeros(mid);
            if (zeros >= n) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
}

public class TwentyEight {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.findNum(6));
        System.out.println(sol.findNum(1));
    }
}
