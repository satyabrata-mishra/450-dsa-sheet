import java.util.*;

class Solution {
    public void dfs(int i, ArrayList<ArrayList<int[]>> adj, Queue<Integer> q, int[] mini, int[] vis) {
        vis[i] = 1;
        for (int[] it : adj.get(i)) {
            if (vis[it[0]] == 0) {
                int val = it[1];
                mini[0] = Math.min(mini[0], val);
                dfs(it[0], adj, q, mini, vis);
            }
        }
        q.add(i);
    }

    ArrayList<ArrayList<Integer>> solve(int n, int p, ArrayList<Integer> a, ArrayList<Integer> b,
            ArrayList<Integer> d) {
        ArrayList<ArrayList<int[]>> adj = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            adj.add(new ArrayList<>());
        }

        for (int i = 0; i < a.size(); i++) {
            adj.get(a.get(i)).add(new int[] { b.get(i), d.get(i) });
        }

        int[] vis = new int[n + 1];
        ArrayList<ArrayList<Integer>> ans = new ArrayList<>();

        int[] indegree = new int[n + 1];

        for (int i = 1; i <= n; i++) {
            for (int[] it : adj.get(i)) {
                indegree[it[0]]++;
            }
        }

        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0) {

                Queue<Integer> q = new LinkedList<>();
                int[] mini = new int[] { Integer.MAX_VALUE };

                dfs(i, adj, q, mini, vis);

                if (q.peek() == i)
                    continue;

                ArrayList<Integer> temp = new ArrayList<>();
                temp.add(i);
                temp.add(q.peek());
                temp.add(mini[0]);

                ans.add(temp);
            }
        }

        return ans;
    }
}

public class Three {
    public static void main(String[] args) {
        Solution sol = new Solution();

        int n = 9, p = 6;

        ArrayList<Integer> a = new ArrayList<>(Arrays.asList(7, 5, 4, 2, 9, 3));
        ArrayList<Integer> b = new ArrayList<>(Arrays.asList(4, 9, 6, 8, 7, 1));
        ArrayList<Integer> d = new ArrayList<>(Arrays.asList(98, 72, 10, 22, 17, 66));

        ArrayList<ArrayList<Integer>> ans = sol.solve(n, p, a, b, d);

        for (ArrayList<Integer> list : ans) {
            for (int val : list) {
                System.out.print(val + " ");
            }
            System.out.println();
        }
    }
}
