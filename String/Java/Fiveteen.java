
import java.util.Stack;

class Solution {

    static boolean isBalanced(String s) {
        Stack<Character> stack = new Stack<>();
        for (char i : s.toCharArray()) {
            if (i == '(' || i == '{' || i == '[') {
                stack.add(i);
                continue;
            }
            if (stack.empty() || (i == ')' && stack.peek() != '(') || (i == '}' && stack.peek() != '{') || (i == ']' && stack.peek() != '[')) {
                return false;
            }
            stack.pop();
        }
        if (!stack.empty()) {
            return false;
        }
        return true;
    }
}

public class Fiveteen {

    public static void main(String[] args) {
        System.out.println(Solution.isBalanced("[{()}]"));//true
        System.out.println(Solution.isBalanced("[()()]{}"));//true
        System.out.println(Solution.isBalanced("([]"));//true
        System.out.println(Solution.isBalanced("([{]})"));//true
    }
}
