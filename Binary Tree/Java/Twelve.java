
import java.util.ArrayList;
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

class GFG {

    ArrayList<Integer> zigZagTraversal(Node root) {
        ArrayList<Integer> ans = new ArrayList<>();
        Queue<Node> q = new LinkedList<>();
        q.add(root);
        boolean toogle = true;
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
            if (toogle) {
                for (int i : tempList) {
                    ans.add(i);
                }
            } else {
                for (int i = tempList.size() - 1; i >= 0; i--) {
                    ans.add(tempList.get(i));
                }
            }
            toogle = !toogle;
        }
        return ans;
    }
}

public class Twelve {

    public static void main(String[] args) {
        Node tree = new Node(1);
        tree.left = new Node(2);
        tree.left.left = new Node(4);
        tree.left.right = new Node(5);
        tree.right = new Node(3);
        tree.right.left = new Node(6);
        tree.right.right = new Node(7);
        GFG sol = new GFG();
        System.out.println(sol.zigZagTraversal(tree));
    }
}
