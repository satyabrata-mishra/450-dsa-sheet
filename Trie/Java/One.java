class Solution {
    static class Node {
        Node[] link = new Node[26];
        int count = 0;
        boolean isLast = false;

        Node() {
            for (int i = 0; i < 26; i++)
                link[i] = null;
        }

        boolean containsKey(char ch) {
            return link[ch - 'a'] != null;
        }

        void setLink(char ch, Node node) {
            link[ch - 'a'] = node;
        }

        Node getLink(char ch) {
            return link[ch - 'a'];
        }

        void increaseCount() {
            count++;
        }

        int getCount() {
            return count;
        }

        void setisLast() {
            isLast = true;
        }

        boolean getisLast() {
            return isLast;
        }
    }

    static Node root;

    static void insert(String str) {
        Node dummy = root;
        for (char ch : str.toCharArray()) {
            if (!dummy.containsKey(ch)) {
                dummy.setLink(ch, new Node());
            }
            dummy = dummy.getLink(ch);
            dummy.increaseCount();
        }
        dummy.setisLast();
    }

    static String search(String str) {
        StringBuilder ans = new StringBuilder();
        Node dummy = root;

        for (char ch : str.toCharArray()) {
            ans.append(ch);
            dummy = dummy.getLink(ch);

            if (dummy.getCount() == 1) {
                return ans.toString();
            }
        }
        return ans.toString();
    }

    static String[] findPrefixes(String[] arr, int N) {
        root = new Node();

        for (int i = 0; i < N; i++) {
            insert(arr[i]);
        }

        String[] ans = new String[N];
        for (int i = 0; i < N; i++) {
            ans[i] = search(arr[i]);
        }
        return ans;
    }
}

public class One {
    public static void main(String[] args) {
        String[] arr1 = { "zebra", "dog", "duck", "dove" };
        int n1 = arr1.length;

        String[] ans1 = Solution.findPrefixes(arr1, n1);
        for (String s : ans1) {
            System.out.print(s + " ");
        }
        System.out.println();
        String[] arr2 = { "geeksgeeks", "geeksquiz", "geeksforgeeks" };
        int n2 = arr2.length;

        String[] ans2 = Solution.findPrefixes(arr2, n2);
        for (String s : ans2) {
            System.out.print(s + " ");
        }
        System.out.println();
    }
}
