import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class Solution {
    List<String> ans;

    public void helper(String s, String temp, int index) {
        if (s.length() == index) {
            if (!temp.isEmpty())
                ans.add(temp);
            return;
        }
        helper(s, temp, index + 1);
        helper(s, temp + s.charAt(index), index + 1);
    }

    public List<String> AllPossibleStrings(String s) {
        ans = new ArrayList<>();
        helper(s, "", 0);
        Collections.sort(ans);
        return ans;
    }
}

public class Nine {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.AllPossibleStrings("abc"));
        System.out.println(sol.AllPossibleStrings("aa"));
    }
}
