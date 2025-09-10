class Solution {
    static int inSequence(int A, int B, int C) {
        if (C == 0)
            return A == B ? 1 : 0;
        return ((B - A) % C == 0) && ((B - A) / C >= 0) ? 1 : 0;
    }
}

public class Twentyseven {
    public static void main(String[] args) {
        System.err.println(Solution.inSequence(1, 3, 2));
    }
}
