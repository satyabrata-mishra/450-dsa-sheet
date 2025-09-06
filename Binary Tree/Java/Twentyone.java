class Node {
    int data;
    Node left, right;

    Node(int item) {
        data = item;
        left = right = null;
    }
}

class Solution {
    boolean ans = true;

    int helper(Node root) {
        if (root == null)
            return 0;
        if (root.left == null && root.right == null)
            return root.data;
        int left = helper(root.left);
        int right = helper(root.right);
        if (root.data != left + right)
            ans = false;
        return left = right + root.data;
    }

    boolean isSumTree(Node root) {
        ans = true;
        helper(root);
        return ans;
    }
}

public class Twentyone {

}
