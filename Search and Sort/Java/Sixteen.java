import java.util.Arrays;

class Compute {
    static void sortBySetBitCount(Integer arr[], int n) {
        Arrays.sort(arr, (a, b) -> {
            return Integer.bitCount(b) - Integer.bitCount(a);
        });
    }
}

public class Sixteen {
    public static void main(String[] args) {
        Integer arr[] = new Integer[] { 5, 2, 3, 9, 4, 6, 7, 15, 32 };
        Compute.sortBySetBitCount(arr, arr.length);
        for (int i : arr)
            System.out.print(i + " ");
        System.out.println();
        arr = new Integer[] { 1, 2, 3, 4, 5, 6 };
        Compute.sortBySetBitCount(arr, arr.length);
        for (int i : arr)
            System.out.print(i + " ");
        System.out.println();
    }
}
