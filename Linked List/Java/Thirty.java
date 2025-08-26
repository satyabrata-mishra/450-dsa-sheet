import java.util.List;

class Node {
    int data;
    Node next;

    Node(int key) {
        data = key;
        next = null;
    }
}

class Solution {
    Node merge(Node head1, Node head2) {
        Node ans = new Node(0);
        Node dummy = ans;
        while (head1 != null && head2 != null) {
            if (head1.data < head2.data) {
                dummy.next = head1;
                head1 = head1.next;
            } else {
                dummy.next = head2;
                head2 = head2.next;
            }
            dummy = dummy.next;
        }
        dummy.next = head1 != null ? head1 : head2;
        return ans.next;
    }

    Node mergeKLists(List<Node> arr) {
        Node result = arr.get(0);
        for (int i = 1; i < arr.size(); i++)
            result = merge(result, arr.get(i));
        return result;
    }
}

public class Thirty {

}
