class Solution {
    boolean isPalindrome(String s) {
        return s.equals(new StringBuilder(s).reverse().toString());
    }
}

public class One {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.isPalindrome("abba"));
        System.out.println(sol.isPalindrome("abc"));
    }
}
