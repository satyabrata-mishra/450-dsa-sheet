class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        next = null;
    }
}

class Solution {
    static Node segregate(Node head) {
        int zero = 0, one = 0, two = 0;
        while (head != null) {
            int data = head.data;
            if (data == 0)
                ++zero;
            else if (data == 1)
                ++one;
            else
                ++two;
            head = head.next;
        }
        Node ans = new Node(0);
        Node dummy = ans;
        while (zero-- != 0) {
            dummy.next = new Node(0);
            dummy = dummy.next;
        }
        while (one-- != 0) {
            dummy.next = new Node(1);
            dummy = dummy.next;
        }
        while (two-- != 0) {
            dummy.next = new Node(2);
            dummy = dummy.next;
        }
        return ans.next;

    }
}

public class Twentyeight {

}
