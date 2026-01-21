import java.util.*;

class Solution {
    public static int[] minimumTime(int n, int m, int[][] edges) {
        int[] indegree = new int[n + 1];
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            adj.add(new ArrayList<>());
        }
        for (int i = 0; i < m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj.get(u).add(v);
            indegree[v]++;
        }
        Queue<Integer> q = new LinkedList<>();
        int[] time = new int[n];
        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0) {
                q.add(i);
                time[i - 1] = 1;
            }
        }
        while (!q.isEmpty()) {
            int curr = q.poll();

            for (int next : adj.get(curr)) {
                if (indegree[next] > 0) {
                    --indegree[next];
                    if (indegree[next] == 0) {
                        q.add(next);
                        time[next - 1] = time[curr - 1] + 1;
                    }
                }
            }
        }
        return time;
    }
}

public class Fourteen {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int n1 = 10;
        int m1 = 13;
        int[][] edges1 = {
                { 1, 3 }, { 1, 4 }, { 1, 5 }, { 2, 3 }, { 2, 8 }, { 2, 9 },
                { 3, 6 }, { 4, 6 }, { 4, 8 }, { 5, 8 }, { 6, 7 }, { 7, 8 }, { 8, 10 }
        };

        int[] ans1 = sol.minimumTime(n1, m1, edges1);
        for (int x : ans1) {
            System.out.print(x + " ");
        }
        System.out.println();
        // Output: 1 1 2 2 2 3 4 5 2 6

        int n2 = 7;
        int m2 = 7;
        int[][] edges2 = {
                { 1, 2 }, { 2, 3 }, { 2, 4 }, { 2, 5 }, { 3, 6 }, { 4, 6 }, { 5, 7 }
        };

        int[] ans2 = sol.minimumTime(n2, m2, edges2);
        for (int x : ans2) {
            System.out.print(x + " ");
        }
        System.out.println();
    }
}
