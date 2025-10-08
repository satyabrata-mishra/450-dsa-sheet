class Node {
    int data;
    Node left, right;

    Node(int d) {
        data = d;
        left = null;
        right = null;
    }
}

class Solution {
    private int helper(Node root) {
        if (root == null) {
            return 0;
        }
        int left = helper(root.left);
        int right = helper(root.right);
        int oldValue = root.data;
        root.data = left + right;
        return left + right + oldValue;
    }

    public void toSumTree(Node root) {
        helper(root);
    }
}

public class Eighteen {
    public static void main(String[] args) {

    }
}
