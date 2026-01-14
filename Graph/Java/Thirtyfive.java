import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;

class Pair {
    int node, weight;

    Pair(int node, int weight) {
        this.node = node;
        this.weight = weight;
    }
}

class Solution {
    boolean findPath(ArrayList<ArrayList<Pair>> adj, int src, int k, boolean visited[]) {
        if (k <= 0)
            return true;
        for (Pair i : adj.get(src)) {
            if (visited[i.node] == true) {
                continue;
            }
            visited[i.node] = true;
            if (findPath(adj, i.node, k - i.weight, visited) == true) {
                return true;
            }
            visited[i.node] = false;
        }
        return false;
    }

    boolean pathMoreThanK(int v, int e, int k, int[] a) {
        ArrayList<ArrayList<Pair>> adjacencyList = new ArrayList<>();
        for (int i = 0; i < v; i++) {
            adjacencyList.add(new ArrayList<>());
        }
        for (int i = 0; i < e * 3; i += 3) {
            adjacencyList.get(a[i]).add(new Pair(a[i + 1], a[i + 2]));
            adjacencyList.get(a[i + 1]).add(new Pair(a[i], a[i + 2]));
        }
        boolean visited[] = new boolean[v];
        visited[0] = true;
        return findPath(adjacencyList, 0, k, visited);
    }
}

public class Thirtyfive {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.pathMoreThanK(4, 3, 8, new int[] { 0, 1, 5, 1, 2, 1,
                2, 3, 1 })); // 0
        System.out.println(sol.pathMoreThanK(9, 14, 60, new int[] { 0, 1, 4, 0, 7, 8, 1, 2, 8, 1, 7, 11, 2, 3, 7, 2, 5,
                4, 2, 8, 2, 3, 4, 9, 3, 5, 14, 4, 5, 10, 5, 6, 2, 6, 7, 1, 6, 8, 6, 7, 8, 7 })); // 0
    }
}
