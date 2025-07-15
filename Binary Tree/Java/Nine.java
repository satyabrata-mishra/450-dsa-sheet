
import java.util.ArrayList;
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

    // Function to return list containing elements of right view of binary tree.
    ArrayList<Integer> rightView(Node root) {
        ArrayList<Integer> ans = new ArrayList<>();
        if (root == null) {
            return ans;
        }
        Queue<Node> q = new LinkedList<>();
        q.add(root);
        while (!q.isEmpty()) {
            ArrayList<Integer> tempList = new ArrayList<>();
            int n = q.size();
            for (int i = 0; i < n; i++) {
                Node tempNode = q.poll();
                tempList.add(tempNode.data);
                if (tempNode.left != null) {
                    q.add(tempNode.left);
                }
                if (tempNode.right != null) {
                    q.add(tempNode.right);
                }
            }
            ans.add(tempList.get(tempList.size() - 1));
        }
        return ans;
    }
}

public class Nine {

    public static void main(String[] args) {
        Node tree = new Node(1);
        tree.left = new Node(2);
        tree.left.left = new Node(4);
        tree.left.right = new Node(5);
        tree.right = new Node(3);
        Solution sol = new Solution();
        System.out.println(sol.rightView(tree));
    }
}
