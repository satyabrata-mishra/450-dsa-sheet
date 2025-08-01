import java.util.ArrayList;

class Node {
    int data;
    Node left, right, next;

    public Node(int data) {
        this.data = data;
    }
}

class Solution {
    public void inorderTraversal(Node root, ArrayList<Node> list) {
        if (root == null) {
            return;
        }
        inorderTraversal(root.left, list);
        list.add(root);
        inorderTraversal(root.right, list);
    }

    public void populateNext(Node root) {
        ArrayList<Node> list = new ArrayList<>();
        inorderTraversal(root, list);
        int n = list.size();
        for (int i = 0; i < n - 1; i++)
            list.get(i).next = list.get(i + 1);
    }
}

public class Five {
    public static void main(String[] args) {
        Solution sol = new Solution();
        Node node = new Node(10);
        node.left = new Node(8);
        node.left.left = new Node(3);
        node.right = new Node(12);
        sol.populateNext(node);
    }
}
