class Node {
    int data;
    Node next;
}

class Solution {
    public static void removeLoop(Node head) {
        Node slow = head, fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            if (slow == fast) {
                break;
            }
        }
        if (fast == null || fast.next == null) {
            return;
        }
        slow = head;
        while (slow != fast) {
            slow = slow.next;
            fast = fast.next;
        }
        while (slow.next != fast) {
            slow = slow.next;
        }
        slow.next = null;
    }
}

public class Three {

}
