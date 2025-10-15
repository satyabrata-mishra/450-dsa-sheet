import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.PriorityQueue;

class Node {
    int row, col, elem;

    Node(int row, int col, int elem) {
        this.row = row;
        this.col = col;
        this.elem = elem;
    }
}

class Solution {
    public ArrayList<Integer> findSmallestRange(int[][] arr) {
        int row = arr.length, col = arr[0].length;
        PriorityQueue<Node> minHeap = new PriorityQueue<>((a, b) -> Integer.compare(a.elem, b.elem));
        int mini = Integer.MAX_VALUE, maxi = Integer.MIN_VALUE;
        for (int i = 0; i < row; i++) {
            mini = Math.min(mini, arr[i][0]);
            maxi = Math.max(maxi, arr[i][0]);
            minHeap.add(new Node(i, 0, arr[i][0]));
        }
        int start = mini, end = maxi;
        while (!minHeap.isEmpty()) {
            Node temp = minHeap.poll();
            mini = temp.elem;
            if (maxi - mini < end - start) {
                start = mini;
                end = maxi;
            }
            if (temp.col + 1 == col) {
                break;
            }
            maxi = Math.max(maxi, arr[temp.row][temp.col + 1]);
            minHeap.add(new Node(temp.row, temp.col + 1, arr[temp.row][temp.col + 1]));
        }
        return new ArrayList<>(Arrays.asList(start, end));
    }
}

public class Ten {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol
                .findSmallestRange(new int[][] { { 4, 7, 9, 12, 15 }, { 0, 8, 10, 14, 20 }, { 6, 12, 16, 30, 50 } }));
        System.out.println(
                sol.findSmallestRange(new int[][] { { 1, 3, 5, 7, 9 }, { 0, 2, 4, 6, 8 }, { 2, 3, 5, 7, 11 } }));
        System.out.println(sol.findSmallestRange(new int[][] { { 2, 4 }, { 1, 7 }, { 20, 40 } }));
    }
}
