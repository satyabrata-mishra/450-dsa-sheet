import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.List;

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

class NodeLocation {
    TreeNode root;
    int hd, vd;

    public NodeLocation(TreeNode root, int hd, int vd) {
        this.root = root;
        this.hd = hd;
        this.vd = vd;
    }

}

class Solution {
    public void traverse(TreeNode root, ArrayList<int[]> list, int hd, int vd) {
        if (root == null) {
            return;
        }
        int arr[] = { root.val, hd, vd };
        list.add(arr);
        traverse(root.left, list, hd - 1, vd + 1);
        traverse(root.right, list, hd + 1, vd + 1);
    }

    public List<List<Integer>> verticalTraversal(TreeNode root) {
        ArrayList<int[]> list = new ArrayList<>();
        traverse(root, list, 0, 0);
        Collections.sort(list, (a, b) -> {
            if (a[1] == b[1]) {
                if (a[2] == b[2]) {
                    return a[0] - b[0];
                } else {
                    return a[2] - b[2];
                }
            }
            return a[1] - b[1];
        });
        HashMap<Integer, ArrayList<Integer>> map = new LinkedHashMap<>();
        for (int[] i : list) {
            if (!map.containsKey(i[1])) {
                map.put(i[1], new ArrayList<>());
            }
            map.get(i[1]).add(i[0]);
        }
        List<List<Integer>> ans = new ArrayList<>();
        for (int i : map.keySet()) {
            ans.add(map.get(i));
        }
        return ans;
    }
}

public class VerticalTraversal {
    public static void main(String[] args) {
        TreeNode node = new TreeNode(1);
        node.left = new TreeNode(2);
        node.left.left = new TreeNode(4);
        node.left.right = new TreeNode(5);
        node.right = new TreeNode(3);
        node.right.left = new TreeNode(6);
        node.right.right = new TreeNode(7);
        Solution sol = new Solution();
        System.out.println(sol.verticalTraversal(node));
    }
}
