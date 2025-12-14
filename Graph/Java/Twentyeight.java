import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

class Solution {
    private ArrayList<ArrayList<Integer>> createAdjacencyList(int v, int[][] edges) {
        ArrayList<ArrayList<Integer>> adjList = new ArrayList<>();
        for (int i = 0; i < v; i++) {
            adjList.add(new ArrayList<>());
        }
        for (int i[] : edges) {
            adjList.get(i[0]).add(i[1]);
            adjList.get(i[1]).add(i[0]);
        }
        return adjList;
    }

    private boolean isBipartiteHelper(int start, ArrayList<ArrayList<Integer>> adjList, int color[]) {
        color[start] = 0;
        Queue<Integer> q = new LinkedList<>();
        q.add(start);
        while (!q.isEmpty()) {
            int node = q.poll();
            for (int neighbor : adjList.get(node)) {
                if (color[neighbor] == -1) {
                    color[neighbor] = color[node] == 0 ? 1 : 0;
                    q.add(neighbor);
                } else if (color[neighbor] == color[node]) {
                    return false;
                }
            }
        }
        return true;
    }

    public boolean isBipartite(int v, int[][] edges) {
        ArrayList<ArrayList<Integer>> adjList = createAdjacencyList(v, edges);
        int color[] = new int[v];
        Arrays.fill(color, -1);
        for (int i = 0; i < v; i++) {
            if (color[i] == -1) {
                if (!isBipartiteHelper(i, adjList, color)) {
                    return false;
                }
            }
        }
        return true;
    }
}

public class Twentyeight {
    public static void main(String[] args) {

    }
}
