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

    static int maxSum;

    public static int findLargestSubtreeSum(Node root) {
        maxSum = Integer.MIN_VALUE;
        postorder(root);
        return maxSum;
    }

    private static int postorder(Node root) {
        if (root == null) {
            return 0;
        }

        int left = postorder(root.left);
        int right = postorder(root.right);

        int currSum = root.data + left + right;

        maxSum = Math.max(maxSum, currSum);

        return currSum;
    }
}

public class Twentyfive {
    public static void main(String[] args) {

        Node root = new Node(1);

        root.left = new Node(2);
        root.left.left = new Node(4);
        root.left.right = new Node(5);

        root.right = new Node(3);
        root.right.left = new Node(6);
        root.right.right = new Node(7);

        Solution sol = new Solution();
        System.out.println(sol.findLargestSubtreeSum(root));
    }
}
