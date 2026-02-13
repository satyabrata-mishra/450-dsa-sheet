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
    private static int postorder(Node root, int[] ans) {
        if (root == null) {
            return 0;
        }

        int left = postorder(root.left, ans);
        int right = postorder(root.right, ans);

        int currSum = root.data + left + right;

        ans[0] = Math.max(ans[0], currSum);

        return currSum;
    }

    public static int findLargestSubtreeSum(Node root) {
        int[] ans = new int[1];
        ans[0] = Integer.MIN_VALUE;

        postorder(root, ans);

        return ans[0];
    }
}

public class Twentyseven {
    public static void main(String[] args) {
        Node root = new Node(1);
        root.left = new Node(2);
        root.left.left = new Node(4);
        root.left.right = new Node(5);

        root.right = new Node(3);
        root.right.left = new Node(6);
        root.right.right = new Node(7);

        int result = Solution.findLargestSubtreeSum(root);

        System.out.println(result);
    }
}
