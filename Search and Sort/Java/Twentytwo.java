
class Solution {

    public int kthElement(int a[], int b[], int k) {
        int aInd = 0, bInd = 0, aSize = a.length, bSize = b.length;
        while (aInd < aSize && bInd < bSize) {
            if (a[aInd] < b[bInd]) {
                if (--k == 0) {
                    return a[aInd];
                }
                aInd++;
            } else {
                if (--k == 0) {
                    return b[bInd];
                }
                bInd++;
            }
        }
        while (aInd < aSize) {
            if (--k == 0) {
                return a[aInd];
            }
            aInd++;
        }
        while (bInd < bSize) {
            if (--k == 0) {
                return b[bInd];
            }
            bInd++;
        }
        return -1;
    }
}

public class Twentytwo {

    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.kthElement(new int[]{2, 3, 6, 7, 9}, new int[]{1, 4, 8, 10}, 5));
        System.out.println(sol.kthElement(new int[]{100, 112, 256, 349, 770}, new int[]{72, 86, 113, 119, 265, 445, 892}, 7));
    }
}
