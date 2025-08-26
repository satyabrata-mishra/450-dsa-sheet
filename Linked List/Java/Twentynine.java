import java.util.HashMap;

class Node {
    int data;
    Node next;
    Node random;

    Node(int x) {
        data = x;
        next = null;
        random = null;
    }
}

class Solution {
    public Node cloneLinkedList(Node head) {
        HashMap<Node, Node> map = new HashMap<>();
        Node temp = head;
        while (temp != null) {
            map.put(temp, new Node(temp.data));
            temp = temp.next;
        }
        for (Node originalNode : map.keySet()) {
            map.get(originalNode).next = map.get(originalNode.next);
            map.get(originalNode).random = map.get(originalNode.random);
        }
        return map.get(head);
    }
}

public class Twentynine {

}
