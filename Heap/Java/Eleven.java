import java.util.ArrayList;
import java.util.LinkedList;
import java.util.PriorityQueue;

class Solution {
    public ArrayList<Double> getMedian(int[] arr) {
        PriorityQueue<Integer> minHeap = new PriorityQueue();
        PriorityQueue<Integer> maxHeap = new PriorityQueue(Collections.reverseOrder());
        ArrayList<Double> ans = new ArrayList<>();
        for (int i : arr) {
            maxHeap.add(i);
            minHeap.add(maxHeap.poll());
            if (minHeap.size() > maxHeap.size()) {
                maxHeap.add(minHeap.poll());
            }
            if (minHeap.size() == maxHeap.size()) {
                ans.add(((double) minHeap.peek() + maxHeap.peek()) / 2);
            } else {
                ans.add((double) maxHeap.peek());
            }
        }
        return ans;
    }
}

public class Eleven {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.getMedian(new int[] { 5, 15, 1, 3, 2, 8 }));
        System.out.println(sol.getMedian(new int[] { 2, 2, 2, 2 }));
    }
}
