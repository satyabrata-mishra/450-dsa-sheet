
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

    // Function to find the minimum element in the given BST.
    int minValue(Node root) {
        if (root == null) {
            return 0;
        }
        while (root.left != null) {
            root = root.left;
        }
        return root.data;
    }
}

public class Two {

    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.minValue(new Node(0)));
    }
}
