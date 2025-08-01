class Solution {
    StringBuilder ans;

    String helper(String str, int ind) {
        if (ind >= str.length())
            return ans.toString();
        ans.append(str.charAt(ind));
        while (ind + 1 < str.length() && str.charAt(ind) == str.charAt(ind + 1))
            ind++;
        return helper(str, ind + 1);
    }

    public String removeConsecutiveCharacter(String s) {
        ans = new StringBuilder();
        return helper(s, 0);
    }
}

public class Thirtyseven {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.removeConsecutiveCharacter("aabb"));
        System.out.println(sol.removeConsecutiveCharacter("aabaa"));
        System.out.println(sol.removeConsecutiveCharacter("abcddcba"));
    }
}
