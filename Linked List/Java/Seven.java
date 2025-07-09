
class Node {

    int data;
    Node next;

    Node(int x) {
        data = x;
        next = null;
    }
}

class Solution {

    public static Node moveToFront(Node head) {
        Node curr = head;
        while (curr.next.next != null) {
            curr = curr.next;
        }
        Node ans = new Node(curr.next.data);
        ans.next = head;
        curr.next = null;
        return ans;
    }
}

public class Seven {

    public static void main(String[] args) {
        Node node = new Node(1);
        node.next = new Node(2);
        node.next.next = new Node(3);
        node.next.next.next = new Node(4);
        node.next.next.next.next = new Node(5);
        node.next.next.next.next.next = new Node(6);
        node.next.next.next.next.next.next = new Node(7);
        node.next.next.next.next.next.next.next = new Node(8);
        System.out.print("Before Operation : ");
        display(node);
        node = Solution.moveToFront(node);
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
