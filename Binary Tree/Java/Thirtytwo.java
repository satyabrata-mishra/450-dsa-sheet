import java.util.HashMap;

class Node {
    int data;
    Node left, right;

    Node(int data) {
        this.data = data;
        left = right = null;
    }
};

class Solution {

    private void traverse(HashMap<Node, Node> map, Node start[], int target, Node root) {
        if (root == null) {
            return;
        }
        if (root.data == target) {
            start[0] = root;
        }

        if (root.left != null) {
            map.put(root.left, root);
            traverse(map, start, target, root.left);
        }

        if (root.right != null) {
            map.put(root.right, root);
            traverse(map, start, target, root.right);
        }
    }

    public int kthAncestor(Node root, int k, int node) {
        HashMap<Node, Node> map = new HashMap<>();
        map.put(root, null);
        Node curr[] = new Node[1];
        traverse(map, curr, node, root);
        while (k-- > 0 && curr[0] != null) {
            curr[0] = map.get(curr[0]);
        }
        return (curr[0] != null) ? curr[0].data : -1;
    }
}

public class Thirtytwo {
    public static void main(String[] args) {
        Solution sol = new Solution();
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);
        System.out.println(sol.kthAncestor(root, 2, 4));
    }
}
