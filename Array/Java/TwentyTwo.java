class Solution {
    int maxProduct(int[] arr) {
        int n = arr.length, maxProduct = arr[0], minProduct = arr[0], ans = arr[0];
        for (int i = 1; i < n; i++) {
            if (arr[i] < 0) {
                int temp = maxProduct;
                maxProduct = minProduct;
                minProduct = temp;
            }
            maxProduct = Math.max(arr[i], arr[i] * maxProduct);
            minProduct = Math.min(arr[i], arr[i] * minProduct);
            ans = Math.max(ans, maxProduct);
        }
        return ans;
    }
}

public class TwentyTwo {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.maxProduct(new int[] { -2, 6, -3, -10, 0, 2 }));
        System.out.println(sol.maxProduct(new int[] { -1, -3, -10, 0, 6 }));
        System.out.println(sol.maxProduct(new int[] { 2, 3, 4 }));
    }
}
