import java.util.ArrayList;

class Solution {

    static class Node {
        Node[] link = new Node[26];
        boolean isLast;

        Node() {
            for (int i = 0; i < 26; i++) {
                link[i] = null;
            }
            isLast = false;
        }

        boolean containsKey(char c) {
            return link[c - 'a'] != null;
        }

        Node getLink(char c) {
            return link[c - 'a'];
        }

        void setLink(char c, Node node) {
            link[c - 'a'] = node;
        }

        void setIsLast() {
            isLast = true;
        }

        boolean getIsLast() {
            return isLast;
        }
    }

    static Node root;

    static void insert(String str) {
        Node dummy = root;
        for (char c : str.toCharArray()) {
            if (dummy.getLink(c) == null) {
                dummy.setLink(c, new Node());
            }
            dummy = dummy.getLink(c);
        }
        dummy.setIsLast();
    }

    static void dfs(Node node, StringBuilder prefix, ArrayList<String> ans) {
        if (node.getIsLast()) {
            ans.add(prefix.toString());
        }

        for (int i = 0; i < 26; i++) {
            char c = (char) (i + 'a');
            if (node.getLink(c) != null) {
                prefix.append(c);
                dfs(node.getLink(c), prefix, ans);
                prefix.deleteCharAt(prefix.length() - 1);
            }
        }
    }

    static ArrayList<ArrayList<String>> displayContacts(int n, String contact[], String s) {
        root = new Node();

        for (int i = 0; i < n; i++) {
            insert(contact[i]);
        }

        ArrayList<ArrayList<String>> ans = new ArrayList<>();
        Node dummy = root;
        StringBuilder prefix = new StringBuilder();

        for (char c : s.toCharArray()) {
            prefix.append(c);

            if (dummy == null || !dummy.containsKey(c)) {
                ArrayList<String> temp = new ArrayList<>();
                temp.add("0");
                ans.add(temp);
                dummy = null;
            } else {
                dummy = dummy.getLink(c);
                ArrayList<String> temp = new ArrayList<>();
                dfs(dummy, prefix, temp);
                ans.add(temp);
            }
        }

        return ans;
    }
}

public class Four {
    public static void main(String[] args) {
        System.out.println(
                Solution.displayContacts(3, new String[] { "geeikistest", "geeksforgeeks", "geeksfortest" }, "geeips"));
    }
}
