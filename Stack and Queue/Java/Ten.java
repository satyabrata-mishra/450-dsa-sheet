import java.util.Stack;

class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> stack = new Stack<>();
        for (String c : tokens) {
            if (c.equals("+")) {
                stack.push(stack.pop() + stack.pop());
            } else if (c.equals("-")) {
                int second = stack.pop();
                int first = stack.pop();
                stack.push(first - second);
            } else if (c.equals("*")) {
                stack.push(stack.pop() * stack.pop());
            } else if (c.equals("/")) {
                int second = stack.pop();
                int first = stack.pop();
                stack.push(first / second);
            } else {
                stack.push(Integer.parseInt(c));
            }
        }
        return stack.peek();
    }
}

public class Ten {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.evalRPN(new String[] { "2", "1", "+", "3", "*" }));
        System.out.println(sol.evalRPN(new String[] { "4", "13", "5", "/", "+" }));
        System.out.println(
                sol.evalRPN(new String[] { "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+" }));
    }
}
