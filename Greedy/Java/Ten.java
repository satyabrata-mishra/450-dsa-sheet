import java.util.*;

class Solution {
    public int[][] minCashFlow(int[][] transaction, int n) {

        int[] net = new int[n];

        // Calculate net balance
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                net[i] -= transaction[i][j];
                net[j] += transaction[i][j];
            }
        }

        // MinHeap for debtors
        PriorityQueue<int[]> minHeap = new PriorityQueue<>(
                (a, b) -> Integer.compare(a[0], b[0]));

        // MaxHeap for creditors
        PriorityQueue<int[]> maxHeap = new PriorityQueue<>(
                (a, b) -> Integer.compare(b[0], a[0]));

        // Fill heaps
        for (int i = 0; i < n; i++) {
            if (net[i] > 0) {
                maxHeap.offer(new int[] { net[i], i });
            } else if (net[i] < 0) {
                minHeap.offer(new int[] { net[i], i });
            }
        }

        int[][] ans = new int[n][n];

        // Settle debts
        while (!minHeap.isEmpty() && !maxHeap.isEmpty()) {

            int[] debitor = minHeap.poll();
            int[] creditor = maxHeap.poll();

            int netflow = Math.min(creditor[0], -debitor[0]);

            ans[debitor[1]][creditor[1]] = netflow;

            debitor[0] += netflow;
            creditor[0] -= netflow;

            if (debitor[0] < 0) {
                minHeap.offer(debitor);
            }

            if (creditor[0] > 0) {
                maxHeap.offer(creditor);
            }
        }

        return ans;
    }
}

public class Ten {
    public static void printMatrix(int[][] arr) {
        for (int[] row : arr) {
            for (int val : row) {
                System.out.print(val + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {

        Solution sol = new Solution();

        int[][] arr1 = {
                { 0, 100, 0 },
                { 0, 0, 100 },
                { 100, 0, 0 }
        };

        int[][] result1 = sol.minCashFlow(arr1, arr1.length);
        printMatrix(result1);

        System.out.println();

        int[][] arr2 = {
                { 0, 100, 0 },
                { 0, 0, 200 },
                { 0, 0, 0 }
        };

        int[][] result2 = sol.minCashFlow(arr2, arr2.length);
        printMatrix(result2);
    }
}
