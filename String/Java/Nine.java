
public class Nine {

    private static void printSubSequence(String str, String curr) {
        if (str.isEmpty()) {
            System.out.println(curr);
            return;
        }
        printSubSequence(str.substring(1), curr + str.charAt(0));
        printSubSequence(str.substring(1), curr);
    }

    public static void main(String[] args) {
        printSubSequence("abc", "");
    }
}
