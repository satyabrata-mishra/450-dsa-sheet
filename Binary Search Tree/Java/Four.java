class Node {
    int data;
    Node left;
    Node right;

    Node(int val) {
        data = val;
        left = right = null;
    }
}

class Solution {
    boolean isBSTUtil(Node root, long minVal, long maxVal) {
        if (root == null)
            return true;
        if (root.data <= minVal || root.data >= maxVal)
            return false;
        return isBSTUtil(root.left, minVal, root.data) && isBSTUtil(root.right, root.data, maxVal);
    }

    boolean isBST(Node root) {

        return isBSTUtil(root, Long.MIN_VALUE, Long.MAX_VALUE);
    }
}

public class Four {
    public static void main(String[] args) {

    }
}