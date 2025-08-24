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
    public static Node findIntersection(Node head1, Node head2) {
        HashSet<Integer> set = new HashSet<>();
        while (head1 != null) {
            set.add(head1.data);
            head1 = head1.next;
        }
        Node ans = new Node(0);
        Node dummy = ans;
        while (head2 != null) {
            if (set.contains(head2.data)) {
                dummy.next = new Node(head2.data);
                dummy = dummy.next;
            }
            head2 = head2.next;
        }
        return ans.next;
    }
}

public class Ten {
    public static void main(String[] args) {
        Node head1 = new Node(1);
        head1.next = new Node(2);
        head1.next.next = new Node(3);
        head1.next.next.next = new Node(4);
        head1.next.next.next.next = new Node(6);
        Node head2 = new Node(2);
        head2.next = new Node(4);
        head2.next.next = new Node(6);
        head2.next.next.next = new Node(8);
        Node ans = Solution.findIntersection(head1, head2);
        while (ans != null) {
            System.out.print(ans.data + " ");
            ans = ans.next;
        }
    }
}
