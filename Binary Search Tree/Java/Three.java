
import java.util.ArrayList;

class Node {

    int data;
    Node left, right;

    Node(int x) {
        data = x;
        left = right = null;
    }
}

class Solution {

    private void inorderTraversal(Node root, ArrayList<Integer> traversal) {
        if (root == null) {
            return;
        }
        inorderTraversal(root.left, traversal);
        traversal.add(root.data);
        inorderTraversal(root.right, traversal);
    }

    public ArrayList<Node> findPreSuc(Node root, int key) {
        ArrayList<Integer> list = new ArrayList<>();
        inorderTraversal(root, list);
        ArrayList<Node> ans = new ArrayList<>();
        int n = list.size(), pre = -1, suc = -1;
        for (int i = 0; i < n; i++) {
            if (list.get(i) == key) {
                if (i == n - 1) {
                    pre = list.get(i - 1);
                } else if (i == 0) {
                    suc = list.get(i + 1);
                } else {
                    pre = list.get(i - 1);
                    suc = list.get(i + 1);
                }
                break;
            }
        }
        ans.add(new Node(pre));
        ans.add(new Node(suc));
        return ans;
    }
}

public class Three {

    public static void main(String[] args) {
        Node tree = new Node(8);
        tree.right = new Node(9);
        tree.right.right = new Node(10);
        tree.left = new Node(1);
        tree.left.right = new Node(4);
        tree.left.right.left = new Node(3);
        Solution sol = new Solution();
        ArrayList<Node> ans = sol.findPreSuc(tree, 10);
        for (Node i : ans) {
            System.out.print(i.data + " ");
        }
    }
}
