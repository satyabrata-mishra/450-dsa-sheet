import java.util.ArrayList;
import java.util.Arrays;

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

    private boolean graphColoringHelper(int start, int color[], ArrayList<ArrayList<Integer>> adjList, int maxColor) {
        for (int c = 0; c < maxColor; c++) {
            boolean canUse = true;
            for (int neighbor : adjList.get(start)) {
                if (color[neighbor] == c) {
                    canUse = false;
                    break;
                }
            }
            if (canUse) {
                color[start] = c;
                for (int neighbor : adjList.get(start)) {
                    if (color[neighbor] == -1) {
                        if (graphColoringHelper(neighbor, color, adjList, maxColor) == false) {
                            color[start] = -1;
                            return false;
                        }
                    }
                }
                return true;
            }
        }
        return false;
    }

    boolean graphColoring(int v, int[][] edges, int m) {
        ArrayList<ArrayList<Integer>> adjList = createAdjacencyList(v, edges);
        int color[] = new int[v];
        Arrays.fill(color, -1);
        for (int i = 0; i < v; i++) {
            if (graphColoringHelper(i, color, adjList, m) == false) {
                return false;
            }
        }
        return true;
    }
}

public class Thirtysix {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.graphColoring(4, new int[][] { { 0, 1 }, { 1, 3 }, { 2, 3 }, { 3, 0 }, { 0, 2 } }, 3)); // 1
        System.out.println(sol.graphColoring(3, new int[][] { { 0, 1 }, { 1, 2 }, { 0, 2 } }, 2)); // 0
    }
}
