import java.util.*;

class Solution {

    static class Node {
        Node[] link = new Node[26];
        boolean isLast;
        ArrayList<Integer> index = new ArrayList<>();

        Node() {
            isLast = false;
            for (int i = 0; i < 26; i++)
                link[i] = null;
        }

        boolean containsKey(char c) {
            return link[c - 'a'] != null;
        }

        void setLink(char c, Node node) {
            link[c - 'a'] = node;
        }

        Node getLink(char c) {
            return link[c - 'a'];
        }

        void setIsLast() {
            isLast = true;
        }

        boolean getIsLast() {
            return isLast;
        }

        void addIndex(int ind) {
            index.add(ind);
        }

        ArrayList<Integer> getIndex() {
            return index;
        }
    }

    private Node root;

    private void insert(String str, int idx) {
        Node dummy = root;
        for (char c : str.toCharArray()) {
            if (!dummy.containsKey(c)) {
                dummy.setLink(c, new Node());
            }
            dummy = dummy.getLink(c);
        }
        dummy.setIsLast();
        dummy.addIndex(idx);
    }

    private void collect(Node root, String[] arr, ArrayList<ArrayList<String>> ans) {
        if (root == null)
            return;

        if (root.getIsLast()) {
            ArrayList<String> group = new ArrayList<>();
            for (int idx : root.getIndex()) {
                group.add(arr[idx]);
            }
            ans.add(group);
        }

        for (int i = 0; i < 26; i++) {
            if (root.link[i] != null) {
                collect(root.link[i], arr, ans);
            }
        }
    }

    public ArrayList<ArrayList<String>> anagrams(String[] arr) {
        root = new Node();
        int n = arr.length;
        for (int i = 0; i < n; i++) {
            char[] chars = arr[i].toCharArray();
            Arrays.sort(chars);
            insert(new String(chars), i);
        }

        ArrayList<ArrayList<String>> ans = new ArrayList<>();
        collect(root, arr, ans);
        return ans;
    }
}

public class Three {
    public static void main(String[] args) {
        Solution sol = new Solution();
        String[] arr1 = { "act", "god", "cat", "dog", "tac" };
        ArrayList<ArrayList<String>> ans1 = sol.anagrams(arr1);
        for (ArrayList<String> group : ans1) {
            for (String s : group) {
                System.out.print(s + " ");
            }
            System.out.println();
        }
        String[] arr2 = { "no", "on", "is" };
        ArrayList<ArrayList<String>> ans2 = sol.anagrams(arr2);
        for (ArrayList<String> group : ans2) {
            for (String s : group) {
                System.out.print(s + " ");
            }
            System.out.println();
        }
        String[] arr3 = { "listen", "silent", "enlist", "abc", "cab", "bac", "rat", "tar", "art" };
        ArrayList<ArrayList<String>> ans3 = sol.anagrams(arr3);
        for (ArrayList<String> group : ans3) {
            for (String s : group) {
                System.out.print(s + " ");
            }
            System.out.println();
        }
    }
}
