import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {
    }

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    void inorderRecursive(TreeNode root, List<Integer> ans) {
        if (root == null)
            return;
        inorderRecursive(root.left, ans);
        ans.add(root.val);
        inorderRecursive(root.right, ans);
    }

    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> ans = new ArrayList<>();
        if (root == null)
            return ans;
        Stack<TreeNode> stack = new Stack<>();
        TreeNode curr = root;
        while (!stack.empty() || curr != null) {
            if (curr != null) {
                stack.push(curr);
                curr = curr.left;
            } else {
                curr = stack.pop();
                ans.add(curr.val);
                curr = curr.right;
            }
        }
        return ans;
    }
}

public class Five {
    public static void main(String[] args) {

    }
}
