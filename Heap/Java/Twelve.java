import java.util.LinkedList;
import java.util.Queue;

class Node {
    int data;
    Node left, right;

    Node(int d) {
        data = d;
        left = right = null;
    }
}

class Solution {
    public boolean isHeap(Node tree) {
        Queue<Node> q = new LinkedList<>();
        q.add(tree);
        boolean hasNullAppeared = false;
        while (!q.isEmpty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                Node curr = q.poll();
                if (curr != null && hasNullAppeared == true) {
                    return false;
                }
                if (curr == null) {
                    hasNullAppeared = true;
                    continue;
                }
                if (curr.left != null && curr.left.data > curr.data) {
                    return false;
                }
                if (curr.right != null && curr.right.data > curr.data) {
                    return false;
                }
                q.add(curr.left);
                q.add(curr.right);
            }
        }
        return true;
    }
}

public class Twelve {
    public static void main(String[] args) {

    }
}
