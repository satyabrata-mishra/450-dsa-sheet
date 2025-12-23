import java.util.ArrayList;
import java.util.Arrays;

class Node {
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

    void setLink(char c, Node n) {
        link[c - 'a'] = n;
    }

    Node getLink(char c) {
        return link[c - 'a'];
    }

    void setisLast() {
        isLast = true;
    }

    boolean getisLast() {
        return isLast;
    }
}

// User function Template for Java
class Solution {

    private Node root;

    private void insert(String str) {
        Node dummy = root;
        for (int i = 0; i < str.length(); i++) {
            char c = str.charAt(i);
            if (!dummy.containsKey(c)) {
                dummy.setLink(c, new Node());
            }
            dummy = dummy.getLink(c);
        }
        dummy.setisLast();
    }

    private boolean search(String str) {
        Node dummy = root;
        for (int i = 0; i < str.length(); i++) {
            char c = str.charAt(i);
            if (!dummy.containsKey(c)) {
                return false;
            }
            dummy = dummy.getLink(c);
        }
        return dummy.getisLast();
    }

    private boolean wordBreakUtil(String str) {
        if (str.length() == 0) {
            return true;
        }

        for (int i = 1; i <= str.length(); i++) {
            String temp1 = str.substring(0, i);
            String temp2 = str.substring(i);

            if (search(temp1) && wordBreakUtil(temp2)) {
                return true;
            }
        }
        return false;
    }

    public static int wordBreak(String a, ArrayList<String> b) {
        Solution sol = new Solution();
        sol.root = new Node();

        for (String s : b) {
            sol.insert(s);
        }

        return sol.wordBreakUtil(a) ? 1 : 0;
    }
}

public class Two {
    public static void main(String[] args) {
        ArrayList<String> dict = new ArrayList<>(Arrays.asList("i", "like", "sam", "sung", "samsung", "mobile", "ice",
                "cream", "icecream", "man", "go", "mango"));
        System.out.println(Solution.wordBreak("ilike", dict));
        System.out.println(Solution.wordBreak("ilikesamsung", dict));
    }
}
