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
    public TreeNode buildTree(TreeNode root, int x) {
        if (root == null) {
            root = new TreeNode(x);
            return root;
        }
        if (root.val < x)
            root.right = buildTree(root.right, x);
        else
            root.left = buildTree(root.left, x);
        return root;
    }

    public TreeNode bstFromPreorder(int[] preorder) {
        TreeNode node = null;
        for (int i : preorder)
            node = buildTree(node, i);
        return node;
    }
}

public class Seven {
    public static void main(String[] args) {

    }
}
