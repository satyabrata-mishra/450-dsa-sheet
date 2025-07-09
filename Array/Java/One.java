class Pair<K, V> {
    private final K key;
    private final V value;

    public Pair(K key, V value) {
        this.key = key;
        this.value = value;
    }

    public K getKey() {
        return key;
    }

    public V getValue() {
        return value;
    }
}

class Solution {
    public Pair<Integer, Integer> getMinMax(int[] arr) {
        int min = Integer.MAX_VALUE, max = Integer.MIN_VALUE;
        for (int i : arr) {
            min = Math.min(min, i);
            max = Math.max(max, i);
        }
        return new Pair(min, max);
    }
}

public class One {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int arr[] = { 3, 2, 1, 56, 10000, 167 };
        Pair<Integer, Integer> ans = sol.getMinMax(arr);
        System.out.println(ans.getKey() + " " + ans.getValue());
    }
}
