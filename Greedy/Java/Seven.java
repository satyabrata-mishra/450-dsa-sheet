import java.util.Arrays;

class Solution {
    public int minPlatform(int arr[], int dep[]) {
        Arrays.sort(arr);
        Arrays.sort(dep);
        int i = 1, j = 0, minPlatform = 1, platforms = 1, n = arr.length;
        while (i < n && j < n) {
            if (arr[i] <= dep[j]) {
                ++platforms;
                ++i;
            } else {
                --platforms;
                ++j;
            }
            minPlatform = Math.max(minPlatform, platforms);
        }
        return minPlatform;
    }
}

public class Seven {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.minPlatform(new int[] { 900, 940, 950, 1100, 1500, 1800 },
                new int[] { 910, 1200, 1120, 1130, 1900, 2000 }));
        System.out.println(sol.minPlatform(new int[] { 900, 1235, 1100 }, new int[] { 1000, 1240, 1200 }));
        System.out.println(sol.minPlatform(new int[] { 1000, 935, 1100 }, new int[] { 1200, 1240, 1130 }));
        System.out.println(
                sol.minPlatform(new int[] { 1114, 825, 357, 1415, 54 }, new int[] { 1740, 1110, 2238, 1535, 2323 }));
    }
}
