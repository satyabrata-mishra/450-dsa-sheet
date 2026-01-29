import java.util.HashMap;
import java.util.HashSet;

class Solution {
    public int findSubString(String str) {
        int n = str.length();

        // Find number of distinct characters
        HashSet<Character> distinct = new HashSet<>();
        for (char c : str.toCharArray()) {
            distinct.add(c);
        }
        int required = distinct.size();

        HashMap<Character, Integer> freq = new HashMap<>();
        int formed = 0, left = 0;
        int ans = Integer.MAX_VALUE;

        for (int right = 0; right < n; right++) {
            char c = str.charAt(right);
            freq.put(c, freq.getOrDefault(c, 0) + 1);

            if (freq.get(c) == 1) {
                formed++;
            }

            while (formed == required) {
                ans = Math.min(ans, right - left + 1);

                char leftChar = str.charAt(left);
                freq.put(leftChar, freq.get(leftChar) - 1);

                if (freq.get(leftChar) == 0) {
                    formed--;
                }
                left++;
            }
        }
        return ans == Integer.MAX_VALUE ? 0 : ans;
    }
}

public class Thirtysix {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.findSubString("aabcbcdbca")); // 4
        System.out.println(sol.findSubString("aaab")); // 2
        System.out.println(sol.findSubString("geeksforgeeks")); // 7
    }
}
