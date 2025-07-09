
import java.util.HashSet;

class Solution {

    static int distinct(int M[][], int N) {
        HashSet<Integer> first = new HashSet<>();
        for (int i : M[0]) {
            first.add(i);
        }
        for (int i = 1; i < N; i++) {
            HashSet<Integer> second = new HashSet<>();
            for (int j = 0; j < N; j++) {
                second.add(M[i][j]);
            }
            first.retainAll(second);
        }
        return first.size();
    }
}

public class Nine {

    public static void main(String[] args) {
        int arr[][] = {{12, 1, 14, 3, 16},
        {14, 2, 1, 3, 35},
        {14, 1, 14, 3, 11},
        {14, 5, 3, 2, 1},
        {1, 18, 3, 21, 14}};
        System.out.println(Solution.distinct(arr, arr.length));
    }
}
