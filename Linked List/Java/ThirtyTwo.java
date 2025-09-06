class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
    }
}

class Solution {
    Node reverse(Node head) {
        Node prev = null, curr = head, next = null;
        while (curr != null) {
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    Node compute(Node head) {
        head = reverse(head);
        int maxData = head.data;
        Node prev = head, curr = head.next;
        while (curr != null) {
            if (maxData > curr.data) {
                prev.next = curr.next;
            } else {
                maxData = curr.data;
                prev = curr;
            }
            curr = curr.next;
        }
        head = reverse(head);
        return head;
    }
}

public class ThirtyTwo {

}
