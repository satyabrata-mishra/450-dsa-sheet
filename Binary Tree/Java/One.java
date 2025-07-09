
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

class Tree {

    public ArrayList<Integer> reverseLevelOrder(Node root) {
        ArrayList<ArrayList<Integer>> list = new ArrayList<>();
        Queue<Node> q = new LinkedList<>();
        q.add(root);
        while (!q.isEmpty()) {
            int size = q.size();
            ArrayList<Integer> temp = new ArrayList<>();
            for (int i = 0; i < size; i++) {
                Node n = q.poll();
                temp.add(n.data);
                if (n.left != null) {
                    q.add(n.left);
                }
                if (n.right != null) {
                    q.add(n.right);
                }
            }
            list.add(temp);
        }
        ArrayList<Integer> ans = new ArrayList<>();
        for (int i = list.size() - 1; i >= 0; i--) {
            for (int j : list.get(i)) {
                ans.add(j);
            }
        }
        return ans;
    }
}

public class One {

    public static void main(String[] args) {
        Node tree = new Node(1);
        tree.left = new Node(2);
        tree.right = new Node(3);
        Tree t = new Tree();
        System.out.println(t.reverseLevelOrder(tree));
    }
}
