import java.util.Stack;

class Solution {
    public int countMinReversals(String s) {
        if (s.length() % 2 != 0) {
            return -1;
        }
        Stack<Character> st = new Stack<>();
        int ans = 0;
        for (char i : s.toCharArray()) {
            if (i == '{') {
                st.add(i);
                continue;
            }
            if (st.isEmpty()) {
                ++ans;
                st.add('{');
            } else {
                st.pop();
            }
        }
        return ans + st.size() / 2;
    }
}

public class Twenty {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.countMinReversals("}{{}}{{{"));// 3
        System.out.println(sol.countMinReversals("{{}{{{}{{}}{{"));// -1
    }
}
