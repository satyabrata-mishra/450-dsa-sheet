
class Node {

    int data;
    Node left, right;

    Node(int item) {
        data = item;
        left = right = null;
    }
}

class Solution {

    int height(Node node) {
        if (node == null) {
            return -1;
        }
        return Math.max(height(node.left), height(node.right)) + 1;

    }
}

public class Two {

    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.height(new Node(1)));
    }
}
