class Node {
    int data;
    Node left, right;

    public Node(int d) {
        data = d;
        left = right = null;
    }
}

class Solution {
    int ans;

    public void inorder(Node root, int[] k) {
        if (root == null || k[0] == 0)
            return;
        inorder(root.left, k);
        --k[0];
        if (k[0] == 0) {
            ans = root.data;
            return;
        }
        inorder(root.right, k);
    }

    public int kthSmallest(Node root, int k) {
        ans = -1;
        inorder(root, new int[] { k });
        return ans;
    }
}

public class Twelve {

}
