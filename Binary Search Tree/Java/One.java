
class Node {

    int data;
    Node left, right;

    Node(int item) {
        data = item;
        left = right = null;
    }
}

class BST {

    boolean search(Node root, int x) {
        if (root == null) {
            return false;
        }
        if (root.data == x) {
            return true;
        }
        if (root.data > x) {
            return search(root.left, x);
        }
        return search(root.right, x);
    }
}

public class One {

    public static void main(String[] args) {
        BST sol = new BST();
        System.out.println(sol.search(new Node(0), 0));
    }
}
