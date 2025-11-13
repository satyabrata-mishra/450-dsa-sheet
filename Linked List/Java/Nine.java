
class Node {
    int data;
    Node next;

    Node(int x) {
        data = x;
        next = null;
    }
}

class Solution {
    private Node reverse(Node node) {
        Node prev = null, curr = node, next = null;
        while (curr != null) {
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    Node removeLeadingZeros(Node node) {
        while (node != null && node.data == 0) {
            node = node.next;
        }
        return node;
    }

    public Node addTwoLists(Node head1, Node head2) {
        head1 = removeLeadingZeros(head1);
        head2 = removeLeadingZeros(head2);
        head1 = reverse(head1);
        head2 = reverse(head2);
        int carry = 0;
        Node ans = new Node(-1);
        Node dummy = ans;
        while (head1 != null && head2 != null) {
            int sum = head1.data + head2.data + carry;
            carry = sum / 10;
            dummy.next = new Node(sum % 10);
            dummy = dummy.next;
            head1 = head1.next;
            head2 = head2.next;
        }
        while (head1 != null) {
            int sum = head1.data + carry;
            carry = sum / 10;
            dummy.next = new Node(sum % 10);
            dummy = dummy.next;
            head1 = head1.next;
        }
        while (head2 != null) {
            int sum = head2.data + carry;
            carry = sum / 10;
            dummy.next = new Node(sum % 10);
            dummy = dummy.next;
            head2 = head2.next;
        }
        if (carry != 0) {
            dummy.next = new Node(carry);
            dummy = dummy.next;
        }
        return reverse(ans.next);
    }
}

public class Nine {
    public static void main(String[] args) {
        Solution sol = new Solution();
        Node head1 = new Node(1);
        head1.next = new Node(2);
        head1.next.next = new Node(3);
        Node head2 = new Node(9);
        head2.next = new Node(9);
        head2.next.next = new Node(9);
        Node ans = sol.addTwoLists(head1, head2);
        while (ans != nullptr) {
            System.out.print(ans.data + " ");
            ans = ans.next;
        }
        System.out.println();
        head1 = new Node(0);
        head1.next = new Node(0);
        head1.next.next = new Node(6);
        head1.next.next.next = new Node(3);
        head2 = new Node(0);
        head2.next = new Node(7);
        ans = sol.addTwoLists(head1, head2);
        while (ans != nullptr) {
            System.out.print(ans.data + " ");
            ans = ans.next;
        }
        System.out.println();
    }
}
