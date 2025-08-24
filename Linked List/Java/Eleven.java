class Node {
    int data;
    Node next;

    Node(int d) {
        data = d;
        next = null;
    }
}

class Solution {
    private int length(Node head) {
        int len = 0;
        while (head != null) {
            ++len;
            head = head.next;
        }
        return len;
    }

    public Node intersectPoint(Node head1, Node head2) {
        int len1 = length(head1), len2 = length(head2);
        while (len1 != len2) {
            if (len1 > len2) {
                head1 = head1.next;
                len1--;
            } else {
                head2 = head2.next;
                len2--;
            }
        }
        while (head1 != null && head2 != null) {
            if (head1 == head2) {
                return head1;
            }
            head1 = head1.next;
            head2 = head2.next;
        }
        return null;
    }
}

public class Eleven {
    public static void main(String[] args) {
        // Shared nodes
        Node intersection = new Node(8);
        intersection.next = new Node(4);
        intersection.next.next = new Node(5);

        // First list: 4 -> 1 -> 8 -> 4 -> 5
        Node head1 = new Node(4);
        head1.next = new Node(1);
        head1.next.next = intersection;

        // Second list: 5 -> 6 -> 1 -> 8 -> 4 -> 5
        Node head2 = new Node(5);
        head2.next = new Node(6);
        head2.next.next = new Node(1);
        head2.next.next.next = intersection;

        Solution sol = new Solution();
        Node result = sol.intersectPoint(head1, head2);
        System.out.println("Intersection at node with data: " + result.data);
    }
}
