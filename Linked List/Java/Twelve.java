class Node {
    int data;
    Node next;

    Node(int key) {
        data = key;
        next = null;
    }
}

class Solution {
    private Node mergeSortHelper(Node root1, Node root2) {
        Node ans = new Node(0);
        Node dummy = ans;
        while (root1 != null && root2 != null) {
            if (root1.data <= root2.data) {
                dummy.next = new Node(root1.data);
                root1 = root1.next;
            } else {
                dummy.next = new Node(root2.data);
                root2 = root2.next;
            }
            dummy = dummy.next;
        }
        while (root1 != null) {
            dummy.next = new Node(root1.data);
            dummy = dummy.next;
            root1 = root1.next;
        }
        while (root2 != null) {
            dummy.next = new Node(root2.data);
            dummy = dummy.next;
            root2 = root2.next;
        }
        return ans.next;
    }

    public Node mergeSort(Node head) {
        if (head.next == null) {
            return head;
        }
        Node slow = head, fast = head;
        while (fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        Node head2 = slow.next;
        slow.next = null;
        Node left = mergeSort(head);
        Node right = mergeSort(head2);
        return mergeSortHelper(left, right);
    }
}

public class Twelve {
    public static void main(String[] args) {

    }
}
