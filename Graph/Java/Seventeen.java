import java.util.*;

class Solution {

    private boolean dfs(char src, Map<Character, List<Character>> adj, Map<Character, Integer> visited,
            StringBuilder ans) {
        visited.put(src, 1); // visiting

        for (char nei : adj.getOrDefault(src, Collections.emptyList())) {
            if (visited.get(nei) == 1) {
                return false; // cycle detected
            }
            if (visited.get(nei) == 0) {
                if (!dfs(nei, adj, visited, ans)) {
                    return false;
                }
            }
        }

        visited.put(src, 2); // visited
        ans.append(src);
        return true;
    }

    public String findOrder(String[] words) {
        Map<Character, List<Character>> adjacencyList = new HashMap<>();
        Map<Character, Integer> visited = new HashMap<>();
        Set<Character> chars = new HashSet<>();
        for (String w : words) {
            for (char c : w.toCharArray()) {
                chars.add(c);
            }
        }
        for (int i = 0; i < words.length - 1; i++) {
            String s1 = words[i];
            String s2 = words[i + 1];
            int len = Math.min(s1.length(), s2.length());
            int ind = 0;
            while (ind < len && s1.charAt(ind) == s2.charAt(ind)) {
                ind++;
            }
            if (ind == len && s1.length() > s2.length()) {
                return "";
            }
            if (ind < len) {
                char u = s1.charAt(ind);
                char v = s2.charAt(ind);
                adjacencyList.computeIfAbsent(u, k -> new ArrayList<>()).add(v);
            }
        }
        for (char c : chars) {
            visited.put(c, 0);
        }

        StringBuilder ans = new StringBuilder();
        for (char c : chars) {
            if (visited.get(c) == 0) {
                if (!dfs(c, adjacencyList, visited, ans)) {
                    return "";
                }
            }
        }

        return ans.reverse().toString();
    }
}

public class Seventeen {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.findOrder(new String[] { "baa", "abcd", "abca", "cab", "cad" })); // bdac
        System.out.println(sol.findOrder(new String[] { "caa", "aaa", "aab" })); // cab
        System.out.println(sol.findOrder(new String[] { "ab", "cd", "ef", "ad" })); // ""
        System.out.println(sol.findOrder(new String[] { "dddc", "a", "ad", "ab", "b", "be", "cd", "cded" })); // edabc
    }
}
