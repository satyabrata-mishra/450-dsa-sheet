class Solution {
    private int[] lpsCalculation(String s) {
        int n = s.length();
        int lps[] = new int[n];
        int pre = 0, suf = 1;
        while (suf < n) {
            if (s.charAt(suf) == s.charAt(pre)) {
                lps[suf] = pre + 1;
                ++pre;
                ++suf;
            } else {
                if (pre != 0) {
                    pre = lps[pre - 1];
                } else {
                    ++suf;
                }
            }
        }
        return lps;
    }

    public int minChar(String s) {
        String rev = s;
        rev = new StringBuilder(rev).reverse().toString();
        String str = s + "$" + rev;
        int lps[] = lpsCalculation(str);
        return s.size() - lps[str.length() - 1];
    }
}

public class Thirtfour {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.minChar("abc"));// 2
        System.out.println(sol.minChar("aacecaaaa"));// 2
    }
}
