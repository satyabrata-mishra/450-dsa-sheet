class Solution {
    public int minimumNumberOfSwaps(String s) {
        int open = 0, close = 0, imbalance = 0, swaps = 0;

        for (char c : s.toCharArray()) {
            if (c == '[') {
                open++;

                if (imbalance > 0) {
                    swaps += imbalance;
                    imbalance--;
                }
            } else {
                close++;

                if (close > open) {
                    imbalance = close - open;
                }
            }
        }
        return swaps;
    }

}

public class Twentynine {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.minimumNumberOfSwaps("[]][][")); // 2
        System.out.println(sol.minimumNumberOfSwaps("[][]")); // 0
        System.out.println(sol.minimumNumberOfSwaps("[[[][][]]]")); // 0
    }
}
