import java.util.*;

class Node {
    private Node[] link;
    private boolean isLast;

    public Node() {
        link = new Node[2];
        isLast = false;
    }

    public boolean containsKey(char c) {
        return link[c - '0'] != null;
    }

    public void setLink(char c, Node n) {
        link[c - '0'] = n;
    }

    public Node getLink(char c) {
        return link[c - '0'];
    }

    public void setIsLast() {
        isLast = true;
    }

    public boolean getIsLast() {
        return isLast;
    }
}

class GfG {
    private Node root;

    private boolean insert(String s) {
        Node dummy = root;
        for (char c : s.toCharArray()) {
            if (!dummy.containsKey(c)) {
                dummy.setLink(c, new Node());
            }
            dummy = dummy.getLink(c);
        }
        if (dummy.getIsLast()) {
            return false;
        }
        dummy.setIsLast();
        return true;
    }

    public ArrayList<ArrayList<Integer>> uniqueRow(int[][] m, int row, int col) {
        root = new Node();
        ArrayList<ArrayList<Integer>> ans = new ArrayList<>();

        for (int i = 0; i < row; i++) {
            String str = "";
            ArrayList<Integer> tmp = new ArrayList<>();
            for (int j = 0; j < col; j++) {
                str += m[i][j];
                tmp.add(m[i][j]);
            }
            if (insert(str)) {
                ans.add(tmp);
            }
        }
        root = null;
        return ans;
    }
}

public class Five {
    public static void main(String[] args) {
        GfG sol = new GfG();
        int[][] m = { { 1, 1, 0, 1 }, { 1, 0, 0, 1 }, { 1, 1, 0, 1 } };
        ArrayList<ArrayList<Integer>> ans = sol.uniqueRow(m, 3, 4);
        for (List<Integer> row : ans) {
            for (int val : row) {
                System.out.print(val + " ");
            }
            System.out.println();
        }
        int[][] n = { { 0, 0, 0, 1 }, { 0, 0, 0, 1 } };
        ans = sol.uniqueRow(n, 2, 4);
        for (List<Integer> row : ans) {
            for (int val : row) {
                System.out.print(val + " ");
            }
            System.out.println();
        }
    }
}
