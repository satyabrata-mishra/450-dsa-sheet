import java.util.ArrayList;

class Solution {

    private static void dfs(int cRow, int row, String[][] list, ArrayList<ArrayList<String>> ans,
            ArrayList<String> sentence) {
        // Base case: one word chosen from each row
        if (cRow == row) {
            ans.add(new ArrayList<>(sentence)); // store a copy
            return;
        }

        // Try every word in the current row
        for (int cCol = 0; cCol < list[cRow].length; cCol++) {
            sentence.add(list[cRow][cCol]); // choose
            dfs(cRow + 1, row, list, ans, sentence); // explore next row
            sentence.remove(sentence.size() - 1); // backtrack
        }
    }

    public static ArrayList<ArrayList<String>> sentences(String[][] list) {
        int row = list.length;
        ArrayList<ArrayList<String>> ans = new ArrayList<>();
        ArrayList<String> sentence = new ArrayList<>();
        dfs(0, row, list, ans, sentence);
        return ans;
    }
}

public class Fourtytwo {
    public static void main(String[] args) {
        String[][] list = {
                { "you", "we" },
                { "have", "are" },
                { "sleep", "eat", "drink" }
        };

        ArrayList<ArrayList<String>> res = Solution.sentences(list);

        for (ArrayList<String> sentence : res) {
            for (String word : sentence) {
                System.out.print(word + " ");
            }
            System.out.println();
        }
    }
}
