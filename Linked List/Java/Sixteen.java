class Node {
    int data;
    Node next;

    Node(int d) {
        data = d;
        next = null;
    }
}

class Solution {
    public Pair<Node, Node> splitList(Node head) {
        Node slow = head, fast = head;
        while (fast.next != head && fast.next.next != head) {
            slow = slow.next;
            fast = fast.next.next;
        }
        Node head1 = head;
        Node head2 = slow.next;
        fast = (fast.next.next == head) ? fast.next : fast;
        fast.next = head2;
        slow.next = head;
        return new Pair<Node, Node>(head1, head2);
    }
}

public class Sixteen {

}
