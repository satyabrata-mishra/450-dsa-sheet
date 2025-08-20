class Solution {
    public int[] singleNum(int[] arr) {
        int xor_all = 0;
        for (int i : arr)
            xor_all ^= i;
        int rightMostSetBit = xor_all & -xor_all;
        int x = 0, y = 0;
        for (int i : arr)
            if ((i & rightMostSetBit) != 0)
                x ^= i;
            else
                y ^= i;
        if (x > y)
            return new int[] { y, x };
        return new int[] { x, y };
    }
}

public class One {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int arr[] = { 1, 2, 3, 2, 1, 4 };
        arr = sol.singleNum(arr);
    }
}
