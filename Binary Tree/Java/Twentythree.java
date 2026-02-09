import java.util.HashMap;

class Node {
    int data;
    Node left, right;

    Node(int item) {
        data = item;
        left = right = null;
    }
}

class Solution {

    private String postorderTraversal(Node root, HashMap<String, Integer> mp, int[] count) {
        if (root == null) {
            return "#";
        }

        String left = postorderTraversal(root.left, mp, count);
        String right = postorderTraversal(root.right, mp, count);

        String subtree = root.data + "," + left + "," + right;

        // Ignore leaf nodes
        if (left.equals("#") && right.equals("#")) {
            return subtree;
        }

        if (mp.getOrDefault(subtree, 0) == 1) {
            count[0]++;
        }

        mp.put(subtree, mp.getOrDefault(subtree, 0) + 1);
        return subtree;
    }

    public int dupSub(Node root) {
        HashMap<String, Integer> mp = new HashMap<>();
        int[] count = new int[1]; // acts like pass-by-reference
        postorderTraversal(root, mp, count);
        return count[0] == 0 ? 0 : 1;
    }
}

public class Twentythree {
    public static void main(String[] args) {
        Node root = new Node('1');
        root.left = new Node('2');
        root.left.left = new Node('4');
        root.left.right = new Node('5');

        root.right = new Node('3');
        root.right.right = new Node('2');
        root.right.right.left = new Node('4');
        root.right.right.right = new Node('5');

        Solution sol = new Solution();
        System.out.println(sol.dupSub(root));
    }
}
