import java.util.ArrayList;
import java.util.List;

class Solution {
    private void backtrack(String str, int currentIndex, int noOfparts, String ip, List<String> ans) {
        if (noOfparts == 4 && currentIndex == str.length()) {
            ans.add(ip.substring(0, ip.length() - 1));
            return;
        }
        if (noOfparts >= 4 && currentIndex >= str.length()) {
            return;
        }
        for (int length = 1; length <= 3 && currentIndex + length <= str.length(); length++) {
            String segment = str.substring(currentIndex, currentIndex + length);
            if ((segment.charAt(0) == '0' && segment.length() > 1) || Integer.parseInt(segment) > 255) {
                continue;
            }
            backtrack(str, length + currentIndex, noOfparts + 1, ip + segment + '.', ans);
        }
    }

    public List<String> restoreIpAddresses(String s) {
        List<String> ans = new ArrayList<>();
        backtrack(s, 0, 0, "", ans);
        return ans;
    }
}

public class Thirtyone {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.restoreIpAddresses("25525511135"));
        System.out.println(sol.restoreIpAddresses("0000"));
        System.out.println(sol.restoreIpAddresses("101023"));
    }
}
