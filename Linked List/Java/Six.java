
import java.util.HashSet;

class Node {

    int data;
    Node next;

    Node(int d) {
        data = d;
        next = null;
    }
}

class Solution {

    public Node removeDuplicates(Node head) {
        HashSet<Integer> set = new HashSet<>();
        Node curr = head;
        Node prev = null;

        while (curr != null) {
            if (prev.next != null && set.contains(curr.data)) {
                prev.next = curr.next;
            } else {
                set.add(curr.data);
                prev = curr;
            }
            curr = curr.next;
        }

        return head;
    }
}

public class Six {

    public static void main(String[] args) {
        Node node = new Node(1);
        node.next = new Node(3);
        node.next.next = new Node(2);
        node.next.next.next = new Node(1);
        node.next.next.next.next = new Node(4);
        node.next.next.next.next.next = new Node(3);
        node.next.next.next.next.next.next = new Node(4);
        node.next.next.next.next.next.next.next = new Node(4);
        System.out.print("Before Operation : ");
        display(node);
        Solution sol = new Solution();
        node = sol.removeDuplicates(node);
        System.out.print("After Operation : ");
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
