class Node {
    int data;
    Node next;

    Node(int x) {
        data = x;
        next = null;
    }
}

class Solution {
    Node deleteNode(Node head, int key) {
        if (head == null) {
            return null;
        }
        if (head.data == key) {
            Node last = head;
            while (last.next != head) {
                last = last.next;
            }
            last.next = head.next;
            head = head.next;
            return head;
        }
        Node prev = head, curr = head.next;
        while (curr != head) {
            if (curr.data == key) {
                prev.next = curr.next;
                break;
            }
            prev = curr;
            curr = curr.next;
        }
        return head;
    }
}

public class Eighteen {
    static Node insert(Node head, int data) {
        Node newNode = new Node(data);

        if (head == null) {
            newNode.next = newNode;
            return newNode;
        }

        Node temp = head;
        while (temp.next != head) {
            temp = temp.next;
        }

        temp.next = newNode;
        newNode.next = head;

        return head;
    }

    // Function to print circular linked list
    static void printList(Node head) {
        if (head == null) {
            System.out.println("List is empty");
            return;
        }

        Node temp = head;
        do {
            System.out.print(temp.data + " -> ");
            temp = temp.next;
        } while (temp != head);

        System.out.println("(back to head)");
    }

    public static void main(String[] args) {
        Node head = null;

        // Creating circular linked list: 10 -> 20 -> 30 -> 40 -> 50
        head = insert(head, 10);
        head = insert(head, 20);
        head = insert(head, 30);
        head = insert(head, 40);
        head = insert(head, 50);

        System.out.println("Original Circular List:");
        printList(head);

        Solution obj = new Solution();

        int key = 30;
        head = obj.deleteNode(head, key);

        System.out.println("\nAfter deleting " + key + ":");
        printList(head);
    }
}
