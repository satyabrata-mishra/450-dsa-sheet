import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Result {
    private static int dfs(int src, boolean[] visited, List<List<Integer>> adj) {
        visited[src] = true;
        int size = 1;

        for (int neighbour : adj.get(src)) {
            if (!visited[neighbour]) {
                size += dfs(neighbour, visited, adj);
            }
        }
        return size;
    }

    public static long journeyToMoon(int n, List<List<Integer>> astronaut) {
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }

        for (List<Integer> pair : astronaut) {
            int u = pair.get(0);
            int v = pair.get(1);
            adj.get(u).add(v);
            adj.get(v).add(u);
        }

        boolean[] visited = new boolean[n];
        List<Integer> componentSizes = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                componentSizes.add(dfs(i, visited, adj));
            }
        }
        long result = 0;
        long remaining = n;
        for (int size : componentSizes) {
            remaining -= size;
            result += (long) size * remaining;
        }
        return result;
    }
}

public class Thirtyone {
    public static void main(String[] args) {
        System.out.println(Result.journeyToMoon(4, Arrays.asList(Arrays.asList(1, 2), Arrays.asList(2, 3)))); // 3

        System.out.println(
                Result.journeyToMoon(5, Arrays.asList(Arrays.asList(0, 1), Arrays.asList(2, 3), Arrays.asList(0, 4)))); // 6

        System.out.println(Result.journeyToMoon(4, Arrays.asList(Arrays.asList(0, 2))));// 5
    }
}
