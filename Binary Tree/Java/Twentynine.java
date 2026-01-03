import java.util.HashMap;

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

class Solution {
    private void preorderTraversal(Node root, int target, int sum, HashMap<Integer, Integer> mp, int[] ans) {
        if (root == null) {
            return;
        }

        sum += root.data;

        if (sum == target) {
            ans[0]++;
        }

        ans[0] += mp.getOrDefault(sum - target, 0);

        mp.put(sum, mp.getOrDefault(sum, 0) + 1);

        preorderTraversal(root.left, target, sum, mp, ans);
        preorderTraversal(root.right, target, sum, mp, ans);

        mp.put(sum, mp.get(sum) - 1);
    }

    public int countAllPaths(Node root, int k) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        int[] ans = new int[1];
        preorderTraversal(root, k, 0, mp, ans);
        return ans[0];
    }
}

public class Twentynine {
    public static void main(String[] args) {
        Node root = new Node(8);
        root.left = new Node(4);
        root.right = new Node(5);
        root.left.left = new Node(3);
        root.left.right = new Node(2);
        root.right.right = new Node(2);
        root.left.left.left = new Node(3);
        root.left.left.right = new Node(-2);
        root.left.right.right = new Node(1);

        Solution sol = new Solution();
        System.out.println(sol.countAllPaths(root, 7));
    }
}
