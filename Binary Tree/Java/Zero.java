
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

    public ArrayList<ArrayList<Integer>> levelOrder(Node root) {
        ArrayList<ArrayList<Integer>> ans = new ArrayList<>();
        Queue<Node> q = new LinkedList<>();
        q.add(root);
        while (!q.isEmpty()) {
            ArrayList<Integer> temp = new ArrayList<>();
            for (int i = 0; i < q.size(); i++) {
                Node n = q.poll();
                temp.add(n.data);
                if (n.left != null) {
                    q.add(n.left);
                }
                if (n.right != null) {
                    q.add(n.right);
                }
            }
            ans.add(temp);
        }
        return ans;
    }
}

public class Zero {

    public static void main(String[] args) {
        Node tree = new Node(1);
        tree.left = new Node(2);
        tree.right = new Node(3);
        Solution sol = new Solution();
        System.out.println(sol.levelOrder(tree));
    }
}
