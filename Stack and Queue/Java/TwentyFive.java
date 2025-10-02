import java.util.LinkedHashMap;
import java.util.Map;

class LRUCache {
    private static LinkedHashMap<Integer, Integer> cache;
    private static int capacity;

    LRUCache(int cap) {
        cache = new LinkedHashMap<>();
        capacity = cap;
    }

    public static int get(int key) {
        if (!cache.containsKey(key))
            return -1;
        int val = cache.get(key);
        cache.remove(key);
        cache.put(key, val);
        return val;
    }

    public static void put(int key, int value) {
        if (cache.size() == capacity) {
            Map.Entry<Integer, Integer> firstEntry = cache.entrySet().iterator().next();
            cache.remove(firstEntry.getKey());
        }
        cache.put(key, value);
    }
}

public class TwentyFive {
    public static void main(String[] args) {
    }
}
