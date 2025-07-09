
class ListNode {

    int val;
    ListNode next;

    ListNode(int val) {
        this.val = val;
    }
}

class Solution {

    private int length(ListNode head) {
        int ans = 0;
        ListNode curr = head;
        while (curr != null) {
            curr = curr.next;
            ++ans;
        }
        return ans;
    }

    public ListNode middleNode(ListNode head) {
        int length = length(head);
        ListNode curr = head;
        for (int i = 0; i < length / 2; i++) {
            curr = curr.next;
        }
        return curr;
    }
}

public class Fourteen {

    public static void main(String[] args) {
        ListNode node = new ListNode(1);
        node.next = new ListNode(3);
        node.next.next = new ListNode(2);
        node.next.next.next = new ListNode(1);
        node.next.next.next.next = new ListNode(4);
        node.next.next.next.next.next = new ListNode(3);
        node.next.next.next.next.next.next = new ListNode(4);
        // node.next.next.next.next.next.next.next = new ListNode(4);
        System.out.print("Before Operation : ");
        display(node);
        Solution sol = new Solution(); // 1 3 2 1 4 3 4 4
        node = sol.middleNode(node);
        System.out.print("After Operation : ");
        display(node);
    }

    private static void display(ListNode node) {
        ListNode temp = node;
        while (temp != null) {
            System.out.print(temp.val + " ");
            temp = temp.next;
        }
        System.out.println();
    }
}
