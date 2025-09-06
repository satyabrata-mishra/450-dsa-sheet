class Node {
    int data;
    Node next;

    Node(int d) {
        data = d;
        next = null;
    }
}

class Solution {
    int length(Node head) {
        Node temp = head;
        int len = 0;
        while (temp != null) {
            ++len;
            temp = temp.next;
        }
        return len;
    }

    int getKthFromLast(Node head, int k) {
        int len = length(head);
        if (k > len)
            return -1;
        Node temp = head;
        for (int i = 0; i < len - k; i++)
            temp = temp.next;
        return temp.data;
    }
}

public class Thirtyfour {

}
