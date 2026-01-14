class Node {
    int data;
    Node left;
    Node right;

    Node(int x) {
        data = x;
        left = right = null;
    }
};

class GfG {
    Node lca(Node root, int a, int b) {
        if (root == null)
            return null;

        if (root.data == a || root.data == b)
            return root;

        Node left = lca(root.left, a, b);
        Node right = lca(root.right, a, b);

        if (left != null && right != null)
            return root;

        return (left != null) ? left : right;
    }

    int distanceFromLCA(Node root, int target, int dist) {
        if (root == null)
            return -1;

        if (root.data == target)
            return dist;

        int left = distanceFromLCA(root.left, target, dist + 1);
        if (left != -1)
            return left;

        return distanceFromLCA(root.right, target, dist + 1);
    }

    int findDist(Node root, int a, int b) {
        Node lca = lca(root, a, b);
        int d1 = distanceFromLCA(lca, a, 0);
        int d2 = distanceFromLCA(lca, b, 0);
        return d1 + d2;
    }
}

public class Thirtyone {
    public static void main(String[] args) {
        GfG sol = new GfG();

        Node root = new Node(11);
        root.left = new Node(22);
        root.left.left = new Node(44);
        root.left.right = new Node(44); // same as your C++ code
        root.right = new Node(33);
        root.right.left = new Node(66);
        root.right.right = new Node(77);

        int ans = sol.findDist(root, 77, 22);

        System.out.print(ans + " ");
    }
}
