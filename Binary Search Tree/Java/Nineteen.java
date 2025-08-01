class Solution {
    public boolean isDeadEnd(Node root) {
        return solve(root, 1, Integer.MAX_VALUE);
    }

    public boolean solve(Node root, int min, int max) {
        if (root == null)
            return false;
        if (min == max)
            return true;
        boolean left = solve(root.left, min, root.data - 1);
        boolean right = solve(root.right, root.data + 1, max);
        return left || right;
    }
}

public class Nineteen {
    public static void main(String[] args) {

    }
}
