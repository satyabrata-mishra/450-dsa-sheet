import java.util.HashMap;
import java.util.Stack;

class Node {
    int data;
    Node left;
    Node right;

    Node(int data) {
        this.data = data;
        left = null;
        right = null;
    }
}

class Solution {
    private static HashMap<Integer, Integer> bracketMapping;

    private static void mapping(String str) {
        Stack<Integer> stack = new Stack<>();
        int n = str.length();
        for (int i = 0; i < n; i++) {
            if (str.charAt(i) == '(') {
                stack.push(i);
            } else if (str.charAt(i) == ')') {
                bracketMapping.put(stack.pop(), i);
            }
        }
    }

    private static Node rec(String str, int si, int ei) {
        if (si > ei)
            return null;
        int num = 0;
        while (si < str.length() && str.charAt(si) >= '0' && str.charAt(si) <= '9') {
            num = (num * 10) + (str.charAt(si) - '0');
            ++si;
        }
        --si;
        Node root = new Node(num);
        int closingBracket = -1;
        if (si + 1 <= ei && str.charAt(si + 1) == '(') {
            closingBracket = bracketMapping.get(si + 1);
        }
        if (closingBracket != -1) {
            root.left = rec(str, si + 2, closingBracket - 1);
            root.right = rec(str, closingBracket + 2, ei - 1);
        }
        return root;
    }

    public static Node treeFromString(String s) {
        bracketMapping = new HashMap<>();
        mapping(s);
        return rec(s, 0, s.length() - 1);
    }
}

public class Sixteen {
    public static void main(String[] args) {

    }
}
