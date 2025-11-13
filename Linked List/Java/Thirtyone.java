class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

class Solution {
    public long multiplyTwoLists(Node first, Node second) {
        long num1 = 0, num2 = 0, mod = 1000000007;
        while (first != null) {
            num1 = ((num1 * 10) + first.data) % mod;
            first = first.next;
        }
        while (second != null) {
            num2 = ((num2 * 10) + second.data) % mod;
            second = second.next;
        }
        return (num1 * num2) % mod;

    }
}

public class Thirtyone {
    public static void main(String[] args) {
        Solution sol = new Solution();
        Node head1 = new Node(1);
        head1.next = new Node(0);
        head1.next.next = new Node(0);
        Node head2 = new Node(1);
        head2.next = new Node(0);
        System.out.println(sol.multiplyTwoLists(head1, head2));
    }
}
