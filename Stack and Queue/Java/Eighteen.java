import java.util.Stack;

class Solution {
    public static boolean checkRedundancy(String s) {
        Stack<Character> st = new Stack<>();
        for (char i : s.toCharArray()) {
            if (i != ')') {
                st.push(i);
                continue;
            }
            int count = 0;
            while (!st.empty() && st.peek() != '(') {
                ++count;
                st.pop();
            }
            st.pop();
            if (count == 0 || count == 1)
                return true;
        }
        return false;
    }
}

public class Eighteen {
    public static void main(String[] args) {
        System.out.println(Solution.checkRedundancy("((a+b))"));
        System.out.println(Solution.checkRedundancy("(a+(b)/c)"));
        System.out.println(Solution.checkRedundancy("(a+b+(c+d))"));
    }
}
