class Solution {
    public int minFlips(String s) {
        int ans1 = 0, ans2 = 0, n = s.length();
        for (int i = 0; i < n; i++) {
            int ch = s.charAt(i);
            if (i % 2 == 0 && ch == '0')
                ++ans1;
            else if (i % 2 != 0 && ch == '1')
                ++ans1;
            else if (i % 2 == 0 && ch == '1')
                ++ans2;
            else if (i % 2 != 0 && ch == '0')
                ++ans2;
        }
        return Math.min(ans1, ans2);
    }
}

public class Twentyseven {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.minFlips("001"));
        System.out.println(sol.minFlips("0001010111"));
    }
}
