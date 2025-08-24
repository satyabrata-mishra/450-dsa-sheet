import java.util.Stack;

class Solution {
    static int maxLen(String s) {
        Stack<Integer> stack = new Stack<>();
        stack.push(-1);
        int maxLen = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '(') {
                stack.push(i);
            } else {
                stack.pop();
                if (stack.empty()) {
                    stack.push(i);
                } else {
                    maxLen = Math.max(maxLen, i - stack.peek());
                }
            }
        }
        return maxLen;
    }
};

public class Seventeen {
    public static void main(String[] args) {
        System.out.println(Solution.maxLen("()(())("));
        System.out.println(Solution.maxLen("(()("));
        System.out.println(Solution.maxLen("(()())"));
    }
}
