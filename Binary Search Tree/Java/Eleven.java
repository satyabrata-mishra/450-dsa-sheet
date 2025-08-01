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
    void length(Node root, int len[]) {
        if (root == null)
            return;
        ++len[0];
        length(root.left, len);
        length(root.right, len);
    }

    void helper(Node root, int k[], int ans[]) {
        if (root == null)
            return;
        helper(root.left, k, ans);
        --k[0];
        if (k[0] == 0) {
            ans[0] = root.data;
            return;
        }
        helper(root.right, k, ans);
    }

    public int kthLargest(Node root, int k) {
        int len[] = { 0 };
        int ans[] = { -1 };
        length(root, len);
        len[0] = len[0] - k + 1;
        helper(root, len, ans);
        return ans[0];
    }
}

public class Eleven {

}
