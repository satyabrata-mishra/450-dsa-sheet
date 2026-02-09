import java.util.ArrayList;
import java.util.List;

public class Thirtythree {
    static void dfs(int src, int[] timer,
            List<List<Integer>> adjacencyList,
            boolean[] visited,
            int[] intime,
            int[] outtime) {

        intime[src] = timer[0]++;
        visited[src] = true;

        for (int neighbour : adjacencyList.get(src)) {
            if (!visited[neighbour]) {
                dfs(neighbour, timer, adjacencyList, visited, intime, outtime);
            }
        }
        outtime[src] = timer[0]++;
    }

    static void oliverTheGame(int n,
            int[][] edges,
            int[][] queryList) {

        List<List<Integer>> adjacencyList = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adjacencyList.add(new ArrayList<>());
        }

        for (int[] e : edges) {
            int u = e[0] - 1;
            int v = e[1] - 1;
            adjacencyList.get(u).add(v);
            adjacencyList.get(v).add(u);
        }

        boolean[] visited = new boolean[n];
        int[] intime = new int[n];
        int[] outtime = new int[n];
        int[] timer = new int[] { 0 };

        dfs(0, timer, adjacencyList, visited, intime, outtime);

        for (int[] query : queryList) {
            int type = query[0];
            int X = query[1] - 1;
            int Y = query[2] - 1;

            if (type == 0) {
                if (intime[X] <= intime[Y] && outtime[X] >= outtime[Y]) {
                    System.out.println("YES");
                } else {
                    System.out.println("NO");
                }
            } else {
                if (intime[X] >= intime[Y] && outtime[X] <= outtime[Y]) {
                    System.out.println("YES");
                } else {
                    System.out.println("NO");
                }
            }
        }
    }

    public static void main(String[] args) {

        int n = 9;
        int[][] edges = {
                { 1, 2 }, { 1, 3 }, { 2, 6 }, { 2, 7 },
                { 6, 9 }, { 7, 8 }, { 3, 4 }, { 3, 5 }
        };

        int[][] query = {
                { 0, 2, 8 },
                { 1, 2, 8 },
                { 1, 6, 5 },
                { 0, 6, 5 },
                { 1, 9, 1 }
        };

        oliverTheGame(n, edges, query);
    }
}
