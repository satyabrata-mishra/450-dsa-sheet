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
    Node mergeTwoLists(Node head1, Node head2){
        Node dummy = new Node(0);
        Node ans = dummy;
        while(head1 != null && head2 != null){
            if(head1.data <= head2.data){
                dummy.next = new Node(head1.data);
                dummy = dummy.next;
                head1 = head1.next;
            }else{
                dummy.next = new Node(head2.data);
                dummy = dummy.next;
                head2 = head2.next;
            }
        }
        while(head1 != null){
            dummy.next = new Node(head1.data);
            dummy = dummy.next;
            head1 = head1.next;
        }
        while(head2 != null){
            dummy.next = new Node(head2.data);
            dummy = dummy.next;
            head2 = head2.next;
        }
        return ans.next;
    }
    Node mergeKLists(List<Node> arr) {
        if(arr.size()==1){
            return arr.get(0);
        }
        Node ans = mergeTwoLists(arr.get(0),arr.get(1));
        for(int i=2;i<arr.size();i++){
            ans = mergeTwoLists(ans,arr.get(i));
        }
        return ans;
    }
}

public class Nine {

}
