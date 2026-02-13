import java.util.*;

class Node {
    int data;
    Node left, right;

    Node(int data) {
        this.data = data;
        left = right = null;
    }
}

class Solution {

    private String postorder(Node root, Map<String, Integer> map, List<Node> ans) {
        if (root == null) {
            return "#";
        }

        String left = postorder(root.left, map, ans);
        String right = postorder(root.right, map, ans);

        String curr = root.data + "," + left + "," + right;

        if (map.getOrDefault(curr, 0) == 1) {
            ans.add(root);
        }

        map.put(curr, map.getOrDefault(curr, 0) + 1);

        return curr;
    }

    public List<Node> printAllDups(Node root) {
        List<Node> ans = new ArrayList<>();
        Map<String, Integer> map = new HashMap<>();
        postorder(root, map, ans);
        return ans;
    }
}

public class Thirtythree {
    public static void display(Node root) {
        if (root == null)
            return;

        System.out.print(root.data + " ");
        display(root.left);
        display(root.right);
    }

    public static void main(String[] args) {

        Node root = new Node(1);
        root.left = new Node(2);
        root.left.left = new Node(4);

        root.right = new Node(3);
        root.right.left = new Node(2);
        root.right.left.left = new Node(4);

        root.right.right = new Node(4);

        Solution sol = new Solution();
        List<Node> ans = sol.printAllDups(root);

        for (Node node : ans) {
            display(node);
            System.out.println();
        }
    }
}
