
class Solution {
    static boolean isPalindrome(String s) {
        int left = 0, right = s.length() - 1;
        while (left < right) {
            if (s.charAt(left) != s.charAt(right)) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    static String longestPalindrome(String s) {
        int n = s.length(), maSize = 0;
        String ans = "";
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                String subString = s.substring(i, j);
                if (isPalindrome(subString) && subString.length() > maSize) {
                    ans = subString;
                    maSize = subString.length();
                }
            }
        }
        return ans;
    }
}

public class Seven {
    public static void main(String[] args) {
        System.out.println(Solution.longestPalindrome("forgeeksskeegfor"));
        System.out.println(Solution.longestPalindrome("abc"));
        System.out.println(Solution.longestPalindrome("jhumixbdbeaqaebvprdpyffypdrpvdbximuhj"));
    }

}
