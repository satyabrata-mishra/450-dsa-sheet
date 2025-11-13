class Node {
    int data;
    Node next;

    Node(int x) {
        data = x;
        next = null;
    }
}

class Solution {
    Node divide(Node head) {
        Node evenStart = new Node(0), oddStart = new Node(0);
        Node dummyEven = evenStart, dummyOdd = oddStart;
        while (head != null) {
            if (head.data % 2 == 0) {
                dummyEven.next = new Node(head.data);
                dummyEven = dummyEven.next;
            } else {
                dummyOdd.next = new Node(head.data);
                dummyOdd = dummyOdd.next;
            }
            head = head.next;
        }
        dummyEven.next = oddStart.next;
        return evenStart.next;
    }
}

public class Thirtythree {
    public static void main(String[] args) {
        Solution sol = new Solution();
        Node head = new Node(17);
        head.next = new Node(15);
        head.next.next = new Node(8);
        head.next.next.next = new Node(9);
        head.next.next.next.next = new Node(2);
        head.next.next.next.next.next = new Node(4);
        head.next.next.next.next.next.next = new Node(6);
        head = sol.divide(head);
        while (head != null) {
            System.out.println(head -> data);
            head = head.next;
        }
    }
}
