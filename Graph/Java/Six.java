import java.util.ArrayList;

class Solution {
    private void helper(int currRow, int currCol, int destRow, int destCol, boolean[][] visited, StringBuilder route,
            int[][] maze, ArrayList<String> ans, int[] dRow, int[] dCol) {
        visited[currRow][currCol] = true;
        if (currRow == destRow && currCol == destCol) {
            ans.add(route.toString());
        }
        for (int i = 0; i < 4; i++) {
            int newRow = currRow + dRow[i];
            int newCol = currCol + dCol[i];

            if (newRow >= 0 && newCol >= 0 && newRow <= destRow && newCol <= destCol && maze[newRow][newCol] == 1
                    && !visited[newRow][newCol]) {
                if (i == 0) {
                    route.append('D');
                } else if (i == 1) {
                    route.append('L');
                } else if (i == 2) {
                    route.append('R');
                } else if (i == 3) {
                    route.append('U');
                }
                helper(newRow, newCol, destRow, destCol, visited, route, maze, ans, dRow, dCol);
                route.deleteCharAt(route.length() - 1);
            }
        }
        visited[currRow][currCol] = false;
    }

    public ArrayList<String> ratInMaze(int[][] maze) {
        int n = maze.length;
        ArrayList<String> ans = new ArrayList<>();
        if (n == 0 || maze[0][0] == 0 || maze[n - 1][n - 1] == 0) {
            return ans;
        }
        int[] dRow = { 1, 0, 0, -1 };
        int[] dCol = { 0, -1, 1, 0 };
        boolean[][] visited = new boolean[n][n];
        StringBuilder route = new StringBuilder();
        helper(0, 0, n - 1, n - 1, visited, route, maze, ans, dRow, dCol);
        return ans;
    }
}

public class Six {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[][] maze1 = {
                { 1, 0, 0, 0 },
                { 1, 1, 0, 1 },
                { 1, 1, 0, 0 },
                { 0, 1, 1, 1 }
        };
        ArrayList<String> ans1 = sol.ratInMaze(maze1);
        for (String s : ans1) {
            System.out.print(s + " ");
        }
        System.out.println();

        int[][] maze2 = {
                { 1, 0 },
                { 1, 0 }
        };

        ArrayList<String> ans2 = sol.ratInMaze(maze2);
        for (String s : ans2) {
            System.out.print(s + " ");
        }
        System.out.println();

        int[][] maze3 = {
                { 1, 1, 1 },
                { 1, 0, 1 },
                { 1, 1, 1 }
        };

        ArrayList<String> ans3 = sol.ratInMaze(maze3);
        for (String s : ans3) {
            System.out.print(s + " ");
        }
        System.out.println();
    }
}
