import java.util.Stack;

class Solution {
    public int evaluate(String[] arr) {
        Stack<String> stack = new Stack<>();
        for (String i : arr) {
            boolean check = i.equals("+") || i.equals("-") || i.equals("*") || i.equals("/")
                    || i.equals("%");
            if (!check) {
                stack.push(i);
                continue;
            } else {
                int num1 = Integer.parseInt(stack.pop());
                int num2 = Integer.parseInt(stack.pop());
                if (i.equals("+"))
                    num2 += num1;
                if (i.equals("-"))
                    num2 -= num1;
                if (i.equals("*"))
                    num2 *= num1;
                if (i.equals("/"))
                    num2 /= num1;
                if (i.equals("%"))
                    num2 %= num1;
                stack.push(Integer.toString(num2));
            }
        }
        return Integer.parseInt(stack.pop());
    }
}

public class Eleven {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.evaluate(new String[] { "2", "3", "1", "*", "+", "9", "-" }));
        System.out.println(sol.evaluate(new String[] { "100", "200", "+", "2", "/", "5", "*", "7", "+" }));
    }
}
