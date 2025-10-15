import java.util.ArrayList;
import java.util.Collections;
import java.util.PriorityQueue;

class Solution {
    public ArrayList<Integer> kLargest(int[] arr, int k) {
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>();
        for (int i : arr) {
            maxHeap.add(i);
            if (maxHeap.size() > k) {
                maxHeap.poll();
            }
        }
        ArrayList<Integer> ans = new ArrayList<>();
        while (!maxHeap.isEmpty()) {
            ans.add(maxHeap.poll());
        }
        Collections.reverse(ans);
        return ans;
    }
}

public class Three {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.kLargest(new int[] { 1, 23, 12, 9, 30, 2, 50 }, 3));
    }
}
