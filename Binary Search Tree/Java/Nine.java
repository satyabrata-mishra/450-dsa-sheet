import java.util.PriorityQueue;

class Node {
    int data;
    Node left, right;

    Node(int item) {
        data = item;
        left = right = null;
    }
}

class Solution {
    void traversal(Node root, PriorityQueue<Integer> pq) {
        if (root == null)
            return;
        traversal(root.left, pq);
        pq.add(root.data);
        traversal(root.right, pq);
    }

    void builtTree(Node root, PriorityQueue<Integer> pq) {
        if (root == null)
            return;
        builtTree(root.right, pq);
        root.data = pq.poll();
        builtTree(root.left, pq);
    }

    Node binaryTreeToBST(Node root) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        traversal(root, pq);
        builtTree(root, pq);
        return root;
    }
}

public class Nine {

}
