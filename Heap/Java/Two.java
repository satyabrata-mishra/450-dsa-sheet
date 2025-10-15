import java.util.ArrayList;
import java.util.PriorityQueue;

class Pair {
    int num, index;

    Pair(int num, int index) {
        this.num = num;
        this.index = index;
    }
}

class Solution {
    public ArrayList<Integer> maxOfSubarrays(int[] arr, int k) {
        PriorityQueue<Pair> maxHeap = new PriorityQueue<>((Pair a, Pair b) -> b.num - a.num);
        int n = arr.length;
        ArrayList<Integer> ans = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            maxHeap.add(new Pair(arr[i], i));
            while (!maxHeap.isEmpty() && maxHeap.peek().index <= i - k) {
                maxHeap.poll();
            }
            if (i >= k - 1) {
                ans.add(maxHeap.peek().num);
            }
        }
        return ans;
    }
}

public class Two {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.maxOfSubarrays(new int[] { 1, 2, 3, 1, 4, 5, 2, 3, 6 }, 3));
        System.out.println(sol.maxOfSubarrays(new int[] { 5, 1, 3, 4, 2 }, 3));
    }
}
