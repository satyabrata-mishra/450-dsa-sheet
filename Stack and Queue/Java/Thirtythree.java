import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;

class Node {
    int data;
    Node left;
    Node right;

    Node(int data) {
        this.data = data;
        left = null;
        right = null;
    }
}

class Solution {
    public static boolean areAnagrams(Node node1, Node node2) {
        Queue<Node> qt1 = new LinkedList<>();
        Queue<Node> qt2 = new LinkedList<>();
        qt1.offer(node1);
        qt2.offer(node2);
        while (qt1.size() > 0 && qt2.size() > 0) {
            int leve1 = qt1.size();
            int leve2 = qt2.size();
            ArrayList<Integer> ans1 = new ArrayList<>();
            ArrayList<Integer> ans2 = new ArrayList<>();
            if (leve1 != leve2)
                return false;
            for (int i = 0; i < leve1; i++) {
                if (qt1.peek().left != null)
                    qt1.offer(qt1.peek().left);
                if (qt2.peek().left != null)
                    qt2.offer(qt2.peek().left);
                if (qt1.peek().right != null)
                    qt1.offer(qt1.peek().right);
                if (qt2.peek().right != null)
                    qt2.offer(qt2.peek().right);
                ans1.add(qt1.poll().data);
                ans2.add(qt2.poll().data);
            }
            Collections.sort(ans1);
            Collections.sort(ans2);
            for (int m = 0; m < leve1; m++) {
                int x = ans1.get(m);
                int y = ans2.get(m);
                if (x != y)
                    return false;
            }
        }
        return true;
    }
}

public class Thirtythree {
    public static void main(String[] args) {

    }
}
