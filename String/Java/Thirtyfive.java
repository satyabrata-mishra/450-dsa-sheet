import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.LinkedHashMap;

class Solution {
    public HashMap<Character, Integer> freqCalculator(String s) {
        HashMap<Character, Integer> map = new HashMap<>();
        for (char i : s.toCharArray()) {
            map.put(i, map.getOrDefault(i, 0) + 1);
        }
        return map;
    }

    public ArrayList<ArrayList<String>> anagrams(String[] arr) {
        HashMap<HashMap<Character, Integer>, ArrayList<String>> tracker = new LinkedHashMap<>();
        for (String i : arr) {
            HashMap<Character, Integer> freq = freqCalculator(i);
            if (!tracker.containsKey(freq)) {
                tracker.put(freq, new ArrayList<>());
            }
            tracker.get(freq).add(i);
        }
        ArrayList<ArrayList<String>> ans = new ArrayList<>();
        for (HashMap<Character, Integer> i : tracker.keySet()) {
            ans.add(tracker.get(i));
        }
        Collections.sort(ans, (ArrayList<String> a, ArrayList<String> b) -> a.get(0).compareTo(b.get(0)));
        return ans;
    }
}

public class Thirtyfive {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.anagrams(new String[] { "act", "god", "cat", "dog", "tac" }));
        System.out.println(sol.anagrams(new String[] { "no", "on", "is" }));
        System.out.println(
                sol.anagrams(new String[] { "listen", "silent", "enlist", "abc", "cab", "bac", "rat", "tar", "art" }));
    }
}
