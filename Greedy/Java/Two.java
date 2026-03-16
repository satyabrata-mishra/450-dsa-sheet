// User function Template for Java

import java.util.*;

class Node {
    int freq;
    char ch;
    Node left;
    Node right;

    Node(int f, char c) {
        freq = f;
        ch = c;
        left = null;
        right = null;
    }
}

class Solution {

    void dfs(Node root, String code, ArrayList<String> ans) {
        if (root == null) {
            return;
        }

        // leaf node
        if (root.left == null && root.right == null) {
            ans.add(code);
        }

        dfs(root.left, code + "0", ans);
        dfs(root.right, code + "1", ans);
    }

    public ArrayList<String> huffmanCodes(String s, int f[], int n) {

        PriorityQueue<Node> minHeap = new PriorityQueue<>(
                (a, b) -> {
                    if (a.freq == b.freq) {
                        return a.ch - b.ch;
                    }
                    return a.freq - b.freq;
                });

        for (int i = 0; i < n; i++) {
            minHeap.add(new Node(f[i], s.charAt(i)));
        }

        while (minHeap.size() > 1) {

            Node left = minHeap.poll();
            Node right = minHeap.poll();

            Node parent = new Node(left.freq + right.freq, '#');
            parent.left = left;
            parent.right = right;

            minHeap.add(parent);
        }

        Node root = minHeap.poll();

        ArrayList<String> ans = new ArrayList<>();

        dfs(root, "", ans);

        return ans;
    }
}

public class Two {
    public static void main(String[] args) {

        Solution sol = new Solution();

        String s = "abcdef";
        int[] f = { 5, 9, 12, 13, 16, 45 };
        int n = s.length();

        ArrayList<String> ans = sol.huffmanCodes(s, f, n);

        for (String code : ans) {
            System.out.print(code + " ");
        }

        System.out.println();
    }
}
