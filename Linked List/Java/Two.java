
class Node {

    int data;
    Node next;

    Node(int d) {
        data = d;
        next = null;
    }
}

class Solution {

    public static boolean detectLoop(Node head) {
        Node fast = head, slow = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
}

public class Two {

    public static void main(String[] args) {
        Node node = new Node(1);
        node.next = new Node(3);
        node.next.next = new Node(4);
        node.next.next.next = node.next.next;
        System.out.println(Solution.detectLoop(node));
    }
}
