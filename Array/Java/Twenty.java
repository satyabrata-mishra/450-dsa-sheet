import java.util.HashSet;

class Solution {
    static boolean findsum(int arr[]) {
        HashSet<Integer> set = new HashSet<>();
        set.add(0);
        int sum = 0;
        for (int i : arr) {
            sum += i;
            if (set.contains(sum))
                return true;
            else
                set.add(sum);
        }
        return false;
    }
}

public class Twenty {
    public static void main(String[] args) {

    }
}
