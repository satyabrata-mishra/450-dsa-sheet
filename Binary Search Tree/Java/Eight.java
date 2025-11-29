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
        builtTree(root.left, pq);
        root.data = pq.poll();
        builtTree(root.right, pq);
    }

    Node binaryTreeToBST(Node root) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        traversal(root, pq);
        builtTree(root, pq);
        return root;
    }
}

public class Eight {
    public static void main(String[] args) {
        Solution sol = new Solution();
        Node head = new Node(1);
        head.left = new Node(2);
        head.right = new Node(3);
        head.left.left = new Node(4);
        head = sol.binaryTreeToBST(head);
        inorderDisplay(head);
    }

    void inorderDisplay(Node head) {
        if (head == null) {
            return;
        }
        inorderDisplay(head.left);
        System.out.println(head.data + " ");
        inorderDisplay(head.right);
    }
}
