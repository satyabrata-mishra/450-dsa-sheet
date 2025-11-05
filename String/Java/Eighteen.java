class Solution {
    int getLPSLength(String s) {
        int n = s.length();
        int lps[] = new int[n];
        int pre = 0, suf = 1;
        while (suf < n) {
            if (s.charAt(pre) == s.charAt(suf)) {
                lps[suf++] = ++pre;
            } else {
                lps[suf] = 0;
                if (pre == 0) {
                    ++suf;
                } else {
                    pre = lps[pre - 1];
                }
            }
        }
        return lps[n - 1];
    }
}

public class Eighteen {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.getLPSLength("abab"));// 2
        System.out.println(sol.getLPSLength("aabcdaabc"));// 4
        System.out.println(sol.getLPSLength("aaaa"));// 3
        System.out.println(sol.getLPSLength("ddbbbbcddd"));// 2
    }
}
