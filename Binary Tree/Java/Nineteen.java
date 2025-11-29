import java.util.HashMap;

class Node {
    int data;
    Node left, right;

    Node(int val) {
        data = val;
        left = right = null;
    }
}

class Solution {
    public static HashMap<Integer, Integer> map;
    public static int pre;

    public static Node helper(int preorder[], int inorder[], int inStart, int inEnd) {
        if (inStart > inEnd) {
            return null;
        }
        int rootVal = preorder[pre++];
        Node head = new Node(rootVal);
        int mid = map.get(rootVal);
        head.left = helper(preorder, inorder, inStart, mid - 1);
        head.right = helper(preorder, inorder, mid + 1, inEnd);
        return head;
    }

    public static Node buildTree(int inorder[], int preorder[]) {
        map = new HashMap<>();
        int n = inorder.length;
        pre = 0;
        for (int i = 0; i < n; i++) {
            map.put(inorder[i], i);
        }
        return helper(preorder, inorder, 0, n - 1);
    }
}

public class Nineteen {
    public static void main(String[] args) {
        Node ans = Solution.buildTree(new int[] { 3, 1, 4, 0, 5, 2 }, new int[] { 0, 1, 3, 4, 2, 5 });
        display(ans);
    }

    public static void display(Node head) {
        if (head == null) {
            return;
        }
        System.out.println(head.data + " ");
        display(head.left);
        display(head.right);
    }
}
