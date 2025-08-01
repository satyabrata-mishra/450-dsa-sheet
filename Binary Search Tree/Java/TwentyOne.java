import java.util.ArrayList;

class Solution {
    public void inorder(Node root, ArrayList<Integer> list) {
        if (root == null) {
            return;
        }
        inorder(root.left, list);
        list.add(root.data);
        inorder(root.right, list);
    }

    Node flattenBST(Node root) {
        ArrayList<Integer> list = new ArrayList<>();
        inorder(root, list);
        Node ans = new Node(list.get(0));
        Node dummy = ans;
        for (int i = 1; i < list.size(); i++) {
            dummy.right = new Node(list.get(i));
            dummy = dummy.right;
        }
        return ans;
    }
};

public class TwentyOne {

}
