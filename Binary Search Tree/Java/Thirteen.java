import java.util.HashSet;

class Node {
    int data;
    Node left, right;

    Node(int val) {
        data = val;
        left = right = null;
    }
}

class Solution {
    public static void inorder(Node root, HashSet<Integer> set) {
        if (root == null)
            return;
        inorder(root.left, set);
        set.add(root.data);
        inorder(root.right, set);
    }

    public static int countPairs(Node root1, Node root2, int x) {
        HashSet<Integer> set1 = new HashSet<>();
        inorder(root1, set1);
        HashSet<Integer> set2 = new HashSet<>();
        inorder(root2, set2);
        int ans = 0;
        for (int i : set1) {
            int target = x - i;
            if (set2.contains(target))
                ++ans;
        }
        return ans;
    }
}

public class Thirteen {
    public static void main(String[] args) {

    }
}
