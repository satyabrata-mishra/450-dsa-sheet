class Node {
    int data;

    Node next;
    Node bottom;

    Node(int x) {
        data = x;
        next = null;
        bottom = null;
    }
};

class Solution {
    Node sort(Node node1, Node node2) {
        Node dummy = new Node(0);
        Node ans = dummy;
        while (node1 != null && node2 != null) {
            if (node1.data <= node2.data) {
                dummy.bottom = new Node(node1.data);
                dummy = dummy.bottom;
                node1 = node1.bottom;
            } else {
                dummy.bottom = new Node(node2.data);
                dummy = dummy.bottom;
                node2 = node2.bottom;
            }
        }
        while (node1 != null) {
            dummy.bottom = new Node(node1.data);
            dummy = dummy.bottom;
            node1 = node1.bottom;
        }
        while (node2 != null) {
            dummy.bottom = new Node(node2.data);
            dummy = dummy.bottom;
            node2 = node2.bottom;
        }
        return ans.bottom;
    }

    Node flatten(Node root) {
        if (root == null) {
            return null;
        }
        if (root.next == null) {
            return root;
        }
        Node ans = sort(root, root.next);
        root = root.next.next;
        while (root != null) {
            ans = sort(ans, root);
            root = root.next;
        }
        return ans;
    }
}

public class TwentySeven {
    public static void main(String[] args) {

    }
}
