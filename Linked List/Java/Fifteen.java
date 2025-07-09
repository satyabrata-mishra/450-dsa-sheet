
class Node {

    int data;
    Node next;

    Node(int d) {
        data = d;
        next = null;
    }
}

class Solution {

    boolean isCircular(Node head) {
        Node slow = head, fast = head;
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

public class Fifteen {

    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.isCircular(new Node(0)));
    }
}
