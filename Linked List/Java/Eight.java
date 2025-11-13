class Node {
    int data;
    Node next;

    Node(int x) {
        data = x;
        next = null;
    }
}

class Solution {

    private Node reverseNode(Node head) {
        Node prev = null, curr = head, next = null;
        while (curr != null) {
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    Node removeLeadingZeros(Node head) {
        while (head != null && head.data == 0) {
            head = head.next;
        }
        return head;
    }

    public Node addOne(Node head) {
        head = removeLeadingZeros(head);
        head = reverseNode(head);
        Node curr = head;
        int carry = 1;
        while (curr != null) {
            int sum = curr.data + carry;
            curr.data = sum % 10;
            carry = sum / 10;
            if (carry == 0)
                break;
            if (curr.next == null && carry != 0) {
                curr.next = new Node(0);
            }
            curr = curr.next;
        }
        if (carry != 0) {
            curr.next = new Node(carry);
        }
        return reverseNode(head);
    }
}

public class Eight {
    public static void main(String[] args) {
        Solution sol = new Solution();
        Node head1 = new Node(4);
        head1.next = new Node(5);
        head1.next.next = new Node(6);
        Node ans = sol.addOne(head1);
        while (ans != nullptr) {
            System.out.print(ans.data + " ");
            ans = ans.next;
        }
    }
}
