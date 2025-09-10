import java.util.ArrayList;
import java.util.HashMap;

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

class Tree {
    public void helper(Node root, int diagonal, HashMap<Integer, ArrayList<Integer>> map) {
        if (root == null)
            return;
        if (!map.containsKey(diagonal))
            map.put(diagonal, new ArrayList<>());
        map.get(diagonal).add(root.data);
        helper(root.left, diagonal + 1, map);
        helper(root.right, diagonal, map);
    }

    public ArrayList<Integer> diagonal(Node root) {
        HashMap<Integer, ArrayList<Integer>> map = new HashMap<>();
        helper(root, 0, map);
        ArrayList<Integer> ans = new ArrayList<>();
        for (int i : map.keySet())
            ans.addAll(map.get(i));
        return ans;
    }
}

public class Fourteen {
    public static void main(String[] args) {
    }
}
