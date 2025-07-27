import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;
import java.util.TreeMap;

class Node {
    int data;
    Node left;
    Node right;

    Node(int data) {
        this.data = data;
        left = null;
        right = null;
    }
}

class Pair {
    Node node;
    int hd;

    Pair(Node node, int hd) {
        this.node = node;
        this.hd = hd;
    }
}

class Solution {
    static ArrayList<Integer> bottomView(Node root) {
        Queue<Pair> q = new LinkedList<>();
        Map<Integer, ArrayList<Integer>> map = new TreeMap<>();
        q.add(new Pair(root, 0));
        while (!q.isEmpty()) {
            Pair p = q.poll();
            if (!map.containsKey(p.hd)) {
                map.put(p.hd, new ArrayList<Integer>());
            }
            map.get(p.hd).add(p.node.data);
            if (p.node.left != null) {
                q.add(new Pair(p.node.left, p.hd - 1));
            }
            if (p.node.right != null) {
                q.add(new Pair(p.node.right, p.hd + 1));
            }
        }
        ArrayList<Integer> ans = new ArrayList<>();
        for (int i : map.keySet()) {
            ans.add(map.get(i).get(map.get(i).size() - 1));
        }
        return ans;
    }
}

public class Eleven {
    public static void main(String[] args) {
        Node node = new Node(1);
        node.left = new Node(2);
        node.left.left = new Node(4);
        node.left.right = new Node(5);
        node.right = new Node(3);
        node.right.left = new Node(6);
        node.right.right = new Node(7);
        System.out.println(Solution.topView(node));
    }

}
