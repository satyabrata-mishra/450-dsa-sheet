import java.util.ArrayList;

class Node {
    int data;
    Node left, right;

    Node() {
        this.data = 0;
        this.left = this.right = null;
    }

    Node(int data) {
        this.data = data;
        this.left = this.right = null;
    }
}

class Solution {
    private void inorderTraversal(Node root, ArrayList<Integer> list) {
        if (root == null) {
            return;
        }
        inorderTraversal(root.left, list);
        list.add(root.data);
        inorderTraversal(root.right, list);
    }

    Node bToDLL(Node root) {
        ArrayList<Integer> list = new ArrayList<>();
        inorderTraversal(root, list);
        int n = list.size();
        if (n == 0) {
            return null;
        }
        Node ans = new Node(list.get(0));
        ans.left = null;
        Node dummy = ans;
        for (int i = 1; i < n; i++) {
            dummy.right = new Node(list.get(i));
            dummy.right.left = dummy;
            dummy = dummy.right;
        }
        return ans;
    }
}

public class Seventeen {
    public static void main(String[] args) {

    }
}
