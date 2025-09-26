import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

class Solution {
    static List<Integer> firstNegInt(int arr[], int k) {
        ArrayList<Integer> ans = new ArrayList<>();
        Queue<Integer> q = new LinkedList<>();
        int n = arr.length;
        for (int i = 0; i < n; i++) {
            if (arr[i] < 0)
                q.add(i);
            if (i >= k - 1) {
                while (!q.isEmpty() && q.peek() < i - k + 1)
                    q.poll();
                if (!q.isEmpty())
                    ans.add(arr[q.peek()]);
                else
                    ans.add(0);
            }
        }
        return ans;
    }
}

public class Thirtytwo {

}
