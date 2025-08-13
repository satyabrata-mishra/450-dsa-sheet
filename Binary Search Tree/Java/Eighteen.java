class Node {
    int data;
    Node left, right;

    Node(int d) {
        data = d;
        left = right = null;
    }
}

class Solution {
    private Node buildTree(Node root, int x) {
        if (root == null) {
            root = new Node(x);
            return root;
        }
        if (root.data < x)
            root.right = buildTree(root.right, x);
        else
            root.left = buildTree(root.left, x);
        return root;
    }

    public Node Bst(int pre[], int size) {
        Node root = null;
        for (int i : pre)
            root = buildTree(root, i);
        return root;

    }
}

public class Eighteen {

}
