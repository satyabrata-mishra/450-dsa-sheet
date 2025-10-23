import java.util.ArrayList;

class Node {
    int data;
    Node left, right;

    Node(int x) {
        data = x;
        left = right = null;
    }
}

class Solution {
    static void inorderTraversal(Node root,
            ArrayList<Integer> inorderArr) {
        if (root == null) {
            return;
        }
        inorderTraversal(root.left, inorderArr);
        inorderArr.add(root.data);
        inorderTraversal(root.right, inorderArr);
    }

    static void preorderFill(Node root,
            ArrayList<Integer> inorderArr, int[] index) {
        if (root == null) {
            return;
        }
        root.data = inorderArr.get(index[0]++);
        preorderFill(root.left, inorderArr, index);
        preorderFill(root.right, inorderArr, index);
    }

    static void convertBSTtoMinHeap(Node root) {
        ArrayList<Integer> inorderArr = new ArrayList<>();
        inorderTraversal(root, inorderArr);
        int[] index = { 0 };
        preorderFill(root, inorderArr, index);
    }
}

public class Fourteen {
    public static void main(String[] args) {
        Node root = new Node(4);
        root.left = new Node(2);
        root.right = new Node(6);
        root.left.left = new Node(1);
        root.left.right = new Node(3);
        root.right.left = new Node(5);
        root.right.right = new Node(7);
        Solution.convertBSTtoMinHeap(root);
    }
}
