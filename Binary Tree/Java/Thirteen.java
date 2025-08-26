class Node {
    int data;
    Node left, right;

    Node(int d) {
        data = d;
        left = right = null;
    }
}

class Solution {
    public int height(Node root, boolean valid[]) {
        if (root == null)
            return 0;
        int l = height(root.left, valid);
        int r = height(root.right, valid);
        if (Math.abs(l - r) > 1)
            valid[0] = false;
        return 1 + Math.max(l, r);
    }

    public boolean isBalanced(Node root) {
        boolean valid[] = { true };
        height(root, valid);
        return valid[0];
    }
}

public class Thirteen {

}
