// User function Template for Java
class Solution {
    public static int[] productExceptSelf(int arr[]) {
        int n = arr.length, mul = 1, cnt = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] != 0)
                mul = mul * arr[i];
            if (arr[i] == 0)
                cnt++;
        }
        int v[] = new int[n];
        for (int i = 0; i < n; i++) {
            if (cnt == 0) {
                v[i] = mul / arr[i];
            } else if (cnt == 1) {
                if (arr[i] != 0)
                    v[i] = 0;
                else
                    v[i] = mul;
            } else {
                v[i] = 0;
            }
        }
        return v;
    }
}

public class Fiveteen {
    public static void main(String[] args) {

    }
}
