import java.util.Arrays;

class Solution {
    static int setSetBit(int x, int y, int l, int r) {
        char[] binX = new char[32];
        char[] binY = new char[32];
        Arrays.fill(binX, '0');
        Arrays.fill(binY, '0');
        int index = 31;
        String binXStr = Integer.toBinaryString(x), binYStr = Integer.toBinaryString(y);
        for (int i = binXStr.length() - 1; i >= 0; i--) {
            binX[index--] = binXStr.charAt(i);
        }
        index = 31;
        for (int i = binYStr.length() - 1; i >= 0; i--) {
            binY[index--] = binYStr.charAt(i);
        }
        for (int i = l; i <= r; i++) {
            if (binY[32 - i] == '1') {
                binX[32 - i] = '1';
            }
        }
        StringBuilder sb = new StringBuilder();
        for (char i : binX) {
            sb.append(i);
        }
        return Integer.parseInt(sb.toString(), 2);
    }
}

public class Six {
    public static void main(String[] args) {
        System.out.println(Solution.setSetBit(44, 3, 1, 5));
        System.out.println(Solution.setSetBit(16, 2, 1, 3));
        System.out.println(Solution.setSetBit(3, 9, 11, 27));
    }
}
