import java.util.ArrayList;
import java.util.Collections;

class Node {
    int data;
    Node left, right;

    Node(int val) {
        data = val;
        left = right = null;
    }
};

class Solution {
    private static Node insert(Node root, int key, int succ[]) {
        if (root == null)
            return new Node(key);

        if (key < root.data) {
            succ[0] = root.data; // current node could be successor
            root.left = insert(root.left, key, succ);
        } else {
            root.right = insert(root.right, key, succ);
        }
        return root;
    }

    public static ArrayList<Integer> findLeastGreater(int n, int[] arr) {
        ArrayList<Integer> result = new ArrayList<>();
        Node root = null;
        for (int i = n - 1; i >= 0; --i) {
            int succ[] = { -1 };
            root = insert(root, arr[i], succ);
            result.add(succ[0]);
        }
        Collections.reverse(result);
        return result;
    }
}

public class Sixteen {

}
