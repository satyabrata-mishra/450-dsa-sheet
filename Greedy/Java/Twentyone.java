// User function Template for Java

import java.util.Iterator;
import java.util.LinkedHashSet;

class Solution {
    static int pageFaults(int n, int c, int pages[]) {
        LinkedHashSet<Integer> set = new LinkedHashSet<>();
        int pagefaults = 0;
        for (int page : pages) {
            if (set.contains(page)) {
                set.remove(page);
                set.add(page);
            } else {
                ++pagefaults;
                if (set.size() == c) {
                    Iterator<Integer> it = set.iterator();
                    it.next();
                    it.remove();
                }
                set.add(page);
            }
        }
        return pagefaults;
    }
}

public class Twentyone {
    public static void main(String[] args) {
        System.out.println(Solution.pageFaults(9, 4, new int[] { 5, 0, 1, 3, 2, 4, 1, 0, 5 }));
    }
}
