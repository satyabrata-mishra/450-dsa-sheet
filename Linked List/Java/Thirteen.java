class Node {
    int data;
    Node next;

    Node(int x) {
        data = x;
        next = null;
    }
}

class Solution {

    private Node getTail(Node head) {
        Node temp = head;
        while (temp.next != null) {
            temp = temp.next;
        }
        return temp;
    }

    private Node partition(Node head, Node tail) {
        Node pivot = head;
        Node curr = head.next;
        Node prev = head;

        while (curr != tail.next) {
            if (pivot.data > curr.data) {
                // swap(prev.next.data, curr.data)
                int temp = prev.next.data;
                prev.next.data = curr.data;
                curr.data = temp;

                prev = prev.next;
            }
            curr = curr.next;
        }

        // swap(prev.data, pivot.data)
        int temp = prev.data;
        prev.data = pivot.data;
        pivot.data = temp;

        return prev;
    }

    private void solveSort(Node head, Node tail) {
        if (head == null || tail == null || head == tail) {
            return;
        }

        Node pivot = partition(head, tail);

        solveSort(head, pivot);
        solveSort(pivot.next, tail);
    }

    public Node quickSort(Node head) {
        if (head == null || head.next == null) {
            return null; // same as your C++ (still a bug logically)
        }

        Node tail = getTail(head);
        solveSort(head, tail);
        return head;
    }
}

public class Thirteen {
    public static void main(String[] args) {
        Node root = new Node(1);
        root.next = new Node(9);
        root.next.next = new Node(3);
        root.next.next.next = new Node(8);

        Solution sol = new Solution();
        root = sol.quickSort(root);

        while (root != null) {
            System.out.print(root.data + " -> ");
            root = root.next;
        }
    }
}
