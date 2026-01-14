
class Node {
    int data;
    Node left, right;

    Node(int item) {
        data = item;
        left = right = null;
    }
}

class Solution {
    Node lca(Node root, int a, int b) {
        if (root == null)
            return null;

        if (root.data == a || root.data == b)
            return root;

        Node left = lca(root.left, a, b);
        Node right = lca(root.right, a, b);

        if (left != null && right != null)
            return root;

        return (left != null) ? left : right;
    }
}

public class Thirty {
    public static void main(String[] args) {
        Solution sol = new Solution();

        Node root = new Node(11);
        root.left = new Node(22);
        root.left.left = new Node(44);
        root.left.right = new Node(44); // same as your C++ code
        root.right = new Node(33);
        root.right.left = new Node(66);
        root.right.right = new Node(77);

        Node ans = sol.lca(root, 77, 22);

        System.out.print(ans.data + " ");
    }
}
