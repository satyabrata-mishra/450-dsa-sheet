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
    void postorderRecursive(TreeNode root, List<Integer> ans) {
        if (root == null)
            return;
        postorderRecursive(root.left, ans);
        postorderRecursive(root.right, ans);
        ans.add(root.val);
    }

    public List<Integer> postorderTraversal(TreeNode root) {
        if (root == null)
            return new ArrayList<>();
        Stack<TreeNode> st = new Stack<>();
        st.push(root);
        Stack<Integer> data = new Stack<>();
        while (!st.empty()) {
            TreeNode node = st.pop();
            data.add(node.val);
            if (node.left != null)
                st.add(node.left);
            if (node.right != null)
                st.add(node.right);
        }
        List<Integer> ans = new ArrayList<>();
        while (!data.empty())
            ans.add(data.pop());
        return ans;
    }
}

public class Seven {
    public static void main(String[] args) {

    }
}
