import java.util.LinkedList;
import java.util.Queue;

class Node {
    int data;
    Node left, right;

    Node(int item) {
        data = item;
        left = right = null;
    }
}

class Solution {
    boolean check(Node root) {
        Queue<Node> q = new LinkedList<>();
        q.add(root);
        boolean foundLeafNode = false;
        int leafNodeLevel = 0, level = 0;
        while (!q.isEmpty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                Node temp = q.poll();
                if (temp.left == null && temp.right == null) {
                    if (foundLeafNode && leafNodeLevel != level)
                        return false;
                    if (!foundLeafNode) {
                        foundLeafNode = true;
                        leafNodeLevel = level;
                    }
                }
                if (temp.left != null)
                    q.add(temp.left);
                if (temp.right != null)
                    q.add(temp.right);
            }
            ++level;
        }
        return true;
    }
}

public class Twentytwo {
    public static void main(String[] args) {
        Node root = new Node(10);
        root.left = new Node(20);
        root.left.left = new Node(10);
        root.left.right = new Node(15);
        root.right = new Node(30);
        // root.right.left = new Node(20);
        // root.right.right = new Node(30);
        Solution sol = new Solution();
        System.out.println(sol.check(root));
    }
}
