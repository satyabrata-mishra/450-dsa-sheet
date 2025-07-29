import java.util.Arrays;
import java.util.Comparator;

class Solution {
    public String findLargest(int[] arr) {
        String strArr[] = new String[arr.length];
        for (int i = 0; i < arr.length; i++)
            strArr[i] = Integer.toString(arr[i]);
        Arrays.sort(strArr, new Comparator<String>() {
            @Override
            public int compare(String a, String b) {
                return (b + a).compareTo(a + b);
            }
        });
        StringBuilder ans = new StringBuilder();
        for (String i : strArr) {
            ans.append(i);
        }
        return ans.charAt(0) == '0' ? "0" : ans.toString();
    }
}

public class Form_the_Largest_Number {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.findLargest(new int[] { 3, 30, 34, 5, 9 }));// 9534330
        System.out.println(sol.findLargest(new int[] { 54, 546, 548, 60 }));// 6054854654
        System.out.println(sol.findLargest(new int[] { 3, 4, 6, 5, 9 }));// 96543
    }
}
