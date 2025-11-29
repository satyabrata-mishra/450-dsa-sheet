import java.util.Arrays;

class Solution {
    public String longestCommonPrefix(String[] strs) {
        StringBuilder sb = new StringBuilder();
        Arrays.sort(strs);
        int n = strs.length;
        String first = strs[0];
        String last = strs[n - 1];
        for (int i = 0; i < Math.min(first.length(), last.length()); i++) {
            if (first.charAt(i) == last.charAt(i)) {
                sb.append(first.charAt(i));
            } else {
                break;
            }
        }
        return sb.toString();
    }
}

public class Twentysix {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.longestCommonPrefix(new String[] { "flower", "flow", "flight" }));
        System.out.println(sol.longestCommonPrefix(new String[] { "dog", "racecar", "car" }));
    }
}
