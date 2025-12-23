import java.util.*;

class Node {
    public int val;
    public List<Node> neighbors;

    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }

    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }

    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}

class Solution {
    private Node clone(Node root, HashMap<Node, Node> track) {
        if (root == null) {
            return null;
        }
        if (track.containsKey(root) == true) {
            return track.get(root);
        }
        Node copy = new Node(root.val);
        track.put(root, copy);
        for (Node neighbour : root.neighbors) {
            copy.neighbors.add(clone(neighbour, track));
        }
        return copy;
    }

    public Node cloneGraph(Node node) {
        return clone(node, new HashMap<>());
    }
}

public class Nine {
    public static void main(String[] args) {

    }
}
