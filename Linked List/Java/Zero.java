
class Node {

    int value;
    Node next;

    Node(int value) {
        this.value = value;
    }
}

class Solution {

    Node reverseList(Node head) {
        Node prev = null, curr = head, next;
        while (curr != null) {
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
}

public class Zero {

    public static void main(String[] args) {
        Solution sol = new Solution();
        Node node = new Node(0);
        node.next = new Node(1);
        node.next.next = new Node(2);
        node.next.next.next = new Node(3);
        System.out.print("Before reversing : ");
        display(node);
        node = sol.reverseList(node);
        System.out.print("After reversing : ");
        display(node);
    }

    private static void display(Node node) {
        Node temp = node;
        while (temp != null) {
            System.out.print(temp.value + " ");
            temp = temp.next;
        }
        System.out.println();
    }
}
