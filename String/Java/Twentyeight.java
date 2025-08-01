import java.util.HashMap;

public class Twentyeight {
    public static String firstRepeatedWord(String s) {
        HashMap<String, Integer> map = new HashMap<>();
        for (String i : s.split(" ")) {
            map.put(i, map.getOrDefault(i, 0) + 1);
            if (map.get(i) > 1) {
                return i;
            }
        }
        return "";
    }

    public static void main(String[] args) {
        System.out.println(firstRepeatedWord("Ravi had been saying that he had been there"));
        System.out.println(firstRepeatedWord("Ravi had been saying that"));
        System.out.println(firstRepeatedWord("he had had he"));
    }
}
