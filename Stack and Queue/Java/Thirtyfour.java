import java.util.ArrayDeque;
import java.util.ArrayList;

class Solution {
    public ArrayList<Integer> maxOfSubarrays(int[] arr, int k) {
        ArrayList<Integer> list = new ArrayList<>();
        ArrayDeque<Integer> Deque = new ArrayDeque<>();
        for (int i = 0; i < arr.length; i++) {
            if (!Deque.isEmpty() && Deque.getFirst() <= i - k) {
                Deque.removeFirst();
            }
            while (!Deque.isEmpty() && arr[Deque.getLast()] < arr[i]) {
                Deque.removeLast();
            }
            Deque.addLast(i);
            if (i >= k - 1) {
                list.add(arr[Deque.getFirst()]);
            }
        }
        return list;
    }
}

public class Thirtyfour {
    public static void main(String[] args) {

    }
}
