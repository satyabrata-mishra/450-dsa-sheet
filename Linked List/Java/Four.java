
class Node {

    int data;
    Node next;

    Node(int x) {
        data = x;
        next = null;
    }
}

class Solution {

    public static Node findFirstNode(Node head) {
        Node slow = head, fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            if (slow == fast) {
                break;
            }
        }
        if (slow != fast) {
            return null;
        }
        slow = head;
        while (slow != fast) {
            slow = slow.next;
            fast = fast.next;
        }
        return slow;

    }
}

public class Four {

    public static void main(String[] args) {

    }
}
