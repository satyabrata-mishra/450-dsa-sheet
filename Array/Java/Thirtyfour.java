class Solution {
    private int helperMediam(int a[], int b[], boolean toogle) {
        int n = a.length;
        int low = Math.min(a[0], b[0]), high = Math.max(a[n - 1], b[n - 1]);
        while (low < high) {
            int mid = low + (high - low) / 2;
            int count = 0;
            for (int i : a) {
                if (i <= mid)
                    count++;
                else
                    break;
            }
            for (int i : b) {
                if (i <= mid)
                    count++;
                else
                    break;
            }
            if (toogle && count < n) {
                low = mid + 1;
            } else if (!toogle && count <= n) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }

    public double medianOf2(int a[], int b[]) {
        return ((double) helperMediam(a, b, true) + helperMediam(a, b, false)) / 2;
    }
}

public class Thirtyfour {
    public static void main(String[] args) {
        int a[] = { -5, 3, 6, 12, 15 }, b[] = { -12, -10, -6, -3, 4 };
        Solution sol = new Solution();
        System.out.println(sol.medianOf2(a, b));
    }
}
