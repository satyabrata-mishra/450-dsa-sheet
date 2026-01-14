import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

class Pair {
    String word;
    int level;

    Pair(String word, int level) {
        this.word = word;
        this.level = level;
    }
}

class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        Queue<Pair> queue = new LinkedList<>();
        queue.offer(new Pair(beginWord, 1));

        HashSet<String> wordSet = new HashSet<>(wordList);
        wordSet.remove(beginWord);

        while (!queue.isEmpty()) {
            Pair curr = queue.poll();

            if (curr.word.equals(endWord)) {
                return curr.level;
            }

            char[] chars = curr.word.toCharArray();

            for (int i = 0; i < chars.length; i++) {
                char original = chars[i];

                for (char c = 'a'; c <= 'z'; c++) {
                    chars[i] = c;
                    String nextWord = new String(chars);

                    if (wordSet.contains(nextWord)) {
                        wordSet.remove(nextWord);
                        queue.offer(new Pair(nextWord, curr.level + 1));
                    }
                }

                chars[i] = original;
            }
        }
        return 0;
    }
}

public class Eleven {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.ladderLength("hit", "cog",
                new ArrayList<>(Arrays.asList("hot", "dot", "dog", "lot", "log", "cog"))));// 5
        System.out.println(
                sol.ladderLength("hit", "cog", new ArrayList<>(Arrays.asList("hot", "dot", "dog", "lot", "log"))));// 0
        System.out.println(sol.ladderLength("ymain", "oecij",
                new ArrayList<>(Arrays.asList("ymann", "yycrj", "oecij", "ymcnj", "yzcrj", "yycij", "xecij", "yecij",
                        "ymanj", "yzcnj", "ymain"))));// 10
    }
}
