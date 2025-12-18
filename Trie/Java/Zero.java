class Node {
    private Node link[] = new Node[26];
    private boolean isLast = false;

    boolean containsKey(char ch) {
        return link[ch - 'a'] != null;
    }

    void setLink(char ch, Node node) {
        link[ch - 'a'] = node;
    }

    Node getLink(char ch) {
        return link[ch - 'a'];
    }

    void setisLast() {
        isLast = true;
    }

    boolean getisLast() {
        return isLast;
    }
}

class Trie {
    private Node root;

    public Trie() {
        root = new Node();
    }

    public void insert(String word) {
        Node dummy = root;
        for (char i : word.toCharArray()) {
            if (!dummy.containsKey(i)) {
                dummy.setLink(i, new Node());
            }
            dummy = dummy.getLink(i);
        }
        dummy.setisLast();
    }

    public boolean search(String word) {
        Node dummy = root;
        for (char i : word.toCharArray()) {
            if (!dummy.containsKey(i)) {
                return false;
            }
            dummy = dummy.getLink(i);
        }
        return dummy.getisLast();
    }

    public boolean isPrefix(String word) {
        Node dummy = root;
        for (char i : word.toCharArray()) {
            if (!dummy.containsKey(i)) {
                return false;
            }
            dummy = dummy.getLink(i);
        }
        return true;
    }
}

public class Zero {
    public static void main(String[] args) {

    }
}
