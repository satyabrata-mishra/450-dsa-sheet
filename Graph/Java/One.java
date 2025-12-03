import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<List<Integer>> printGraph(int V, int edges[][]) {
        List<List<Integer>> ans = new ArrayList<>();
        for (int i = 0; i < V; i++) {
            ans.add(new ArrayList<>());
        }
        for (int[] i : edges) {
            ans.get(i[0]).add(i[1]);
            ans.get(i[1]).add(i[0]);
        }
        return ans;
    }
}

public class One {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int edges[][] = { { 0, 1 }, { 0, 4 }, { 4, 1 }, { 4, 3 }, { 1, 3 }, { 1, 2 }, { 3, 2 } };
        System.out.println(sol.printGraph(5, edges));
    }
}
