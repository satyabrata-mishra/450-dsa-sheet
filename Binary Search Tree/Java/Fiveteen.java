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

    void inorder(Node root, int l, int h) {
        if (root == null)
            return;
        inorder(root.left, l, h);
        if (root.data >= l && root.data <= h)
            ++ans;
        inorder(root.right, l, h);
    }

    int getCount(Node root, int l, int h) {
        ans = 0;
        inorder(root, l, h);
        return ans;
    }
}

public class Fiveteen {
    public static void main(String[] args) {

    }
}
