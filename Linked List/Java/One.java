
class Node {

    int data;
    Node next;

    Node(int key) {
        data = key;
        next = null;
    }
}

class Solution {

    public static Node reverseKGroup(Node head, int k) {
        if (head == null) {
            return head;
        }
        Node prev = null, curr = head, next = null;
        int count = k;
        while (curr != null && count-- > 0) {
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        head.next = reverseKGroup(next, k);
        return prev;
    }
}

public class One {

    public static void main(String[] args) {
        Node node = new Node(1);
        node.next = new Node(2);
        node.next.next = new Node(3);
        node.next.next.next = new Node(4);
        node.next.next.next.next = new Node(5);
        node.next.next.next.next.next = new Node(6);
        node.next.next.next.next.next.next = new Node(7);
        node.next.next.next.next.next.next.next = new Node(8);
        System.out.print("Before reversing : ");
        display(node);
        node = Solution.reverseKGroup(node, 4);
        System.out.println("After reversing : ");
        display(node);
    }

    private static void display(Node node) {
        Node temp = node;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }
}
